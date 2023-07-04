#ifndef PROTOCOLADAUGAOPTIUNE_H
#define PROTOCOLADAUGAOPTIUNE_H

#include "cprotocol.h"

class ProtocolAdaugaOptiune: public CProtocol
{

public:
    ProtocolAdaugaOptiune(QString IDSesiune, QString DescriereOpt);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    int IDSesiune;
    QString DescriereOpt;
    int NrVoturi;
};

#endif // PROTOCOLADAUGAOPTIUNE_H
