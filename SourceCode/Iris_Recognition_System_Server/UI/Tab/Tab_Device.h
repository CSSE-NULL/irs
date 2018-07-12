#ifndef TAB_DEVICE_H
#define TAB_DEVICE_H

#include "UI/Dialog/Dialog_Device_Add.h"
#include "UI/Dialog/Dialog_Device_Change.h"
#include "UI/Message/Message_Question.h"
#include "UI/Message/Message_Error.h"
#include "Function/Mysql_Operation.h"

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Tab_Device;
}

class Tab_Device : public QWidget
{
    Q_OBJECT

public:
    explicit Tab_Device(QWidget *parent = 0);
    ~Tab_Device();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_change_clicked();

    void filter();

private:
    Ui::Tab_Device *ui;

    void set_table_device();
};

#endif // TAB_DEVICE_H
