#include "register.h"
#include "ui_register.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    cont = nullptr;
    valid = true;
}

Register::~Register()
{
    if(cont != nullptr)
        delete cont;
    delete ui;
}

void Register::inregistrare()
{
    valid = true;

    if(ui->lineEdit_passward->text() != ui->lineEdit_pass_confirm->text())
    {
        valid = false;
        QMessageBox msg = QMessageBox();
        msg.setStyleSheet("background-color: rgb(255, 255, 255);");
        msg.setText("Parolele nu coresound!");
        msg.setWindowTitle("Register");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
    }
    if(ui->lineEdit_email->text().contains("|") || ui->lineEdit_email->text().contains("%") ||
       ui->lineEdit_nume->text().contains("|") || ui->lineEdit_nume->text().contains("%") ||
       ui->lineEdit_prenume->text().contains("|") || ui->lineEdit_prenume->text().contains("%") ||
       ui->lineEdit_passward->text().contains("|") || ui->lineEdit_passward->text().contains("%"))
    {
        valid = false;
        QMessageBox msg = QMessageBox();
        msg.setStyleSheet("background-color: rgb(255, 255, 255);");
        msg.setText("Nu se pot folosi caracterele | si % in inregistrare!");
        msg.setWindowTitle("Register");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
    }
    if(valid)
    {
        cont = new Votant("192.168.43.2", 1234, ui->lineEdit_nume->text(), ui->lineEdit_prenume->text(),
                          ui->lineEdit_passward->text(), ui->lineEdit_email->text(), ui->lineEdit_cnp->text() );

    }
}

void Register::on_pb_register_clicked()
{
    inregistrare();

    if(valid)
    {
        cont->sendMsgToServer(cont->getDate().toUtf8());
        QStringList m = cont->getLastMsg();
        if(m[1] == "1")
            close();
        else
        {
            QMessageBox msg = QMessageBox();
            msg.setStyleSheet("background-color: rgb(255, 255, 255);");
            msg.setText("Exista deja un cont pentru acest email!");
            msg.setWindowTitle("Register");
            msg.setIcon(QMessageBox::Warning);
            msg.exec();
        }
    }
}

