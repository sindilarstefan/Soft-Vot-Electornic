#ifndef CFACTORYPROTOCOL_H
#define CFACTORYPROTOCOL_H

#include "iprotocol.h"
#include "protocollist.h"
#include <QString>

class CFactoryProtocol
{

public:
    CFactoryProtocol();
    static IProtocol* createProtocol(QString Data,Protocol Name);
};

#endif // CFACTORYPROTOCOL_H
