#ifndef SERVER_H
#define SERVER_H

#include "Function/Mysql_Operation.h"
#include "Socket.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDataStream>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    ~Server();

protected:
     void incomingConnection(qintptr socketDescriptor);

private slots:
     void handle(qintptr, QString);
     void disconnectSlot(qintptr);

signals:

     void pass(QString, QDateTime,QString,QString);

private:
     QList<Socket *> clients;
};

#endif // SERVER_H
