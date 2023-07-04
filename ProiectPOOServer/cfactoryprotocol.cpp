#include "cfactoryprotocol.h"
#include "protocollogin.h"
#include "protocolregister.h"
#include "protocoladaugasesiune.h"
#include "protocoladaugaoptiune.h"
#include "protocolloadsesiuniactive.h"
#include "protocolloadsesiuniinactive.h"
#include "protocolamuitatparola.h"
#include "protocolcautaresesiune.h"
#include "protocolgenereazarezultat.h"
#include "protocolincreasevote.h"
#include "protocolgenereazaoptiuni.h"
#include "protocolsetsesiuneactiv.h"
#include "protocolsetsesiuneinactiv.h"

CFactoryProtocol::CFactoryProtocol()
{

}

 IProtocol* CFactoryProtocol::createProtocol(QString Data,Protocol Name)
{
     QStringList dataList= QString(Data).split('|');

    if(Name==Login)
        return new ProtocolLogin(dataList.value(1),dataList.value(2));

    if(Name==Register)
        return new ProtocolRegister(dataList.value(1),dataList.value(2),dataList.value(3),dataList.value(4),dataList.value(5));

    if(Name==AdaugaSesiune)
        return new ProtocolAdaugaSesiune(dataList.value(1), dataList.value(2), dataList.value(3), dataList.value(4), dataList.value(5));

    if(Name==AdaugaOptiune)
        return new ProtocolAdaugaOptiune(dataList.value(1), dataList.value(2));

    if(Name==LoadSesiuniActive)
        return new ProtocolLoadSesiuniActive(dataList.value(1));

    if(Name==LoadSesiuniInactive)
        return new ProtocolLoadSesiuniInactive(dataList.value(1));

    if(Name==AmUitatParola)
        return new ProtocolAmUitatParola(dataList.value(1), dataList.value(2));

    if(Name==CautareSesiune)
        return new ProtocolCautareSesiune(dataList.value(1));

    if(Name==GenereazaRezultat)
        return new ProtocolGenereazaRezultat(dataList.value(1));

    if(Name==IncreaseVote)
        return new ProtocolIncreaseVote(dataList.value(1));

    if(Name==GenereazaOptiuni)
        return new ProtocolGenereazaOptiuni(dataList.value(1));

    if(Name==SetSesiuneActiv)
        return new ProtocolSetSesiuneActiv(dataList.value(1));

    if(Name==SetSesiuneInactiv)
        return new ProtocolSetSesiuneInactiv(dataList.value(1));

    return NULL;
}
