#include "protocoladaugasesiune.h"

ProtocolAdaugaSesiune::ProtocolAdaugaSesiune(QString Descriere, QString NrOptiuni, QString DataSesiune, QString Status, QString NrOptiuniDisponibile)
{
    this->Descriere = Descriere;
    this->NrOptiuni = NrOptiuni;
    this->DataSesiune = DataSesiune;
    this->Status=Status;
    this->NrOptiuniDisponibile=NrOptiuniDisponibile;
    //qDebug()<<Descriere<<NrOptiuni<<DataSesiune;
}

void ProtocolAdaugaSesiune::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

void ProtocolAdaugaSesiune::createMessage()
{
    QSqlQuery query;
    query.prepare("INSERT INTO [SesiuniVot](DescriereSes,NrOptiuni,DataSes,Status, NrOptDisp) values (:DescriereSes,:NrOptiuni,:DataSes,:Status,:NrOptiuniDisponibile)");
    query.bindValue(":DescriereSes",Descriere);
    query.bindValue(":NrOptiuni",NrOptiuni);
    query.bindValue(":DataSes",DataSesiune);
    query.bindValue(":Status",Status);
    query.bindValue(":NrOptiuniDisponibile",NrOptiuniDisponibile);

    QString ID;
    if(query.exec()){
        QSqlQuery query2;
        if(query2.exec("select ID_Sesiune from [SesiuniVot] where DescriereSes='"+Descriere+"'")){
        while (query2.next()){
            ID = query2.value(0).toString();
            //qDebug()<<ID;
        }
        }
        QString myString = "3|1|"+ID;
        qDebug()<<"S-a creat sesiunea cu ID-ul:"<<ID<<"! Date sesiune:"<<Descriere<<NrOptiuni<<DataSesiune<<Status<<NrOptiuniDisponibile;
        this->Message=myString.toUtf8();

        }
    else{
        qDebug()<<"Sesiunea nu a fost creata!";
        this->Message="3|0";
    }
}
