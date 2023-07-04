#ifndef IUSER_H
#define IUSER_H

#include <iostream>
#include <string>
#include <QString>
#include <QObject>
#include <QTcpSocket>
#include <QFile>
#include <QFileInfo>

class IUser : public QObject
{      
public:
    virtual QTcpSocket* getSocket() = 0;
    virtual QStringList getLastMsg() = 0;
    virtual QStringList getLongMsg() = 0;
    virtual void sendMsgToServer(QString msg) = 0;
};

#endif // IUSER_H
