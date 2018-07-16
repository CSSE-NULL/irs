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
        if(blockSize==0) //����Ǹտ�ʼ��������
        {
            //�жϽ��յ������Ƿ������ֽڣ�Ҳ�����ļ��Ĵ�С��Ϣ
            //������򱣴浽blockSize�����У�û���򷵻أ�������������
            if(this->bytesAvailable() < (int)sizeof(quint16)) return;
            in >> blockSize;
        }
        if(this->bytesAvailable() < blockSize) return;
        //���û�еõ�ȫ�������ݣ��򷵻أ�������������
        QByteArray ba;
        ba.resize(this->bytesAvailable());
        this->read(ba.data(),ba.size());
     emit sockReadDataSignal(this->socketDescriptor(),(QString)ba.mid(15));
}



void Socket::disconnectSlot()
{
    emit disconnectSignal(this->socketDescriptor());
}

