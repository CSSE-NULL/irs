#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H

#include "Message/Message_Error.h"
#include "Message/Message_Correct.h"
#include <QtSql>
#include <QFileDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDataStream>
#include <QMessageBox>
#include "Scan.h"
#include "NDBManipulate.h"

namespace Ui {
class Client_Window;
}

class Client_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Client_Window(QWidget *parent = 0);
    ~Client_Window();

private slots:
    void on_pushButton_scanner_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_submit_clicked();

    void on_btnMenu_Min_clicked();
    void on_btnMenu_Close_clicked();

    void slotReadData();

private:
    Ui::Client_Window *ui;
    QTcpSocket *socket;

};
#endif // CLIENT_WINDOW_H
