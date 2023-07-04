#ifndef PROTOCOLLOGIN_H
#define PROTOCOLLOGIN_H

#include "cprotocol.h"

class ProtocolLogin : public CProtocol
{

public:
    ProtocolLogin(QString Email,QString Password);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();

private:
    QString Email, Password;

};

#endif // PROTOCOLLOGIN_H
