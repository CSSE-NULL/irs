#ifndef SYSTEM_TRAY_H
#define SYSTEM_TRAY_H

#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QApplication>

class System_Tray: public QSystemTrayIcon
{
    Q_OBJECT

public:
    explicit System_Tray(QWidget *parent = 0);

signals:
    void showAction();
    void quitAction();

private:
    QAction* quit;
    QAction* showWindow;
    QMenu* pContextMenu;

};

#endif // SYSTEM_TRAY_H
