#ifndef PROTOCOLLOADSESIUNIACTIVE_H
#define PROTOCOLLOADSESIUNIACTIVE_H

#include "cprotocol.h"

class ProtocolLoadSesiuniActive : public CProtocol
{

public:
    ProtocolLoadSesiuniActive(QString Descript);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString Descript;
};

#endif // PROTOCOLLOADSESIUNIACTIVE_H
