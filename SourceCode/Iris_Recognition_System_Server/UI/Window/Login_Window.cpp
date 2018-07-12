#include "Login_Window.h"
#include "ui_Login_Window.h"

Login_Window::Login_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_Window)
{
    ui->setupUi(this);

    //设置窗体属性
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    //canMove参数用来实现窗体拖动
    this->setProperty("canMove", true);
}

Login_Window::~Login_Window()
{
    delete ui;
}

void Login_Window::on_pushButton_exit_clicked()
{
    exit(0);
}

void Login_Window::on_pushButton_login_clicked()
{
    QString admin_name = ui->lineEdit_admin_name->text();
    QString admin_password = ui->lineEdit_admin_password->text();
    if (Mysql_Operation().login(admin_name,admin_password)) {
        this->accept();
    } else {
        Message_Error msg;
        msg.setMessage("用户名或密码错误");
        msg.exec();
    }
}
