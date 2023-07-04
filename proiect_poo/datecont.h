#ifndef DATECONT_H
#define DATECONT_H

#include <QDialog>
#include <QString>
#include <QLabel>

namespace Ui {
class DateCont;
}

class DateCont : public QDialog
{
    Q_OBJECT

public:
    explicit DateCont(QWidget *parent = nullptr);
    ~DateCont();

    void afiseazaDate(QString nume, QString prenume, QString email, QString cnp);

private slots:
    void on_pb_contct_clicked();

private:
    Ui::DateCont *ui;
};

#endif // DATECONT_H
