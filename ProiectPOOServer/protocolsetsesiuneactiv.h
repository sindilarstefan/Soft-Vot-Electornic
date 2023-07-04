#ifndef PROTOCOLSETSESIUNEACTIV_H
#define PROTOCOLSETSESIUNEACTIV_H

#include "cprotocol.h"

class ProtocolSetSesiuneActiv: public CProtocol
{

public:
    ProtocolSetSesiuneActiv(QString IDSes);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();

private:
    QString IDSes;
};

#endif // PROTOCOLSETSESIUNEACTIV_H
