#ifndef CPROTOCOL_H
#define CPROTOCOL_H

#include "iprotocol.h"

class CProtocol : public IProtocol
{

public:
    CProtocol();
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db)=0;
    virtual void createMessage()=0;

protected:
    QByteArray Message;
};

#endif // CPROTOCOL_H
