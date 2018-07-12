#include "Tab_Device.h"
#include "ui_Tab_Device.h"

Tab_Device::Tab_Device(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab_Device)
{
    ui->setupUi(this);

    //初始化表� �
    set_table_device();

    //连接实时查询lineedit的槽函数
    connect(ui->lineEdit_device_id, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_device_name, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->comboBox_device_authority, SIGNAL(currentTextChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_position, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_device_register_time, SIGNAL(textChanged(QString)), this, SLOT(filter()));
}

Tab_Device::~Tab_Device()
{
    delete ui;
}

void Tab_Device::set_table_device()
{
    QSqlQueryModel *model = Mysql_Operation().initialize("device");

    ui->table_device->setModel(model);
}

void Tab_Device::on_pushButton_add_clicked()
{
    Dialog_Device_Add dialog_device_add;
    if (dialog_device_add.exec() == QDialog::Accepted) {
        //从dialog中接收数据并� 给value
        QStringList value;
        value << dialog_device_add.get_device_name();
        value << dialog_device_add.get_device_authority();
        value << dialog_device_add.get_position();
        value << QDateTime::currentDateTime().toString("yyyy/M/d hh:mm");

        //构� column,和value一起进行数据库操作
        QStringList column;
        column << "device_name";
        column << "device_authority";
        column << "position";
        column << "device_register_time";

        if (Mysql_Operation().insert("device", value, column)) {
           set_table_device();
        }
    }
}

void Tab_Device::on_pushButton_delete_clicked()
{
    //判断是否选中行
    int row = ui->table_device->currentIndex().row();

    //row等于-1时未选中，弹窗提醒
    if (row == -1) {
        Message_Error msg;
        msg.setMessage("请选择需要� 除的设备");
        msg.exec();
    } else {
        Message_Question msg;
        msg.setMessage("确定要� 除该用户吗？");
        if (msg.exec() == QDialog::Accepted) {
            //获取当前选中行的信息的id值
            QModelIndex index = ui->table_device->model()->index(row,0);
            QString device_id = ui->table_device->model()->data(index).toString();

            if (Mysql_Operation().Delete("device", device_id)) {
               set_table_device();
            }
        }
    }
}

void Tab_Device::on_pushButton_change_clicked()
{
    //判断是否选中行
    int row = ui->table_device->currentIndex().row();

    //row等于-1时未选中，弹窗提醒
    if (row == -1) {
        Message_Error msg;
        msg.setMessage("请选择需要修改的设备");
        msg.exec();
    } else {
        //获取当前选中行的信息的id值
        QModelIndex index = ui->table_device->model()->index(row,0);
        QString device_id = ui->table_device->model()->data(index).toString();

        Dialog_Device_Change dialog_device_change;
        if (dialog_device_change.exec() == QDialog::Accepted) {
            //从dialog中接收数据并� 给value
            QStringList value;
            value << dialog_device_change.get_device_name();
            value << dialog_device_change.get_device_authority();
            value << dialog_device_change.get_position();

            //构� column,和value一起进行数据库操作
            QStringList column;
            column << "device_name";
            column << "device_authority";
            column << "position";

            if (Mysql_Operation().update("device", device_id, value, column)) {
                set_table_device();
            }
        }
    }
}

void Tab_Device::filter()
{
    //从实时显示lineedit中获取数据，初始化value和column，进行数据库操作
    QStringList column;
    QStringList value;
    if (ui->lineEdit_device_id->text() != "") {
        value << ui->lineEdit_device_id->text();
        column << "device_id";
    }
    if (ui->lineEdit_device_name->text() != "") {
        value << ui->lineEdit_device_name->text();
        column << "device_name";
    }
    if (ui->comboBox_device_authority->currentText() != "None") {
        value << ui->comboBox_device_authority->currentText();
        column << "device_authority";
    }
    if (ui->lineEdit_position->text() != "") {
        value << ui->lineEdit_position->text();
        column << "position";
    }
    if (ui->lineEdit_device_register_time->text() != "") {
        value << ui->lineEdit_device_register_time->text();
        column << "device_register_time";
    }

    QSqlQueryModel *model = Mysql_Operation().filter("device", value, column);

    ui->table_device->setModel(model);
}


