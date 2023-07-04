#include "thread.h"
#include "database.h"

#include <QString>
#include "cfactoryprotocol.h"
#include "ProtocolList.h"

void Thread::run(){
    //thread starts here
    qDebug() << "Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        qDebug() << "There was a problem connecting";
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    exec();
}


void Thread::readyRead()
{

    QByteArray Data = socket->readAll();

    QStringList dataList=QString(Data).split('|');

    if (dataList.value(0)=="1")
        CFactoryProtocol::createProtocol(Data,Login)->writeOnSocket(socket,DataBase::getInstance());

    if (dataList.value(0)=="2")
        CFactoryProtocol::createProtocol(Data,Register)->writeOnSocket(socket,DataBase::getInstance());

    if (dataList.value(0)=="3")
        CFactoryProtocol::createProtocol(Data,AdaugaSesiune)->writeOnSocket(socket,DataBase::getInstance());

    if (dataList.value(0)=="4")
        CFactoryProtocol::createProtocol(Data,AdaugaOptiune)->writeOnSocket(socket,DataBase::getInstance());

    if (dataList.value(0)=="5")
        CFactoryProtocol::createProtocol(Data,LoadSesiuniActive)->writeOnSocket(socket,DataBase::getInstance());

    if (dataList.value(0)=="6")
        CFactoryProtocol::createProtocol(Data,LoadSesiuniInactive)->writeOnSocket(socket, DataBase::getInstance());

    if (dataList.value(0)=="7")
        CFactoryProtocol::createProtocol(Data,AmUitatParola)->writeOnSocket(socket, DataBase::getInstance());

    if (dataList.value(0)=="8")
        CFactoryProtocol::createProtocol(Data,CautareSesiune)->writeOnSocket(socket, DataBase::getInstance());

    if (dataList.value(0)=="9")
        CFactoryProtocol::createProtocol(Data,GenereazaRezultat)->writeOnSocket(socket, DataBase::getInstance());

    if (dataList.value(0)=="10")
        CFactoryProtocol::createProtocol(Data,IncreaseVote)->writeOnSocket(socket, DataBase::getInstance());

    if(dataList.value(0)=="11")
        CFactoryProtocol::createProtocol(Data,GenereazaOptiuni)->writeOnSocket(socket, DataBase::getInstance());

    if(dataList.value(0)=="12")
        CFactoryProtocol::createProtocol(Data,SetSesiuneActiv)->writeOnSocket(socket, DataBase::getInstance());

    if(dataList.value(0)=="13")
        CFactoryProtocol::createProtocol(Data,SetSesiuneInactiv)->writeOnSocket(socket, DataBase::getInstance());
}

void Thread::disconnected(){

    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}
