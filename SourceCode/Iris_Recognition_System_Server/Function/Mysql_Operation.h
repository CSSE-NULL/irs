#ifndef MYSQL_OPERATION_H
#define MYSQL_OPERATION_H

#include <QtSql>
#include <QSqlQueryModel>
#include "Scan/OsiManager.h"
#include "Function/Recognition.h"
using namespace osiris;

class Mysql_Operation
{
public:
    Mysql_Operation();
    ~Mysql_Operation();

    QSqlQueryModel* initialize(QString);
    QSqlQueryModel* filter(QString, QStringList, QStringList);

    bool insert(QString, QStringList, QStringList);
    bool update(QString, QString, QStringList, QStringList);
    bool Delete(QString, QString);
    bool login(QString, QString);
    bool identity_verification(OsiManager::Result iris_struct, QString &user_id,QString device_id);

private:
    int transform(QString);

    QSqlDatabase db;
};

#endif // MYSQL_OPERATION_H
