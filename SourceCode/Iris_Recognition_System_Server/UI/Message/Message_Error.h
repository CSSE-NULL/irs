#ifndef MESSAGE_ERROR_H
#define MESSAGE_ERROR_H

#include <QDialog>

namespace Ui {
class Message_Error;
}

class Message_Error : public QDialog
{
    Q_OBJECT

public:
    explicit Message_Error(QWidget *parent = 0);
    ~Message_Error();

    void setMessage(QString);

private slots:
    void on_btnMenu_Close_clicked();
    void on_pushButton_confirm_clicked();

private:
    Ui::Message_Error *ui;
};

#endif // MESSAGE_ERROR_H
