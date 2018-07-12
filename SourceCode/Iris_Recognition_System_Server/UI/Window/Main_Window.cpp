#include "Main_Window.h"
#include "ui_Main_Window.h"


Main_Window::Main_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_Window)
{
    ui->setupUi(this);

    //max记录当前是否最大化
    this->max = false;

    //location记录最大化前窗体的位置
    this->location = this->geometry();

    //设置窗体属性
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    //canMove参数用来实现窗体拖动
    this->setProperty("canMove", true);

    //设置属性，用来加载qss
    this->setProperty("form","window");
    ui->widgetTitle->setProperty("form", "title");
    ui->widgetLeft->setProperty("nav", "left");

    //添加属性,用于切换ico用
    ui->btn_host->setProperty("icoName", "host");
    ui->btn_user->setProperty("icoName", "user");
    ui->btn_device->setProperty("icoName", "device");
    ui->btn_record->setProperty("icoName", "record");

    //给所有toolbuttom建议连接
    QList<QToolButton *> btns = ui->widgetLeft->findChildren<QToolButton *>();
    foreach (QToolButton *btn, btns) {
        btn->setMaximumHeight(80);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));
    }

    //增加功能tab到stackedwidget
    tab_device = new Tab_Device;
    tab_host = new Tab_Host;
    tab_user = new Tab_User;
    tab_record = new Tab_Record;
    ui->stackedWidgetRight->addWidget(tab_host);
    ui->stackedWidgetRight->addWidget(tab_user);
    ui->stackedWidgetRight->addWidget(tab_device);
    ui->stackedWidgetRight->addWidget(tab_record);

    //打开窗体默认进入host
    ui->btn_host->click();

    //系统托盘
    system_tray = new System_Tray();
    system_tray->show();
    connect(system_tray, SIGNAL(showAction()), this, SLOT(on_showAction()));
    connect(system_tray, SIGNAL(quitAction()), this, SLOT(on_quitAction()));
    connect(system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(SystemTrayActivated(QSystemTrayIcon::ActivationReason)));

    //server服务
    server = new Server;
    connect(server, SIGNAL(pass(QString,QDateTime,QString,QString)), this, SLOT(windowReadDataSlot(QString,QDateTime,QString,QString)));

    //初始化系统托盘菜单
    pContextMenu = new QMenu;

    //maximize选项
    minimize = new QAction(tr("&最小化"),this);
    pContextMenu->addAction(minimize);
    connect(minimize, SIGNAL(triggered()), this, SLOT(on_btnMenu_Min_clicked()));

    //minimize选项
    maximize_revert = new QAction(tr("&最大化"),this);
    pContextMenu->addAction(maximize_revert);
    connect(maximize_revert, SIGNAL(triggered()), this, SLOT(on_btnMenu_Max_clicked()));

    //分割线
    pContextMenu->addSeparator();

    //quit选项
    quit = new QAction(tr("&退出"),this);
    pContextMenu->addAction(quit);
    connect(quit, SIGNAL(triggered()), this, SLOT(on_quitAction()));

    ui->btnMenu->setMenu(pContextMenu);
}

Main_Window::~Main_Window()
{
    delete ui;
}

//点击左侧菜单栏按钮切换页面
void Main_Window::buttonClick()
{
    //获取点击的按钮和他的文本值
    QToolButton *b = (QToolButton *)sender();
    QString text = b->text();

    //根据按钮的属性切换选中状态和非选中状态的图片
    QList<QToolButton *> btns = ui->widgetLeft->findChildren<QToolButton *>();
    foreach (QToolButton *btn, btns) {
        QString icoName = btn->property("icoName").toString();
        if (btn != b) {
            btn->setChecked(false);
            btn->setIcon(QIcon(QString(":/image/%1.png").arg(icoName)));
        } else {
            btn->setChecked(true);
            btn->setIcon(QIcon(QString(":/image/%1_focus.png").arg(icoName)));
        }
    }

    //根据文本值切换页面
    if (text == "主页") {
        ui->stackedWidgetRight->setCurrentIndex(0);
    } else if (text == "用户界面") {
        ui->stackedWidgetRight->setCurrentIndex(1);
    } else if (text == "设备界面") {
        ui->stackedWidgetRight->setCurrentIndex(2);
    } else if (text == "识别记录") {
        ui->stackedWidgetRight->setCurrentIndex(3);
    }
}

//最小化按钮
void Main_Window::on_btnMenu_Min_clicked()
{
    showMinimized();
}

//最大化和还原按钮
void Main_Window::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        this->setProperty("canMove", true);
        maximize_revert->setText("最大化");
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        this->setProperty("canMove", false);
        maximize_revert->setText("还原");
    }

    max = !max;
}

//关闭窗体按钮
void Main_Window::on_btnMenu_Close_clicked()
{
    this->hide();
}

//点击系统托盘槽函数
void Main_Window::SystemTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger://单击打开窗体
    {
        this->show();
        break;
    }
    case QSystemTrayIcon::DoubleClick://双击打开窗体
    {
        this->show();
        break;
    }
    default:
        break;
    }
}

//系统托盘菜单show选项打开窗体
void Main_Window::on_showAction()
{
    this->show();
}

//系统托盘菜单quit选项退出程序
void Main_Window::on_quitAction()
{
    exit(0);
}

//sever通过虹膜验证后向该窗体传递数据，新建一个record记录
void Main_Window::windowReadDataSlot(QString device_id, QDateTime time, QString result, QString user_id)
{
    if (user_id == "") {
        tab_record->add(device_id, time, result);
    } else {
        tab_record->add(device_id, time, result, user_id);
    }

}
