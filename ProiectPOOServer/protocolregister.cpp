#include "protocolregister.h"

ProtocolRegister::ProtocolRegister(QString Nume,QString Prenume, QString CNP, QString Email, QString Parola)
{
    this->Nume=Nume;
    this->Prenume=Prenume;
    this->CNP=CNP;
    this->Email=Email;
    this->Parola=Parola;
}


bool searchEmail(QString Email)
{
    QSqlQuery query;
    query.prepare("select* from Utilizatori where Email='"+Email+"'");
    query.exec();
    while(query.next())
    {
        return true;
    }
    return false;

}
void ProtocolRegister::createMessage()
{
    if(searchEmail(Email))
    {
        this->Message="2|0";
    }
    else
    {
        QSqlQuery query;
        query.prepare("INSERT INTO [Utilizatori](Nume,Prenume,CNP,Email,Parola)  values (:Nume,:Prenume,:CNP,:Email,:Parola)");
        query.bindValue(":Nume",Nume);
        query.bindValue(":Prenume",Prenume);
        query.bindValue(":CNP",CNP);
        query.bindValue(":Email",Email);
        query.bindValue(":Parola",Parola);

        if(query.exec()){
            qDebug()<<"Utilizatorul a fost inregistrat cu succes!";
            this->Message="2|1";
        }
        else{
            qDebug()<<"Utilizatorul nu a fost inregistrat!";
            this->Message="2|0";
        }
    }
}

void ProtocolRegister::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}
