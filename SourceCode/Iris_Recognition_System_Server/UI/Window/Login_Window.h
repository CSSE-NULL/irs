#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include "Function/Mysql_Operation.h"
#include "UI/Message/Message_Error.h"

#include <QDialog>

namespace Ui {
class Login_Window;
}

class Login_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Login_Window(QWidget *parent = 0);
    ~Login_Window();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::Login_Window *ui;
};

#endif // LOGIN_WINDOW_H
