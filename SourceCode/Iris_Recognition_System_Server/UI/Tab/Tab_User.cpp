#include "Tab_User.h"
#include "ui_Tab_User.h"

Tab_User::Tab_User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab_User)
{
    ui->setupUi(this);

    //初始化表格
    set_table_user();

    //连接实时查询lineedit的槽函数
    connect(ui->lineEdit_user_id, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_user_name, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->comboBox_user_authority, SIGNAL(currentTextChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_user_register_time, SIGNAL(textChanged(QString)), this, SLOT(filter()));
}

Tab_User::~Tab_User()
{
    delete ui;
}

void Tab_User::set_table_user()
{
    QSqlQueryModel *model = Mysql_Operation().initialize("user");

    ui->table_user->setModel(model);
}

void Tab_User::on_pushButton_delete_clicked()
{
    //判断是否选中行
    int row = ui->table_user->currentIndex().row();

    //row等于-1时未选中，弹窗提醒
    if (row == -1) {
        Message_Error msg;
        msg.setMessage("请选择需要删除的用户");
        msg.exec();
    } else {
        Message_Question msg;
        msg.setMessage("确定要删除该用户吗？");
        if (msg.exec() == QDialog::Accepted) {

            //获取当前选中行的信息的id值
            QModelIndex index = ui->table_user->model()->index(row,0);
            QString user_id = ui->table_user->model()->data(index).toString();

            if (Mysql_Operation().Delete("user", user_id)) {
                set_table_user();
            }
        }
    }
}

void Tab_User::on_pushButton_add_clicked()
{
    Dialog_User_Add dialog_user_add;
    if(dialog_user_add.exec() == QDialog::Accepted)
    {
    //从dialog获取数据
    QStringList value;
    value << dialog_user_add.get_user_name();
    value << dialog_user_add.get_user_authority();

 //************************************************************************************************************
    //获取虹膜图片路径字符串
    QString Qpath = dialog_user_add.get_iris();
    std::string  spath = Qpath.toStdString().c_str();
    int i;char path[100];
    for(i=0;i<spath.length();i++) path[i]=spath[i];
    path[i]='\0';
    //将QString转换成IRIS结构体
    OsiManager::Result temp = scan(path);
    //将temp加密为irisdata字符串
    char* irisdata = Transfer(temp.code);
    value << irisdata;
    value << temp.mask;
    value << QDateTime::currentDateTime().toString("yyyy/M/d hh:mm");

    //构造column,和value一起进行数据库操作
    QStringList column;
    column << "user_name";
    column << "user_authority";
    column << "irisdata";
    column << "mask";
    column << "user_register_time";

        if(Mysql_Operation().insert("user", value, column))
        {
            set_table_user();
        }
    }
}

void Tab_User::on_pushButton_change_clicked()
{
    //判断是否选中行
    int row = ui->table_user->currentIndex().row();

    //row等于-1时未选中，弹窗提醒
    if(row == -1){
        Message_Error msg;
        msg.setMessage("请选择需要删除的设备");
        msg.exec();
    }else{
        //获取当前选中行的信息的id值
        QModelIndex index = ui->table_user->model()->index(row,0);
        QString user_id = ui->table_user->model()->data(index).toString();

        //进入dialog，获取新数据
        Dialog_User_Change dialog_user_change;
        if(dialog_user_change.exec() == QDialog::Accepted)
        {

            QStringList value;
            value << dialog_user_change.get_user_name();
            value << dialog_user_change.get_user_authority();

         //************************************************************************************************************
         //Transfer dialog_user_add.get_iris() 并且放在value中,先放irisdata，再放mask，顺序一定要对
            QString Qpath = dialog_user_change.get_iris();
            std::string  spath = Qpath.toStdString().c_str();
            int i;char path[100];
            for(i=0;i<spath.length();i++) path[i]=spath[i];
            path[i]='\0';
            //将QString转换成IRIS结构体
            OsiManager::Result temp = scan(path);
            //将temp加密为irisdata字符串
            char* irisdata = Transfer(temp.code);
            value << irisdata;
            value << temp.mask;

            //构造column,和value一起进行数据库操作
            QStringList column;
            column << "user_name";
            column << "user_authority";
            column << "irisdata";
            column << "mask";

            if(Mysql_Operation().update("user", user_id, value, column))
            {
                set_table_user();
            }
        }
    }
}

void Tab_User::filter()
{
    //从实时显示lineedit中获取数据，并构建column，和value一起进行数据库操作
    QStringList column;
    QStringList value;
    if (ui->lineEdit_user_id->text() != "") {
        value << ui->lineEdit_user_id->text();
        column << "user_id";
    }
    if (ui->lineEdit_user_name->text() != "") {
        value << ui->lineEdit_user_name->text();
        column << "user_name";
    }
    if (ui->comboBox_user_authority->currentText() != "None") {
        value << ui->comboBox_user_authority->currentText();
        column << "user_authority";
    }
    if (ui->lineEdit_user_register_time->text() != "") {
        value << ui->lineEdit_user_register_time->text();
        column << "user_register_time";
    }

    QSqlQueryModel *model = Mysql_Operation().filter("user", value, column);

    ui->table_user->setModel(model);
}





