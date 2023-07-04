#ifndef PROTOCOLADAUGASESIUNE_H
#define PROTOCOLADAUGASESIUNE_H

#include "cprotocol.h"

class ProtocolAdaugaSesiune : public CProtocol
{

public:
    ProtocolAdaugaSesiune(QString Descriere, QString NrOptiuni, QString DataSesiune, QString Status, QString NrOptiuniDisponibile);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString Descriere, NrOptiuni, DataSesiune, Status, NrOptiuniDisponibile;
};

#endif // PROTOCOLADAUGASESIUNE_H
