#include "Message_Question.h"
#include "ui_Message_Question.h"

Message_Question::Message_Question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message_Question)
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

Message_Question::~Message_Question()
{
    delete ui;
}

//设置弹窗内容
void Message_Question::setMessage(QString info)
{
    ui->label_info->setText(info);
}

//确认按钮
void Message_Question::on_pushButton_confirm_clicked()
{
    this->accept();
}

//取消按钮
void Message_Question::on_pushButton_cancel_clicked()
{
    this->reject();
}

//关闭弹窗
void Message_Question::on_btnMenu_Close_clicked()
{
    this->reject();
}
