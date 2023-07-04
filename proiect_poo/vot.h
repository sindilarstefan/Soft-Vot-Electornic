#ifndef VOT_H
#define VOT_H

#include <iostream>
#include <QLabel>
#include <QString>
#include <QVector>
#include <QMap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QObject>
#include <QMessageBox>
#include "user.h"

class SesiuneVotare;

class Vot : public QObject
{

private:
    QMap<QString, QString> desc_idOpt;
    QMap<QString, bool> optiuni_votate;
    QVector<QPushButton*> optiunui;
    QPushButton *voteaza_acum;
    QVBoxLayout *lay;
    QLabel *descriere;
    SesiuneVotare *s;
    QString descriere_text;
    QString data;
    QString status;
    QString status_bar;
    User *user;
    int nr_optiunui;
    int nr_optiunui_posibile;
    int id;
    int stat[10];

public:
    Vot();
    ~Vot();

    void preiaUser(User* user);
    void setId(int id);
    void setDescriere(QString text);
    void setNrOptiuni(int nr);
    void setNrOtiunuiPosibile(int nr);
    void setData(QString data);
    void setStatus(QString status);
    void adaugaOptiune(QString optiune, QString id_optiune);
    void preiaStatus(SesiuneVotare* s);

    QVBoxLayout* getLayout();
    QString getDescriere();
    QString getStatusBar();
    int getNrOptiunui();
    int getId();

private slots:
    void on_pb_opt_clicked();
};

#endif // VOT_H
