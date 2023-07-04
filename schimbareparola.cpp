#include "schimbareparola.h"
#include "ui_schimbareparola.h"

SchimbareParola::SchimbareParola(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SchimbareParola)
{
    ui->setupUi(this);
}

SchimbareParola::~SchimbareParola()
{
    delete ui;
}

void SchimbareParola::schimbaProla(QString mail)
{
    this->mail = mail;
}

void SchimbareParola::on_pb_reset_pass_clicked()
{
    this->new_pass = ui->lineEdit_new_passward->text();
    QString msg = (QString("7") + "|" + mail + "|" + new_pass);
    qDebug() << "SCHIMBARE PAROLA:" << mail << new_pass;

    User *user = new User("192.168.43.2", 1234);
    user->sendMsgToServer(msg);
    QStringList lst = user->getLastMsg();
    qDebug() << lst;
}

