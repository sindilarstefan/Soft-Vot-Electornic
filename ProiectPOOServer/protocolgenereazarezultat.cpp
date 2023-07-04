#include "protocolgenereazarezultat.h"

ProtocolGenereazaRezultat::ProtocolGenereazaRezultat(QString ID)
{
    this->ID=ID;
}

void ProtocolGenereazaRezultat::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolGenereazaRezultat::createMessage()
{
    QSqlQuery query;
    query.prepare("select O.ID_Optiune, O.DescriereOpt, O.NrVoturi from SesiuniVot S inner join Optiuni O on S.ID_Sesiune = O.ID_Sesiune where S.ID_Sesiune='"+ID+"'");

    QString IDq;
    QString Descriereq;
    QString NrVoturiq;

    QString myString;
    QString MessageSent;

    if(query.exec()){
        while(query.next()){
            IDq = query.value(0).toString();
            Descriereq = query.value(1).toString();
            NrVoturiq = query.value(2).toString();

            myString = "9|1|" + IDq + "|" + Descriereq + "|" + NrVoturiq;
            qDebug()<<myString;
            MessageSent = MessageSent + myString + "%";
        }
        qDebug()<<"Rezultatul a fost generat cu succes!";
        qDebug()<<"Mesaj trimis: "<<MessageSent;
        this->Message=MessageSent.toUtf8();
    }
    else{
        qDebug()<<"Rezultatul nu a fost generat!";
        this->Message="9|0";
    }
}




