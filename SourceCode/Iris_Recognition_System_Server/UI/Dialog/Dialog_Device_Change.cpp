#include "Dialog_Device_Change.h"
#include "ui_Dialog_Device_Change.h"

Dialog_Device_Change::Dialog_Device_Change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Device_Change)
{
    ui->setupUi(this);

    //canMove参数用来实现窗体拖动
    this->setProperty("canMove", true);

    //设置属性，用来加载qss
    this->setProperty("form","window");
    ui->widgetTitle->setProperty("form", "title");

    //max记录当前是否最大化
    this->max = false;

    //location记录最大化前窗体的位置
    this->location = this->geometry();

    //设置窗体属性
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
}

Dialog_Device_Change::~Dialog_Device_Change()
{
    delete ui;
}

QString Dialog_Device_Change::get_device_name()
{
    return device_name;
}

QString Dialog_Device_Change::get_position()
{
    return position;
}

QString Dialog_Device_Change::get_device_authority()
{
    return device_authority;
}

void Dialog_Device_Change::on_pushButton_confirm_2_clicked()
{
    device_name = ui->lineEdit_device_name->text();
    device_authority = ui->comboBox_device_authority->currentText();
    position = ui->lineEdit_position->text();

    if (device_name == "" || device_name.size() > 10 || position == "" || position.size() > 20) {
        Message_Error msg;
        msg.setMessage("输入错误");
        msg.exec();
    } else {
        Message_Question msg;
        msg.setMessage("确定要修改设备吗？");
        if (msg.exec() == QDialog::Accepted) {
            this->accept();
        } else {
            this->reject();
        }
    }
}

void Dialog_Device_Change::on_pushButton_cancel_2_clicked()
{
    this->reject();
}

//最小化按钮
void Dialog_Device_Change::on_btnMenu_Min_clicked()
{
    showMinimized();
}

//最大化和还原按钮
void Dialog_Device_Change::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        this->setProperty("canMove", true);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        this->setProperty("canMove", false);
    }

    max = !max;
}

//关闭窗体按钮
void Dialog_Device_Change::on_btnMenu_Close_clicked()
{
    this->close();
}


