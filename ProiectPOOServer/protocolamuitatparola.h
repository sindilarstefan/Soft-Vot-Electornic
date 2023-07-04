#ifndef PROTOCOLAMUITATPAROLA_H
#define PROTOCOLAMUITATPAROLA_H

#include "cprotocol.h"

class ProtocolAmUitatParola : public CProtocol
{

public:
    ProtocolAmUitatParola(QString Email, QString Parola);
    virtual void writeOnSocket(QTcpSocket* socket, DataBase db);
    virtual void createMessage();

private:
    QString Email, Parola;

};

#endif // PROTOCOLAMUITATPAROLA_H
