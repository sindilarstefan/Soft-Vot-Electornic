#include "admin.h"

Admin::Admin(QString ip, int port, QString nume, QString prenume, QString password, QString mail, QString cnp) :
    User(ip, port, nume, prenume, password, mail, cnp)
{
    this->admin = true;
}

Admin::Admin(QString ip, int port): User(ip, port)
{
    this->admin = true;
}

Admin::~Admin()
{

}

bool Admin::verifAdmin()
{
    return this->admin;
}
