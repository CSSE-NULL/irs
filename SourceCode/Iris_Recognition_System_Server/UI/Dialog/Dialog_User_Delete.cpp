#include "Dialog_User_Delete.h"
#include "ui_Dialog_User_Delete.h"

Dialog_User_Delete::Dialog_User_Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_User_Delete)
{
    ui->setupUi(this);

    //max记录当前是否最大化
    this->max = false;

    //location记录最大化前窗体的位置
    this->location = this->geometry();

    //指定鼠标事件可用区域
    window_rect = QApplication::desktop()->availableGeometry();
    mouse_rect = new QRect(0,0,window_rect.width(),40);

    //canMove用来标记是否能拖动窗体
    this->setProperty("canMove", true);

    //设置窗体属性
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
}

Dialog_User_Delete::~Dialog_User_Delete()
{
    delete ui;
}

QString Dialog_User_Delete::get_user_id()
{
    return user_id;
}

void Dialog_User_Delete::on_buttonBox_accepted()
{
    user_id = ui->lineEdit_user_id->text();

    this->accept();
}

//最小化按钮
void Dialog_User_Delete::on_btnMenu_Min_clicked()
{
    showMinimized();
}

//最大化和还原按钮
void Dialog_User_Delete::on_btnMenu_Max_clicked()
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
void Dialog_User_Delete::on_btnMenu_Close_clicked()
{
    this->close();
}

//重写鼠标按下事件
void Dialog_User_Delete::mousePressEvent(QMouseEvent *event)
{
    if(mouse_rect->contains(this->mapFromGlobal(QCursor::pos())) == true)
    {
        if(this->property("canMove").toBool())
        {
            mMoveing = true;
            mMovePosition = event->globalPos() - pos();
            return QDialog::mousePressEvent(event);
        }
    }
}

//重写鼠标移动事件
void Dialog_User_Delete::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
        && (event->globalPos()- mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

//重写鼠标释放事件
void Dialog_User_Delete::mouseReleaseEvent(QMouseEvent *event)
{
    mMoveing = false;
}

//双击最大化
void Dialog_User_Delete::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(mouse_rect->contains(this->mapFromGlobal(QCursor::pos())) == true) // 指定区域内
        on_btnMenu_Max_clicked();
}
