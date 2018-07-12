#ifndef TAB_RECORD_H
#define TAB_RECORD_H

#include "Function/Mysql_Operation.h"

#include <QWidget>

namespace Ui {
class Tab_Record;
}

class Tab_Record : public QWidget
{
    Q_OBJECT

public:
    explicit Tab_Record(QWidget *parent = 0);
    ~Tab_Record();

    void add(QString, QDateTime, QString, QString);
    void add(QString, QDateTime, QString);

public slots:
    void filter();

private:
    Ui::Tab_Record *ui;

    void set_table_record();
};


#endif // TAB_RECORD_H
