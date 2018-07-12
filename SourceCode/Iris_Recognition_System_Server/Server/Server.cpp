#include "Server.h"

Server::Server()
{
    //设置监听
    listen(QHostAddress::Any,8080);
}


Server::~Server()
{

}

//每次有client进行连接，执行此函数
void Server::incomingConnection(qintptr socketDescriptor)
{
   //获取连接的socket信息
   Socket *socket = new Socket;
   socket->setSocketDescriptor(socketDescriptor);

   //讲socket提交的信息交由handle函数处理
   QObject::connect(socket, SIGNAL(sockReadDataSignal(qintptr,QString)), this, SLOT(handle(qintptr,QString)));

   //断开连接
   QObject::connect(socket,SIGNAL(disconnectSignal(qintptr)),this,SLOT(disconnectSlot(qintptr)));


   //将该socket加入存放客户端连接的list
   clients << socket;
}

//处理socket提交的信息
void Server::handle(qintptr sockfd, QString msg)
{
    for (int i = 0; i < clients.size(); ++i)
    {
        if (clients.at(i)->socketDescriptor() == sockfd)
        {
            QString user_id = msg.split(",").at(0);
            QString device_id = msg.split(",").at(1);
            QDateTime time = QDateTime::currentDateTime();
            emit pass(device_id,time,"成功",user_id);
        }
    }
}

//断开连接
void Server::disconnectSlot(qintptr sockfd)
{
    for (int i = 0; i < clients.size(); ++i) {
        if (clients.at(i)->socketDescriptor() == sockfd)
            clients.removeAt(i);
    }
}


