#include "protocolcautaresesiune.h"

ProtocolCautareSesiune::ProtocolCautareSesiune(QString DescriereSes)
{
    this->DescriereSes=DescriereSes;
}

void ProtocolCautareSesiune::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolCautareSesiune::createMessage()
{
    QSqlQuery query;
    query.prepare("select ID_Sesiune,DescriereSes,NrOptiuni,DataSes,Status,NrOptDisp from [SesiuniVot] where DescriereSes like '%"+DescriereSes+"%'");

    QString IDq;
    QString Descriereq;
    QString NrOptiuniq;
    QString Dataq;
    QString Statusq;
    QString NrOptiuniDisponibileq;
    QString myString;
    QString MessageSent;

    if(query.exec()){
        while(query.next()){
            IDq = query.value(0).toString();
            Descriereq = query.value(1).toString();
            NrOptiuniq = query.value(2).toString();
            Dataq = query.value(3).toString();
            Statusq = query.value(4).toString();
            NrOptiuniDisponibileq=query.value(5).toString();

            myString = "8|1|" + IDq + "|" + Descriereq + "|" + NrOptiuniq + "|" + Dataq + "|" + Statusq + "|" + NrOptiuniDisponibileq;
            //qDebug()<<myString;
            MessageSent = MessageSent + myString + "%";
        }
        qDebug()<<"Sesiunea cautata a fost gasita!";
        qDebug()<<myString;
        this->Message=MessageSent.toUtf8();
    }
    else{
        qDebug()<<"Sesiunea cautata nu a fost gasita!";
        this->Message="8|0";
    }
}



