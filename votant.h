#ifndef VOTANT_H
#define VOTANT_H

#include "user.h"

class Votant : public User
{
public:
    Votant(QString ip, int port, QString nume, QString prenume, QString password, QString mail, QString cnp);
    Votant(QString ip, int port);

    virtual ~Votant();
};

#endif // VOTANT_H
