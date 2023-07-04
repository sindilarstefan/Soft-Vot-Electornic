#ifndef PROTOCOLCAUTARESESIUNE_H
#define PROTOCOLCAUTARESESIUNE_H

#include "cprotocol.h"

class ProtocolCautareSesiune : public CProtocol
{

public:
    ProtocolCautareSesiune(QString DescriereSes);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString DescriereSes;
};

#endif // PROTOCOLCAUTARESESIUNE_H
