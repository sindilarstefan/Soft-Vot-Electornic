#ifndef PROTOCOLLOADSESIUNIINACTIVE_H
#define PROTOCOLLOADSESIUNIINACTIVE_H

#include "cprotocol.h"

class ProtocolLoadSesiuniInactive : public CProtocol
{

public:
    ProtocolLoadSesiuniInactive(QString Descript);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString Descript;
};

#endif // PROTOCOLLOADSESIUNIINACTIVE_H
