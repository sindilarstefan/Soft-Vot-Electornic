#include "votant.h"

Votant::Votant(QString ip, int port, QString nume, QString prenume, QString password, QString mail, QString cnp) :
    User(ip, port, nume, prenume, password, mail, cnp)
{

}

Votant::Votant(QString ip, int port): User(ip, port)
{

}

Votant::~Votant()
{

}
