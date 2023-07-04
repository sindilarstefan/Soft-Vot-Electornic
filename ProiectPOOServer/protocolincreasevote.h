#ifndef PROTOCOLINCREASEVOTE_H
#define PROTOCOLINCREASEVOTE_H

#include "cprotocol.h"

class ProtocolIncreaseVote: public CProtocol
{

public:
    ProtocolIncreaseVote(QString ID);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString ID;

};

#endif // PROTOCOLINCREASEVOTE_H
