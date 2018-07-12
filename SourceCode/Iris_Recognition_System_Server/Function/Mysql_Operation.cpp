#include "Mysql_Operation.h"

Mysql_Operation::Mysql_Operation()
{
    //初始化一个数据库连接
    if (QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/irs.db");
    db.open();
}

Mysql_Operation::~Mysql_Operation()
{
    db.close();
}

//初始化table，返回一个model，根据时间排序
QSqlQueryModel* Mysql_Operation::initialize(QString table_name)
{
    //构造sql语句
    QString sql = "select * from " + table_name + " order by " + table_name + "_register_time desc";

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql);
    return model;
}

//实时查询，返回一个model
QSqlQueryModel* Mysql_Operation::filter(QString table_name, QStringList value, QStringList column)
{
    //构造sql语句
    QString sql = "select * from " + table_name;

    for (int i=0 ; i<value.size() ; i++) {
        if (i == 0) {
            sql = sql + " where " + column.at(i) + " = '" + value.at(i) + "'";
        } else {
            sql = sql + " and " + column.at(i) + " = '" + value.at(i) + "'";
        }
    }

    sql = sql + " order by " + table_name + "_register_time desc";

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql);
    return model;
}

//插入操作
bool Mysql_Operation::insert(QString table_name, QStringList value, QStringList column)
{
    //构造sql语句
    QString sql = "insert into " + table_name + " (";
    for (int i=0 ; i<column.size() ; i++) {
        if (i==0) {
            sql = sql + column.at(i);
        } else {
            sql = sql + "," + column.at(i);
        }
    }
    sql = sql + ") values ('";
    for (int i=0 ; i<value.size() ; i++) {
        if (i==0) {
            sql = sql + value.at(i) + "'";
        } else {
            sql = sql + ",'" + value.at(i) + "'";
        }
    }
    sql = sql + ");";

    QSqlQuery query;
    query.prepare(sql);
    return query.exec();
}

//更新操作
bool Mysql_Operation::update(QString table_name, QString id, QStringList value, QStringList column)
{
    //构造sql语句
    QString sql = "update " + table_name + " set ";
    for (int i=0 ; i<value.size() ; i++) {
        if (i == 0) {
            sql = sql + column.at(i) + "='" + value.at(i) + "'";
        } else {
            sql = sql + "," +column.at(i) + "='" + value.at(i) + "'";
        }

    }
    sql = sql + " where " + table_name + "_id = '" + id +"';";

    QSqlQuery query;
    query.prepare(sql);
    return query.exec();
}

//删除操作
bool Mysql_Operation::Delete(QString table_name, QString id)
{
    //构造sql语句
    QString sql = "delete from " + table_name + " where " + table_name + "_id = '" + id +"';";

    QSqlQuery query;
    query.prepare(sql);
    return query.exec();
}

//登陆验证
bool Mysql_Operation::login(QString admin_name, QString admin_password)
{
    if (admin_name == "" || admin_password == "") {
        return false;
    } else {
        QSqlQuery query;
        //构造sql语句
        if (query.exec("select admin_password from administrator where admin_name = '" + admin_name + "'")) {
            query.next();

            QString result = query.value(0).toString();
            if (admin_password == result) {
                return true;
            } else {
               return false;
            }
        } else {
            return false;
        }
    }
}

//验证用户虹膜和权限信息
bool Mysql_Operation::identity_verification(OsiManager::Result iris_struct, QString &user_id,QString device_id)
{
//查询user表中所有的虹膜，掩码信息和用户权限，进行验证，如果验证通过，则找到user_id并返回true，验证失败返回false
    QSqlQuery query;
    query.exec("select irisdata,mask,user_id,user_authority from user");
    while(query.next())
    {
        //irisdata和mask需要从QString转换到char数组形式
        QString  Qirisdata = query.value(0).toString();
        std::string  Sirisdata = Qirisdata.toStdString();
        const char* irisdata = Sirisdata.c_str();
        int longNDB[2 * LEN][2];
        GetBinaryArray(irisdata, longNDB);

        QString  Qmask = query.value(1).toString();
        std::string  Smask = Qmask.toStdString();
        const char* mask = Smask.c_str();

        QString user_authority = query.value(3).toString();

        //验证虹膜信息
        if(Recognition(iris_struct,longNDB,mask))
        {
            user_id = query.value(2).toString();

            //验证用户权限
            QSqlQuery query_device_authority;
            query_device_authority.exec("select device_authority from device where device_id = '" + device_id + "';");
            query_device_authority.first();
            QString device_authority = query_device_authority.value(0).toString();
            if(transform(user_authority) <= transform(device_authority))
            {
                return true;
            }
        }
    }
    return false;
}

//用来将权限字符串转换成int来进行比较
int Mysql_Operation::transform(QString QString_authority)
{
    if(QString_authority == "Level_1")
    {
        return 1;
    }else if(QString_authority == "Level_2")
    {
        return 2;
    }
    else if(QString_authority == "Level_3"){
        return 3;
    }else{
        //当没有对应设备时
        return 0;
    }
}






