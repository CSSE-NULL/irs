#include "Tab_Record.h"
#include "ui_Tab_Record.h"

#include <QDebug>

Tab_Record::Tab_Record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab_Record)
{
    ui->setupUi(this);

    //初始化表格
    set_table_record();

    //连接实时查询lineedit的槽函数
    connect(ui->lineEdit_record_id, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_user_id, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_device_id, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->lineEdit_record_register_time, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    connect(ui->comboBox_result, SIGNAL(currentTextChanged(QString)), this, SLOT(filter()));

}

Tab_Record::~Tab_Record()
{
    delete ui;
}

void Tab_Record::set_table_record()
{
    QSqlQueryModel *model = Mysql_Operation().initialize("record");
    ui->table_record->setModel(model);
}

void Tab_Record::add(QString device_id, QDateTime time, QString result, QString user_id)
{
    //获取server传递过来的数据
    QStringList value;
    value << user_id;
    value << device_id;
    value << time.toString("yyyy/M/d hh:mm");
    value << result;

    //构建column，和value一起进行数据库操作
    QStringList column;
    column << "user_id";
    column << "device_id";
    column << "record_register_time";
    column << "result";

    if (Mysql_Operation().insert("record", value, column)) {
        set_table_record();
    }
}

void Tab_Record::add(QString device_id, QDateTime time, QString result)
{
    //获取server传递过来的数据
    QStringList value;
    value << device_id;
    value << time.toString("yyyy/M/d hh:mm");
    value << result;

    //构建column，和value一起进行数据库操作
    QStringList column;
    column << "device_id";
    column << "record_register_time";
    column << "result";

    if (Mysql_Operation().insert("record", value, column)) {
        set_table_record();
    }
}

void Tab_Record::filter()
{
    //从实时显示lineedit中获取数据，并构建column，和value一起进行数据库操作
    QStringList column;
    QStringList value;
    if (ui->lineEdit_record_id->text() != "") {
        value << ui->lineEdit_record_id->text();
        column << "record_id";
    }
    if (ui->lineEdit_user_id->text() != "") {
        value << ui->lineEdit_user_id->text();
        column << "user_id";
    }
    if (ui->lineEdit_device_id->text() != "") {
        value << ui->lineEdit_device_id->text();
        column << "device_id";
    }
    if (ui->lineEdit_record_register_time->text() != "") {
        value << ui->lineEdit_record_register_time->text();
        column << "record_register_time";
    }
    if (ui->comboBox_result->currentText() != "None") {
        value << ui->comboBox_result->currentText();
        column << "result";
    }

    QSqlQueryModel *model = Mysql_Operation().filter("record", value, column);

    ui->table_record->setModel(model);

}
