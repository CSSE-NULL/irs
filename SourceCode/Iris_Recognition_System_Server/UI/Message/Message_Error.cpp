#include "Message_Error.h"
#include "ui_Message_Error.h"

Message_Error::Message_Error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message_Error)
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

Message_Error::~Message_Error()
{
    delete ui;
}

void Message_Error::setMessage(QString info)
{
    ui->label_info->setText(info);
}

void Message_Error::on_btnMenu_Close_clicked()
{
    this->reject();
}

void Message_Error::on_pushButton_confirm_clicked()
{
    this->accept();
}
