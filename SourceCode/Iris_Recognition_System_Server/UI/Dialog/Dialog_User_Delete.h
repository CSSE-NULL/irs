#ifndef DIALOG_USER_DELETE_H
#define DIALOG_USER_DELETE_H

#include <QDialog>
#include <QMouseEvent>
#include <QDesktopWidget>

namespace Ui {
class Dialog_User_Delete;
}

class Dialog_User_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_User_Delete(QWidget *parent = 0);
    ~Dialog_User_Delete();

    QString get_user_id();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

private slots:
    void on_buttonBox_accepted();

    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

private:
    Ui::Dialog_User_Delete *ui;

    QString user_id;

    bool max;
    bool mMoveing;
    QRect location;
    QRect *mouse_rect;
    QRect window_rect;
    QPoint mMovePosition;
};

#endif // DIALOG_USER_DELETE_H
