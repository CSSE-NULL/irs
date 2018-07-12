#ifndef TAB_USER_H
#define TAB_USER_H

#include "UI/Dialog/Dialog_User_Add.h"
#include "UI/Dialog/Dialog_User_Change.h"
#include "UI/Message/Message_Question.h"
#include "UI/Message/Message_Error.h"
#include "Function/Mysql_Operation.h"
#include "Scan/Scan.h"
#include "Function/NDBManipulate.h"
#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Tab_User;
}

class Tab_User : public QWidget
{
    Q_OBJECT

public:
    explicit Tab_User(QWidget *parent = 0);
    ~Tab_User();

private slots:
    void on_pushButton_delete_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_change_clicked();

    void filter();

private:
    Ui::Tab_User *ui;

    void set_table_user();
};

#endif // TAB_USER_H
