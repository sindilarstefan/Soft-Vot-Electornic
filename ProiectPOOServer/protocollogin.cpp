#include "protocollogin.h"
#include "database.h"

ProtocolLogin::ProtocolLogin(QString Email,QString Password)
{
    this->Email=Email;
    this->Password=Password;
    //qDebug()<<Email<<Password;
}

bool searchUser(QString Email, QString Password)
{
    QSqlQuery query;
    query.prepare("select* from Utilizatori where Email='"+Email+"'and Parola='"+Password+"'");
    query.exec();

    while(query.next())
    {
        return true;
    }
    return false;

}
void ProtocolLogin::createMessage()
{
    QString IDq;
    QString Numeq, Prenumeq,CNPq;

    if(searchUser(this->Email,this->Password))
    {
        QSqlQuery query2;
        if(query2.exec("select UserID,Nume,Prenume,CNP from [Utilizatori] where Email='"+Email+"'")){
            while(query2.next()){
                IDq = query2.value(0).toString();
                Numeq = query2.value(1).toString();
                Prenumeq = query2.value(2).toString();
                CNPq = query2.value(3).toString();
            //qDebug()<<Email<<IDq<<Numeq<<Prenumeq<<CNPq;
            }
        }

        QString myString = "1|1|"+IDq+"|"+Numeq+"|"+Prenumeq+"|"+CNPq;
        qDebug()<<"Utilizatorul"<<Numeq<<Prenumeq<<"s-a logat!";
        this->Message=myString.toUtf8();
    }
    else
    {
        qDebug()<<"Utilizatorul nu a fost logat!";
        this->Message="1|0";
    }

}
void ProtocolLogin::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.ConnectDB();
    createMessage();
    db.destroyDatabase();
    socket->write(Message);
}
