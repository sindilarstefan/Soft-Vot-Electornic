#ifndef MENIU_PRINCIPAL_H
#define MENIU_PRINCIPAL_H

#include <QDialog>

namespace Ui {
class meniu_principal;
}

class meniu_principal : public QDialog
{
    Q_OBJECT

public:
    explicit meniu_principal(QWidget *parent = nullptr);
    ~meniu_principal();

private:
    Ui::meniu_principal *ui;
};

#endif // MENIU_PRINCIPAL_H
