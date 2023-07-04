#include "protocoladaugaoptiune.h"

ProtocolAdaugaOptiune::ProtocolAdaugaOptiune(QString IDSesiune, QString DescriereOpt)
{
    this->IDSesiune=IDSesiune.toInt();
    this->DescriereOpt=DescriereOpt;
    this->NrVoturi=0;
}

void ProtocolAdaugaOptiune::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    /*db.getDataBase().open();
    createMessage();
    db.getDataBase().close();
    socket->write(Message);*/
    //DataBase &db = DataBase::getInstance();
    db.ConnectDB();
    //db.getDataBase().open();
    createMessage();
    db.destroyDatabase();
    //db.getDataBase().close();
    socket->write(Message);
}

void ProtocolAdaugaOptiune::createMessage()
{
    QSqlQuery query;
    query.prepare("INSERT INTO [Optiuni](ID_Sesiune,DescriereOpt,NrVoturi) values (:ID_Sesiune,:DescriereOpt,:NrVoturi)");
    query.bindValue(":ID_Sesiune",IDSesiune);
    query.bindValue(":DescriereOpt",DescriereOpt);
    query.bindValue(":NrVoturi",NrVoturi);
    //trimit inapoi id optiune, tu actualizezi optiunile, cand votezi intorci id si eu incrementez in baza

    QString IDq;
    if(query.exec()){
        QSqlQuery query2;
        if(query2.exec("select ID_Optiune from [Optiuni] where DescriereOpt='"+DescriereOpt+"'")){
            while(query2.next()){
                IDq = query2.value(0).toString();
                //qDebug()<<"S-a trimis ID_Optiune"<<IDq;
            }
        }
        QString myString = "4|1|"+IDq;
        qDebug()<<"S-a adaugat optiunea cu ID: "<<IDq<<"Date optiune: "<<DescriereOpt;
        this->Message=myString.toUtf8();
    }
    else{
        qDebug()<<"Optiunea nu a fost adaugata!";
        this->Message="4|0";
    }
}


