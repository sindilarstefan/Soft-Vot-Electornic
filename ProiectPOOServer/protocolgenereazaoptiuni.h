#ifndef PROTOCOLGENEREAZAOPTIUNI_H
#define PROTOCOLGENEREAZAOPTIUNI_H

#include "cprotocol.h"

class ProtocolGenereazaOptiuni: public CProtocol
{

public:
    ProtocolGenereazaOptiuni(QString IDSes);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString IDSes;
};

#endif // PROTOCOLGENEREAZAOPTIUNI_H
