#include "Dialog_User_Add.h"
#include "ui_Dialog_User_Add.h"

Dialog_User_Add::Dialog_User_Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_User_Add)
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

Dialog_User_Add::~Dialog_User_Add()
{
    delete ui;
}

QString Dialog_User_Add::get_user_name()
{
    return user_name;
}

QString Dialog_User_Add::get_iris()
{
    return iris;
}

QString Dialog_User_Add::get_user_authority()
{
    return user_authority;
}

void Dialog_User_Add::on_pushButton_choose_clicked()
{
    QString temp = QDir::toNativeSeparators(QFileDialog::getOpenFileName(this,tr("choose irisdata"),QDir::currentPath()));
    ui->lineEdit_iris->setText(temp);
}

void Dialog_User_Add::on_pushButton_confirm_clicked()
{
    user_name = ui->lineEdit_user_name->text();
    user_authority = ui->comboBox_user_authority->currentText();
    iris = ui->lineEdit_iris->text();

    if (user_name == "" || user_name.size() > 10 || iris == "") {
        Message_Error msg;
        msg.setMessage("输入错误");
        msg.exec();
    } else {
        Message_Question msg;
        msg.setMessage("确定要增加用户吗？");
        if (msg.exec() == QDialog::Accepted) {
            this->accept();
        } else {
            this->reject();
        }
    }


}

void Dialog_User_Add::on_pushButton_cancel_clicked()
{
    this->reject();
}

//最大化和还原按钮
void Dialog_User_Add::on_btnMenu_Min_clicked()
{
    showMinimized();
}

//最大化按钮
void Dialog_User_Add::on_btnMenu_Max_clicked()
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
void Dialog_User_Add::on_btnMenu_Close_clicked()
{
    this->close();
}

