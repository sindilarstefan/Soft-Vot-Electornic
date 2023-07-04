#include "protocolloadsesiuniinactive.h"

ProtocolLoadSesiuniInactive::ProtocolLoadSesiuniInactive(QString Descript)
{
    this->Descript=Descript;
}

void ProtocolLoadSesiuniInactive::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolLoadSesiuniInactive::createMessage()
{
    QSqlQuery query;
    query.prepare("select ID_Sesiune,DescriereSes,NrOptiuni,DataSes,Status from [SesiuniVot] where Status='Inactiva'");

    QString IDq;
    QString Descriereq;
    QString NrOptiuniq;
    QString Dataq;
    QString Statusq;
    QString myString;
    QString MessageSent;

    if(query.exec()){
        while(query.next()){
            IDq = query.value(0).toString();
            Descriereq = query.value(1).toString();
            NrOptiuniq = query.value(2).toString();
            Dataq = query.value(3).toString();
            Statusq = query.value(4).toString();

            myString = "6|1|" + IDq + "|" + Descriereq + "|" + NrOptiuniq + "|" + Dataq + "|" + Statusq;
            qDebug()<<myString;
            MessageSent = MessageSent + myString + "%";
        }
        qDebug()<<"S-au incarcat sesiunile de vot inactive!";
        qDebug()<<"Mesaj trimis: "<<MessageSent;
        this->Message=MessageSent.toUtf8();
    }
    else{
        qDebug()<<"Incarcarea sesiunilor de vot inactive a esuat!";
        this->Message="6|0";
    }
}





