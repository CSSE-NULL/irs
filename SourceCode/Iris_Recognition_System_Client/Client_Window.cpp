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
    socket = new QTcpSocket;
    connect(socket,SIGNAL(readyRead()),this,SLOT(slotReadData()));
    socket->connectToHost(QHostAddress::LocalHost,8080);

    //获取虹膜图片路径字符串
    QString device_id = ui->lineEdit_device_id->text();
    QString Qpath = ui->lineEdit_scanner->text();
    std::string  spath = Qpath.toStdString();
    int i;char path[1000];
    for(i=0;i<spath.length();i++) path[i]=spath[i];
    path[i]='\0';
    //将QString转换成IRIS结构体
    OsiManager::Result iris = scan(path);
    QByteArray block; //用于暂存我们要发送的数据
    QDataStream out(&block,QIODevice::WriteOnly);
    //使用数据流写入数据
    out<<(quint16)0;
    char msg[50000];
    memset(msg,0,50000);
    char* irisdata = Transfer(iris);
    strcat(msg,irisdata);
    strcat(msg,",");
    strcat(msg,iris.mask);
    strcat(msg,",");

    for(int i=0;i<STN;i++){
        strcat(msg,iris.shift_code[i]);
        strcat(msg,",");
    }
    strcat(msg,device_id.toStdString().c_str());
    out<<msg;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    //我们获取已经建立的连接的子套接字
    socket->write(block);
}

void Client_Window::slotReadData()
{
    if (socket->bytesAvailable()>0) {
        QString result;
        QByteArray ba;
        ba.resize(socket->bytesAvailable());
        socket->read(ba.data(),ba.size());
        result = QString(ba);

        if (result == "true") {
            Message_Correct msg;
            msg.setMessage("成功");
            msg.exec();
        } else if (result == "false") {
            Message_Error msg;
            msg.setMessage("失败");
            msg.exec();
        }
        socket->close();
    }
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
