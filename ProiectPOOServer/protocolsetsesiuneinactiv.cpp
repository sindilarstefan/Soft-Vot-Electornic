#include "protocolsetsesiuneinactiv.h"

ProtocolSetSesiuneInactiv::ProtocolSetSesiuneInactiv(QString IDSes)
{
    this->IDSes=IDSes;
}

void ProtocolSetSesiuneInactiv::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolSetSesiuneInactiv::createMessage()
{
    QSqlQuery query;
    query.prepare("update SesiuniVot set Status = 'Inactiva' where ID_Sesiune ='"+IDSes+"'");

    QString myString;
    QString MessageSent;

    if(query.exec()){

        myString = "13|1";
        qDebug()<<"Sesiunea de vot cu ID:"+IDSes+" a fost dezactivata!";
        this->Message=myString.toUtf8();
    }
    else{
        qDebug()<<"Sesiunea nu a fost dezactivata!";
        this->Message="13|0";
    }
}
