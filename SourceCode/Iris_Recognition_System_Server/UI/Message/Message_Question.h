#ifndef MESSAGE_QUESTION_H
#define MESSAGE_QUESTION_H

#include <QDialog>

namespace Ui {
class Message_Question;
}

class Message_Question : public QDialog
{
    Q_OBJECT

public:
    explicit Message_Question(QWidget *parent = 0);
    ~Message_Question();

    void setMessage(QString);

private slots:
    void on_btnMenu_Close_clicked();

    void on_pushButton_confirm_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::Message_Question *ui;

};

#endif // MESSAGE_QUESTION_H
