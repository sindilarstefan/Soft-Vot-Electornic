#include "protocolsetsesiuneactiv.h"

ProtocolSetSesiuneActiv::ProtocolSetSesiuneActiv(QString IDSes)
{
    this->IDSes=IDSes;
}

void ProtocolSetSesiuneActiv::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolSetSesiuneActiv::createMessage()
{
    QSqlQuery query;
    query.prepare("update SesiuniVot set Status = 'Activa' where ID_Sesiune ='"+IDSes+"'");

    QString myString;
    QString MessageSent;

    if(query.exec()){

        myString = "12|1";
        qDebug()<<"Sesiunea de vot cu ID:"+IDSes+" a fost activata!";
        this->Message=myString.toUtf8();
    }
    else{
        qDebug()<<"Sesiunea nu a fost activata!";
        this->Message="12|0";
    }
}
