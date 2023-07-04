#ifndef MENIUPRINCIPAL_H
#define MENIUPRINCIPAL_H

#include <QScrollArea>
#include <QLabel>
#include <QDialog>
#include <QDebug>
#include <QVector>
#include <QVBoxLayout>
#include <QDate>
#include <QString>
#include <QPushButton>
#include "user.h"
#include "vot.h"
#include "mainwindow.h"
#include "datecont.h"
#include "sesiunevot.h"
#include "sesiunevotare.h"

class SesiuneVot;

// sesiune votare ceez aici si trimit

namespace Ui {
class MeniuPrincipal;
}

class MeniuPrincipal : public QDialog
{
    Q_OBJECT

public:
    explicit MeniuPrincipal(QWidget *parent = nullptr);
    ~MeniuPrincipal();

    void preiaUser(User* cont);
    MeniuPrincipal* getParinte();
    void setMeniuClient(bool set);


private slots:
    void on_pb_vActive_clicked();
    void on_pb_vInactive_pressed();
    void on_pb_profil_clicked();
    void on_pb_add_Vot_clicked();
    void on_pb_nr_opt_clicked();
    void on_pb_opt_clicked();
    void on_pb_login_clicked();
    void on_pb_cauta_clicked();
    void on_pushButton_clicked();
    void on_pb_activ_clicked();
    void on_pb_inactiv_clicked();

private:
    Ui::MeniuPrincipal *ui;
    User *cont;

    QVector<SesiuneVot*> sesiuni_active;
    QVector<SesiuneVot*> sesiuni_inactive;

    Vot *vot;
    int nr_opt;
    QString descriere;
    QString id_sesiune;
};

#endif // MENIUPRINCIPAL_H
