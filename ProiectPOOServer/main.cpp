#include <QCoreApplication>
#include "server.h"
#include "database.h"
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //DataBase db =  DataBase::getInstance();
    //db.ConnectDB();

    Server::getServer().StartServer();

    return a.exec();
}
