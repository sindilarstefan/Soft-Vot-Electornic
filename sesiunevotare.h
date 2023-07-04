#ifndef SESIUNEVOTARE_H
#define SESIUNEVOTARE_H

#include <QDialog>
#include <QVBoxLayout>
#include <QStatusBar>
#include "vot.h"

namespace Ui {
class SesiuneVotare;
}

class SesiuneVotare : public QDialog
{
    Q_OBJECT

public:
    explicit SesiuneVotare(QWidget *parent = nullptr);
    ~SesiuneVotare();

    void setSesiune(Vot *sesiune);
    void setStatusBar(QString text);

private:
    Ui::SesiuneVotare *ui;
    Vot *sesiune;
    QVBoxLayout *lay;
    QStatusBar *sb;
};

#endif // SESIUNEVOTARE_H
