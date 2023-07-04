#ifndef PROTOCOLREGISTER_H
#define PROTOCOLREGISTER_H

#include "cprotocol.h"

class ProtocolRegister : public CProtocol
{

public:
    ProtocolRegister(QString Nume,QString Prenume, QString CNP, QString Email, QString Parola);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();

private:
    QString Nume;
    QString Prenume;
    QString CNP;
    QString Email;
    QString Parola;
};

#endif // PROTOCOLREGISTER_H
