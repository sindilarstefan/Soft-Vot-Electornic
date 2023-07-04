#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin : public User
{
    bool admin;
public:
    Admin(QString ip, int port, QString nume, QString prenume, QString password, QString mail, QString cnp);
    Admin(QString ip, int port);
    virtual ~Admin();

    bool verifAdmin();
};

#endif // ADMIN_H
