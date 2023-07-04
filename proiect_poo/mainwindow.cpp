#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_register_clicked()
{
    Register *reg = new Register(this);
    reg->show();
}

void MainWindow::on_pb_login_clicked()
{
    email = ui->lineEdit_email->text();
    parola = ui->lineEdit_passward->text();
    MeniuPrincipal *meniu = new MeniuPrincipal(this);

    User *user = nullptr;
    email = ui->lineEdit_email->text();
    parola = ui->lineEdit_passward->text();
    if(email == "admin" && parola == "admin")
    {
        user = new Admin("192.168.43.2", 1234);

        Admin *admin = static_cast<Admin*>(user);
        meniu->setMeniuClient(!admin->verifAdmin());
    }
    else
    {
        user = new Votant("192.168.43.2", 1234);
        meniu->setMeniuClient(true);
    }

    QString msg = QString(QString("1") + "|" + email  + "|" + parola);
    user->sendMsgToServer(msg);
    QStringList lst = user->getLastMsg();

    if(!lst.isEmpty())
    {
        if(lst[1] == "1" && lst[0] != "")
        {
            user->setId(lst[2].toInt());
            user->setNume(lst[3]);
            user->setPrenume(lst[4]);
            user->setCNP(lst[5]);
            user->setMail(email);
            user->setParola(parola);

            meniu->preiaUser(user);

            hide();
            meniu->show();
        }
        else
            QMessageBox::warning(this, "Login", "Date invalide!");
    }
}

#include <QMessageBox>
void MainWindow::on_pb_fg_password_clicked()
{
    SchimbareParola *sp = new SchimbareParola(this);
    sp->schimbaProla(ui->lineEdit_email->text());
    sp->show();
}

