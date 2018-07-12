#ifndef TAB_HOST_H
#define TAB_HOST_H

#include <QWidget>

namespace Ui {
class Tab_Host;
}

class Tab_Host : public QWidget
{
    Q_OBJECT

public:
    explicit Tab_Host(QWidget *parent = 0);
    ~Tab_Host();

private:
    Ui::Tab_Host *ui;
};

#endif // TAB_HOST_H
