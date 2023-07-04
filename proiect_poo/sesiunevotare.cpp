#include "sesiunevotare.h"
#include "ui_sesiunevotare.h"

SesiuneVotare::SesiuneVotare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SesiuneVotare)
{
    ui->setupUi(this);
    sesiune = nullptr;
    lay = nullptr;
    sb = nullptr;
}

SesiuneVotare::~SesiuneVotare()
{
    if(sesiune != nullptr)
        delete sesiune;
    if(lay != nullptr)
        delete lay;
    if(sb != nullptr)
        delete sb;
    delete ui;
}

void SesiuneVotare::setSesiune(Vot *sesiune)
{
    this->sesiune = sesiune;
    ui->scrollAreaWidgetContents->setLayout(sesiune->getLayout());
    ui->scrollArea->show();
    sb = new QStatusBar(this);
    sb->setGeometry(0, 380, 400, 20);
    sb->show();
}

void SesiuneVotare::setStatusBar(QString text)
{
    if(sb != nullptr)
        sb->showMessage(text);
}
