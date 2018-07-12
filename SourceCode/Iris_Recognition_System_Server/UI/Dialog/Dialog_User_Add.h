#ifndef DIALOG_USER_ADD_H
#define DIALOG_USER_ADD_H

#include "UI/Message/Message_Question.h"
#include "UI/Message/Message_Error.h"

#include <QDialog>
#include <QFileDialog>
#include <QDesktopWidget>


namespace Ui {
class Dialog_User_Add;
}

class Dialog_User_Add : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_User_Add(QWidget *parent = 0);
    ~Dialog_User_Add();

    QString get_user_name();
    QString get_user_authority();
    QString get_iris();

private slots:
    void on_pushButton_choose_clicked();

    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::Dialog_User_Add *ui;

    QString user_name;
    QString user_authority;
    QString iris;

    bool max;
    QRect location;

};

#endif // DIALOG_USER_ADD_H
