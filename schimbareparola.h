#ifndef SCHIMBAREPAROLA_H
#define SCHIMBAREPAROLA_H

#include <QDialog>
#include <QString>
#include "user.h"

namespace Ui {
class SchimbareParola;
}

class SchimbareParola : public QDialog
{
    Q_OBJECT

public:
    explicit SchimbareParola(QWidget *parent = nullptr);
    ~SchimbareParola();
    void schimbaProla(QString mail);
private slots:
    void on_pb_reset_pass_clicked();
private:
    Ui::SchimbareParola *ui;
    QString mail;
    QString new_pass;
};

#endif // SCHIMBAREPAROLA_H
