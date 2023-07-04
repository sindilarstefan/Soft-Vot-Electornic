#ifndef SESIUNEVOT_H
#define SESIUNEVOT_H

#include <iostream>
#include <QLabel>
#include <QString>
#include <QVector>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QObject>
#include <QDebug>
#include "sesiunevotare.h"
#include "user.h"
#include "vot.h"

class SesiuneVot : public QObject
{
    QLabel* lb_descriere;
    QVBoxLayout *lay;
    User* user;
    QString descriere;
    Vot *sesiune;
    SesiuneVotare *s;
    int id;
    bool optiunui_adaugate;

public:
    SesiuneVot();
    ~SesiuneVot();

    void setDescriere(QString text);
    void setSesiuneActiva(int id, QString descriere, int nr_optiuni, QString data, QString status, int nr_opt_disponibile);
    void setSesiuneInactiva(int id, QString descriere, int nr_optiuni, QString data, QString status);
    void setFereastra(SesiuneVotare *s);
    void setUser(User *user);

    QVBoxLayout* getLayout();
    QString getDescriere();
    int getId();

private slots:
    void on_voteaza_acum_clicked();

};

#endif // SESIUNEVOT_H


