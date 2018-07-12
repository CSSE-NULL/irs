#ifndef DIALOG_DEVICE_CHANGE_H
#define DIALOG_DEVICE_CHANGE_H

#include "UI/Message/Message_Question.h"
#include "UI/Message/Message_Error.h"

#include <QDialog>
#include <QDesktopWidget>


namespace Ui {
class Dialog_Device_Change;
}

class Dialog_Device_Change : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Device_Change(QWidget *parent = 0);
    ~Dialog_Device_Change();

    QString get_device_name();
    QString get_device_authority();
    QString get_position();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void on_pushButton_confirm_2_clicked();
    void on_pushButton_cancel_2_clicked();

private:
    Ui::Dialog_Device_Change *ui;

    QString device_name;
    QString device_authority;
    QString position;

    bool max;
    QRect location;

};

#endif // DIALOG_DEVICE_CHANGE_H
