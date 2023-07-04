#ifndef USER_H
#define USER_H

#include "iuser.h"

class User : public IUser
{
private:
    QTcpSocket *socket;
    QStringList lastResponseMsg;

    int id;
    QString nume;
    QString prenume;
    QString password;
    QString mail;
    QString cnp;
public:
    User(QString ip, int port, QString nume, QString prenume, QString password, QString mail, QString cnp);
    User(QString ip, int port);
    virtual ~User();

    void sendMsgToServer(QString msg);
    void setId(int id);
    void setNume(QString nume);
    void setPrenume(QString prenume);
    void setParola(QString parola);
    void setMail(QString mail);
    void setCNP(QString CNP);

    QString getNume();
    QString getPrenume();
    QString getEmail();
    QString getCNP();
    int getId();
    QString getPassword();
    QString getDate();

    QTcpSocket* getSocket();
    QStringList getLastMsg();
    QStringList getLongMsg();

signals:

public slots:
    void onReadyRead();
};

#endif // USER_H
