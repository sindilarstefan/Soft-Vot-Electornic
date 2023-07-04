#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(qintptr ID, QObject *parent = nullptr) : QThread(parent){
        this->socketDescriptor = ID;
    }
    void run();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;

signals:

public slots:
    void readyRead();
    void disconnected();
};

#endif // THREAD_H
