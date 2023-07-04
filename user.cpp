#include "user.h"

User::User(QString ip, int port, QString nume, QString prenume, QString password, QString mail, QString cnp) :
    nume(nume), prenume(prenume), password(password), mail(mail), cnp(cnp)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ip,port);
    socket->waitForConnected();
}


User::User(QString ip, int port)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ip,port);
    socket->waitForConnected();
}


User::~User()
{
    id = -1;
    nume = "";
    prenume = "";
    password = "";
    mail = "";
    cnp = "";
}

void User::sendMsgToServer(QString msg)
{
    socket->write(msg.toUtf8());
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
}

void User::setId(int id)
{
    this->id = id;
}

void User::setNume(QString nume)
{
    this->nume = nume;
}

void User::setPrenume(QString prenume)
{
    this->prenume = prenume;
}

void User::setParola(QString parola)
{
    this->password = parola;
}

void User::setMail(QString mail)
{
    this->mail = mail;
}

void User::setCNP(QString CNP)
{
    this->cnp = CNP;
}

QString User::getNume()
{
    return QString(nume);
}

QString User::getPrenume()
{
    return QString(prenume);
}

QString User::getEmail()
{
    return QString(mail);
}

QString User::getCNP()
{
    return QString(cnp);
}

int User::getId()
{
    return this->id;
}

QString User::getPassword()
{
    return password;
}

QString User::getDate()
{
    return QString(QString("2") + "|" + nume + "|" + prenume + "|" + cnp + "|" + mail  + "|" + password);
}

QTcpSocket *User::getSocket()
{
    return socket;
}

QStringList User::getLastMsg()
{
    QByteArray Data = socket->readAll();
    lastResponseMsg = QString(Data).split("|");
    qDebug() << "S-a primit raspunsul: " << Data;
    return lastResponseMsg;
}

QStringList User::getLongMsg()
{
    QByteArray Data = socket->readAll();
    lastResponseMsg = QString(Data).split("%");
    qDebug() << "S-a primit raspunsul: " << Data;
    return lastResponseMsg;
}

void User::onReadyRead()
{
    QByteArray Data = socket->readAll();
    lastResponseMsg = QString(Data).split("|");
    qDebug() << "S-a primit raspunsul: "<<Data<<"\n";
}


