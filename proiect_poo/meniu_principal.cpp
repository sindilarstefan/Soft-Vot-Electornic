#include "meniu_principal.h"
#include "ui_meniu_principal.h"

meniu_principal::meniu_principal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meniu_principal)
{
    ui->setupUi(this);
}

meniu_principal::~meniu_principal()
{
    delete ui;
}
