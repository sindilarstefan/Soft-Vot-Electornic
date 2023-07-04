#include "datecont.h"
#include "ui_datecont.h"

DateCont::DateCont(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateCont)
{
    ui->setupUi(this);
}

DateCont::~DateCont()
{
    delete ui;
}

void DateCont::afiseazaDate(QString nume, QString prenume, QString email, QString cnp)
{
    ui->label_nume->setText(nume);
    ui->label_prenume->setText(prenume);
    ui->label_email->setText(email);
    ui->label_cnp->setText(cnp);
}

void DateCont::on_pb_contct_clicked()
{
    QLabel* lb = new QLabel(this);
    lb->setGeometry(10, 10, 580, 380);
    lb->setStyleSheet("background-image:url(:/imagini/Imagini/bg_2.jpg);color:#DDDDDD;border-radius: 10px; text-align: center; position: absolute; top: 50%; left: 50%; font: 20pt \"Modern No. 20\";");
    lb->setText("\t\tCOLTAN Cristian\n\t\tSINDILAR Stefan");
    lb->show();
}

