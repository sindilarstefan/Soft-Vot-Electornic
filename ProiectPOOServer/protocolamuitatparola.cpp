#include "protocolamuitatparola.h"

ProtocolAmUitatParola::ProtocolAmUitatParola(QString Email, QString Parola)
{
    this->Email=Email;
    this->Parola=Parola;
}

void ProtocolAmUitatParola::writeOnSocket(QTcpSocket *socket, DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}

bool searchUser(QString Email)
{
    QSqlQuery query;
    query.prepare("select UserID from Utilizatori where Email='"+Email+"'");
    query.exec();

    while(query.next())
    {
        return true;
    }
    return false;

}

void ProtocolAmUitatParola::createMessage()
{
    if(searchUser(this->Email))
    {
        QSqlQuery query2;
        if(query2.exec("update Utilizatori set Parola='"+Parola+"' where Email='"+Email+"'"))
        {
        qDebug()<<"Utilizatorul cu email-ul:"<<Email<<"si-a restat parola!";
        this->Message="7|1";
        }
    }
    else
    {
        qDebug()<<"Utilizatorul nu a restat parola!";
        this->Message="7|0";
    }
}
