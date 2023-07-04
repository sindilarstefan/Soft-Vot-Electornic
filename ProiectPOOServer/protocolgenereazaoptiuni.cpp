#include "protocolgenereazaoptiuni.h"

ProtocolGenereazaOptiuni::ProtocolGenereazaOptiuni(QString IDSes)
{
    this->IDSes=IDSes;
}

void ProtocolGenereazaOptiuni::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolGenereazaOptiuni::createMessage()
{
    QSqlQuery query;
    query.prepare("select O.ID_Optiune, O.DescriereOpt from SesiuniVot S inner join Optiuni O on S.ID_Sesiune = O.ID_Sesiune where S.ID_Sesiune='"+IDSes+"'");

    QString IDq;
    QString Descriereq;

    QString myString;
    QString MessageSent;

    if(query.exec()){
        while(query.next()){
            IDq = query.value(0).toString();
            Descriereq = query.value(1).toString();

            myString = "11|1|" + IDq + "|" + Descriereq;
            qDebug()<<myString;
            MessageSent = MessageSent + myString + "%";
        }
        qDebug()<<"Optiunile pentru vot au fost trimise cu succes!";
        qDebug()<<"Mesaj trimis: "<<MessageSent;
        this->Message=MessageSent.toUtf8();
    }
    else{
        qDebug()<<"Optiunile nu au fost trimise!";
        this->Message="11|0";
    }
}
