#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "UI/Tab/Tab_Device.h"
#include "UI/Tab/Tab_Host.h"
#include "UI/Tab/Tab_Record.h"
#include "UI/Tab/Tab_User.h"
#include "UI/System_Tray/System_Tray.h"
#include "Server/Server.h"

#include <QMainWindow>
#include <QDialog>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QMenu>
#include <QApplication>
#include <QRect>

namespace Ui {
class Main_Window;
}

class Main_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Main_Window(QWidget *parent = 0);
    ~Main_Window();

private:
    Ui::Main_Window *ui;

    Tab_Device *tab_device = new Tab_Device;
    Tab_Host *tab_host = new Tab_Host;
    Tab_User *tab_user = new Tab_User;
    Tab_Record *tab_record = new Tab_Record;

    System_Tray* system_tray;

    Server *server;

    bool max;
    QRect location;

    QAction* quit;
    QAction* maximize_revert;
    QAction* minimize;
    QMenu* pContextMenu;

private slots:
    void buttonClick();

    void on_showAction();
    void on_quitAction();
    void SystemTrayActivated(QSystemTrayIcon::ActivationReason reason);

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void windowReadDataSlot(QString, QDateTime, QString, QString);
};


#endif // MAIN_WINDOW_H
