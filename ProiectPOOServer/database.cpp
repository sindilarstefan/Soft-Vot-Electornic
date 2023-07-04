#include "database.h"
#include <QtCore>
#include<QCoreApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DataBase *DataBase::instance=nullptr;

DataBase &DataBase::getInstance()
{
    if(!instance)
        instance=new DataBase();
    return *instance;
}

void DataBase::destroyDatabase()
{
    instance->db.close();
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
    QSqlDatabase::removeDatabase(instance->db.connectionName());
    if(instance)
    {
        delete instance;
        instance=nullptr;
    }
    qDebug()<<"Baza de date deconectata!";
}

DataBase::DataBase()
{

}

void DataBase::ConnectDB()
{
      QSqlDatabase db1 = QSqlDatabase::addDatabase("QODBC");//QODBC

      db1.setConnectOptions(/*"MYSQL_OPT_RECONNECT=1"*/);
      QString dsn=QString("DRIVER={SQL SERVER};SERVER=COLTAN;DATABASE=Vote;UID=crist;PWD=;Trusted_Connection=Yes");

      db1.setDatabaseName(dsn);

      db1.open();
}
