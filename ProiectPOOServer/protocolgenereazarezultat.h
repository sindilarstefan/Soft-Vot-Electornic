#ifndef PROTOCOLGENEREAZAREZULTAT_H
#define PROTOCOLGENEREAZAREZULTAT_H

#include "cprotocol.h"

class ProtocolGenereazaRezultat: public CProtocol
{

public:
    ProtocolGenereazaRezultat(QString ID);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString ID;
};

#endif // PROTOCOLGENEREAZAREZULTAT_H
