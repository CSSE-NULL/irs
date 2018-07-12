#include "Client_Window.h"
#include "ui_Client_Window.h"

Client_Window::Client_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client_Window)
{
    ui->setupUi(this);

    //canMove参数用来实现窗体拖动
    this->setProperty("canMove", true);

    //设置属性，用来加载qss
    this->setProperty("form","window");
    ui->widgetTitle->setProperty("form", "title");

    //设置窗体属性
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
}

Client_Window::~Client_Window()
{
    delete ui;
}

void Client_Window::on_pushButton_scanner_clicked()
{
    QString temp = QDir::toNativeSeparators(QFileDialog::getOpenFileName(this,tr("choose irisdata"),QDir::currentPath()));
    ui->lineEdit_scanner->setText(temp);
}

void Client_Window::on_pushButton_exit_clicked()
{
    exit(0);
}

void Client_Window::on_pushButton_submit_clicked()
{
    //初始化socket
    socket = new QTcpSocket;
    connect(socket,SIGNAL(readyRead()),this,SLOT(slotReadData()));
    socket->connectToHost(QHostAddress::LocalHost,8080);

    //连接数据库
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/irs.db");
    if(db.open()){
        //获取虹膜图片路径字符串
        QString device_id = ui->lineEdit_device_id->text();
        QString Qpath = ui->lineEdit_scanner->text();
        std::string  spath = Qpath.toStdString();
        int i;char path[1000];
        for(i=0;i<spath.length();i++) path[i]=spath[i];
        path[i]='\0';

        //进行识别
        OsiManager::Result iris = scan(path);
        int flag=0;
        QSqlQuery query;
        query.exec("select irisdata,mask,user_id,user_authority from user");
        while(query.next())
        {
            QString  Qirisdata = query.value(0).toString();
            std::string  Sirisdata = Qirisdata.toStdString();
            const char* irisdata = Sirisdata.c_str();
            int longNDB[2 * LEN][2];
            GetBinaryArray(irisdata, longNDB);//获取统计信息

            QString  Qmask = query.value(1).toString();
            std::string  Smask = Qmask.toStdString();
            const char* mask = Smask.c_str();
            QString user_id = query.value(2).toString();
            QString user_authority = query.value(3).toString();

            if(Recognition(iris,longNDB,mask))
            {
                QSqlQuery query_device_authority;
                query_device_authority.exec("select device_authority from device where device_id = '" + device_id + "';");
                query_device_authority.first();
                QString device_authority = query_device_authority.value(0).toString();
                if(transform(user_authority) <= transform(device_authority))
                {
                    flag=1;
                    QTextStream in(socket);
                    in<<user_id<<","<<device_id;
                    Message_Correct msg;
                    msg.setMessage("成功");
                    msg.exec();
                    break;
                }
            }
        }
        if(!flag) {
            Message_Error msg;
            msg.setMessage("失败");
            msg.exec();
        }

    }else{
        Message_Error msg;
        msg.setMessage("数据库连接失败，请检查网络！！！");
        msg.exec();
    }

}

int Client_Window::transform(QString QString_authority)
{
    if(QString_authority == "Level_1")
    {
        return 1;
    }else if(QString_authority == "Level_2")
    {
        return 2;
    }
    else if(QString_authority == "Level_3"){
        return 3;
    }else{
        //当没有对应设备时
        return 0;
    }
}


void Client_Window::slotReadData()
{
        socket->close();
}

//最小化按钮
void Client_Window::on_btnMenu_Min_clicked()
{
    showMinimized();
}

//关闭窗体按钮
void Client_Window::on_btnMenu_Close_clicked()
{
    exit(0);
}
