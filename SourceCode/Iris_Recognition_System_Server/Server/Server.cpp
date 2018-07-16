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
    //找到list中存放的对应的socket
    for (int i = 0; i < clients.size(); ++i)
    {
        qDebug()<<clients.size()<<endl;
        qDebug()<<clients.at(i)->socketDescriptor()<<endl;
        if (clients.at(i)->socketDescriptor() == sockfd)
        {
            //新建user_id，用于发送到主窗体添加record记录，再验证过程中初始化
            OsiManager::Result iris;
            memset(iris.code,0,M);
            memset(iris.mask,0,M);
            strcpy(iris.code, msg.split(",").at(0).toStdString().c_str()) ;
            strcpy(iris.mask,msg.split(",").at(1).toStdString().c_str());
            qDebug()<<iris.code<<endl;
            for(int i=0;i<STN;i++){
                memset(iris.shift_code[i],0,M);
                strcat(iris.shift_code[i],msg.split(",").at(i+2).toStdString().c_str());
            }
            QString device_id = QString(msg).split(",").at(STN+2);
            QString user_id = "";
            Mysql_Operation *mysql_operation = new Mysql_Operation();
            if(mysql_operation->identity_verification(iris,user_id,device_id))
            {
                //验证通过则通过socket向client返回true，并发送user_id,device_id,time,status到主窗体添加record记录
                QTextStream in(clients.at(i));
                in << "true";
                QDateTime time = QDateTime::currentDateTime();
                emit pass(device_id,time,"成功",user_id);
            }else {
                //验证失败则通过socket向client返回false,并发送user_id,device_id,time,status到主窗体添加record记录
                QTextStream in(clients.at(i));
                in << "false";
                QDateTime time = QDateTime::currentDateTime();
                emit pass(device_id,time,"失败",user_id);
            }
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


