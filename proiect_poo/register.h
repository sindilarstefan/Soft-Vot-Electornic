#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "user.h"
#include "votant.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void inregistrare();

private slots:
    void on_pb_register_clicked();
private:
    Ui::Register *ui;
    User *cont;
    bool valid;
};

#endif // REGISTER_H
