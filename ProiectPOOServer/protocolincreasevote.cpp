#include "protocolincreasevote.h"

ProtocolIncreaseVote::ProtocolIncreaseVote(QString ID)
{
    this->ID=ID;
}

void ProtocolIncreaseVote::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolIncreaseVote::createMessage()
{
    QSqlQuery query;
    query.prepare("update Optiuni set NrVoturi = NrVoturi + 1 where ID_Optiune='"+ID+"'");

    if(query.exec()){
        QString myString = "10|1|" + ID;
        qDebug()<<myString;

        qDebug()<<"Optiunea"<<ID<<"a fost votata!";
        this->Message=myString.toUtf8();

     }
    else{
        qDebug()<<"Optiunea nu a fost votata";
        this->Message="10|0";
    }

}
