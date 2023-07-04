#ifndef CONFIRMAREVOT_H
#define CONFIRMAREVOT_H

#include <QDialog>

namespace Ui {
class ConfirmareVot;
}

class ConfirmareVot : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmareVot(QWidget *parent = nullptr);
    ~ConfirmareVot();

private:
    Ui::ConfirmareVot *ui;
};

#endif // CONFIRMAREVOT_H
