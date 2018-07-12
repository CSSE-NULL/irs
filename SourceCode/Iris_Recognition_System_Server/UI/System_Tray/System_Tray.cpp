#include "System_Tray.h"

System_Tray::System_Tray(QWidget *parent) :
    QSystemTrayIcon(parent)
{
    //设置系统托盘图片
    QIcon icon(":/image/main.png");
    this->setIcon(icon);

    //设置系统托盘提示信息
    this->setToolTip("Iris_Recognition_System");

    //初始化系统托盘菜单
    pContextMenu = new QMenu;

    //quit选项
    quit = new QAction(tr("&退出"),this);
    pContextMenu->addAction(quit);
    connect(quit, SIGNAL(triggered()), this, SIGNAL(quitAction()));

    //分割线
    pContextMenu->addSeparator();

    //show选项
    showWindow = new QAction(tr("&显示"),this);
    pContextMenu->addAction(showWindow);
    connect(showWindow, SIGNAL(triggered()), this, SIGNAL(showAction()));

    this->setContextMenu(pContextMenu);
}


