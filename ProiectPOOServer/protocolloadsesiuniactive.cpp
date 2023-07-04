#include "protocolloadsesiuniactive.h"

ProtocolLoadSesiuniActive::ProtocolLoadSesiuniActive(QString Descript)
{
    this->Descript=Descript;
}

void ProtocolLoadSesiuniActive::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolLoadSesiuniActive::createMessage()
{
    QSqlQuery query;
    query.prepare("select ID_Sesiune,DescriereSes,NrOptiuni,DataSes,Status,NrOptDisp from [SesiuniVot] where Status='Activa'");

    QString IDq;
    QString Descriereq;
    QString NrOptiuniq;
    QString Dataq;
    QString Statusq;
    QString NrOptDispq;
    QString myString;
    QString MessageSent;

    if(query.exec()){
        while(query.next()){
            IDq = query.value(0).toString();
            Descriereq = query.value(1).toString();
            NrOptiuniq = query.value(2).toString();
            Dataq = query.value(3).toString();
            Statusq = query.value(4).toString();
            NrOptDispq = query.value(5).toString();

            myString = "5|1|" + IDq + "|" + Descriereq + "|" + NrOptiuniq + "|" + Dataq + "|" + Statusq + "|" + NrOptDispq;
            qDebug()<<myString;
            MessageSent = MessageSent + myString + "%";
        }
        qDebug()<<"S-au incarcat sesiunile de vot active!";
        qDebug()<<"Mesaj trimis: "<<MessageSent;
        this->Message=MessageSent.toUtf8();
    }
    else{
        qDebug()<<"Incarcarea sesiunilor de vot active a esuat!";
        this->Message="5|0";
    }
}
