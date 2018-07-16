#include "Socket.h"

Socket::Socket()
{
    blockSize = 0;
    connect(this, SIGNAL(readyRead()), this, SLOT(readDataSlot()));
    connect(this, SIGNAL(disconnected()), this, SLOT(disconnectSlot()));

}

Socket::~Socket()
{

}

void Socket::readDataSlot()
{
    QDataStream in(this);
        if(blockSize==0) //如果是刚开始接收数据
        {
            //判断接收的数据是否有两字节，也就是文件的大小信息
            //如果有则保存到blockSize变量中，没有则返回，继续接收数据
            if(this->bytesAvailable() < (int)sizeof(quint16)) return;
            in >> blockSize;
        }
        if(this->bytesAvailable() < blockSize) return;
        //如果没有得到全部的数据，则返回，继续接收数据
        QByteArray ba;
        ba.resize(this->bytesAvailable());
        this->read(ba.data(),ba.size());
     emit sockReadDataSignal(this->socketDescriptor(),(QString)ba.mid(15));
}



void Socket::disconnectSlot()
{
    emit disconnectSignal(this->socketDescriptor());
}

