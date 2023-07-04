#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include "register.h"
#include "meniuprincipal.h"
#include "user.h"
#include "votant.h"
#include "admin.h"
#include "schimbareparola.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_register_clicked();
    void on_pb_login_clicked();
    void on_pb_fg_password_clicked();

private:
    Ui::MainWindow *ui;
    QString email;
    QString parola;
};
#endif // MAINWINDOW_H
