#ifndef PROTOCOLSETSESIUNEINACTIV_H
#define PROTOCOLSETSESIUNEINACTIV_H

#include "cprotocol.h"

class ProtocolSetSesiuneInactiv: public CProtocol
{

public:
    ProtocolSetSesiuneInactiv(QString IDSes);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();

private:
    QString IDSes;
};

#endif // PROTOCOLSETSESIUNEINACTIV_H
