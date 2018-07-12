#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QTextStream>
#include <QHostAddress>

class Socket : public QTcpSocket
{
    Q_OBJECT

public:
    Socket();
    ~Socket();

signals:
    void disconnectSignal(qintptr);
    void sockReadDataSignal(qintptr, QString);

private slots:
    void readDataSlot();
    void disconnectSlot();

private:
    quint16 blockSize;  //����ļ��Ĵ�С��Ϣ
};

#endif // SOCKET_H
