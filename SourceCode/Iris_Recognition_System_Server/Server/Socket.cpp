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
     QString msg;
     QByteArray ba;
     this->setReadBufferSize(100);
     ba = this->readAll();
     msg=(QString)ba;
     emit sockReadDataSignal(this->socketDescriptor(),msg);
}



void Socket::disconnectSlot()
{
    emit disconnectSignal(this->socketDescriptor());
}

