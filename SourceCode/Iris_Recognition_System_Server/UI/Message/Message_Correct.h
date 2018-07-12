#ifndef MESSAGE_CORRECT_H
#define MESSAGE_CORRECT_H

#include <QDialog>

namespace Ui {
class Message_Correct;
}

class Message_Correct : public QDialog
{
    Q_OBJECT

public:
    explicit Message_Correct(QWidget *parent = 0);
    ~Message_Correct();

    void setMessage(QString);

private slots:
    void on_btnMenu_Close_clicked();
    void on_pushButton_confirm_clicked();

private:
    Ui::Message_Correct *ui;
};

#endif // MESSAGE_CORRECT_H
