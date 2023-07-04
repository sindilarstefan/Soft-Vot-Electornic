#include "meniuprincipal.h"
#include "ui_meniuprincipal.h"

MeniuPrincipal::MeniuPrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MeniuPrincipal)
{
    ui->setupUi(this);
    cont = nullptr;
    vot = nullptr;

    ui->label_admin_mode->hide();
    ui->widget_vot->hide();
}

MeniuPrincipal::~MeniuPrincipal()
{
    if(cont != nullptr)
        delete cont;
    if(vot != nullptr)
        delete vot;
    delete ui;
}

void MeniuPrincipal::preiaUser(User *cont)
{
    this->cont = cont;
}

MeniuPrincipal *MeniuPrincipal::getParinte()
{
    return this;
}

void MeniuPrincipal::on_pb_vActive_clicked()
{
    QVBoxLayout *lay = new QVBoxLayout(this);

    QLabel* info = new QLabel("ID\tDescriere");
    info->setFixedSize(950, 30);
    info->setStyleSheet("background-color: #004d3b;border-radius: 10px;");
    lay->addWidget(info);
    lay->addSpacing(30);

    QString msg = "5|getSesiuniActive";
    cont->sendMsgToServer(msg);
    QStringList res = cont->getLongMsg();
    int j = res.length();
    int i = 0;
    foreach(QString element, res)
    {
        if(i < (j - 1))
        {
            i++;
            QStringList lst = element.split("|");
            if(lst[1] == "1")
            {
                qDebug() << "Sesiune Vot:" << lst[2].toInt() << lst[3] << lst[4].toInt() << lst[5] << lst[6] << lst[7];
                SesiuneVot *sv = new SesiuneVot();
                sv->setUser(cont);
                SesiuneVotare *s = new SesiuneVotare(this);
                sv->setFereastra(s);
                sv->setDescriere(lst[3]);
                sv->setSesiuneActiva(lst[2].toInt(), lst[3], lst[4].toInt(), lst[5], lst[6], lst[7].toInt());
                lay->addLayout(sv->getLayout());
                lay->addSpacing(30);
                sesiuni_active.push_back(sv);
            }
            else
            {
                qDebug() << "Eroare: " << lst[0] << "\t" << lst[1];
            }
        }
    }

    QScrollArea* scrollArea = new QScrollArea(this);
    QWidget* scrollAreaWidgetContentss = new QWidget();
    scrollArea->setGeometry(200, 60, 1000, 540);
    scrollAreaWidgetContentss->setLayout(lay);
    scrollArea->setWidget(scrollAreaWidgetContentss);
    scrollArea->show();
    scrollArea->raise();

}

void MeniuPrincipal::on_pb_vInactive_pressed()
{
    QVBoxLayout *lay = new QVBoxLayout(this);

    QString msg = "6|getSesiuniInactive";
    cont->sendMsgToServer(msg);
    QStringList res = cont->getLongMsg();

    QLabel* info = new QLabel("ID\tDescriere\t\tData");
    info->setFixedSize(950, 30);
    info->setStyleSheet("background-color: #004d3b;border-radius: 10px;");
    lay->addWidget(info);
    lay->addSpacing(20);

    int j = res.length();
    int i = 0;
    foreach(QString element, res)
    {
        if(i < (j - 1))
        {
            i++;
            QStringList lst = element.split("|");
            if(lst[1] == "1")
            {
                qDebug() << "Sesiune Vot:" << lst[2].toInt() << lst[3] << lst[4].toInt() << lst[5] << lst[6];
                SesiuneVot *sv = new SesiuneVot();
                SesiuneVotare *s = new SesiuneVotare(this);
                sv->setFereastra(s);
                sv->setDescriere(lst[3]);
                sv->setSesiuneInactiva(lst[2].toInt(), lst[3], lst[4].toInt(), lst[5], lst[6]);
                lay->addLayout(sv->getLayout());
                lay->addSpacing(20);
                sesiuni_inactive.push_back(sv);
            }
            else
                {
                    qDebug() << "Eroare: " << lst[0] << "\t" << lst[1];
                }

        }
    }
    QScrollArea* scrollArea = new QScrollArea(this);
    QWidget* scrollAreaWidgetContents = new QWidget();
    scrollArea->setGeometry(200, 60, 1000, 540);

    scrollAreaWidgetContents->setLayout(lay);
    scrollArea->setWidget(scrollAreaWidgetContents);
    scrollArea->show();
    scrollArea->raise();
}

void MeniuPrincipal::on_pb_profil_clicked()
{
    DateCont *date_cont = new DateCont(this);
    date_cont->afiseazaDate(cont->getNume(), cont->getPrenume(), cont->getEmail(), cont->getCNP());
    date_cont->show();
}

void MeniuPrincipal::on_pb_add_Vot_clicked()
{
    ui->widget_vot->show();
    vot = new Vot();
}

void MeniuPrincipal::on_pb_nr_opt_clicked()
{
    QString _descriere = ui->lineEdit_descriere->text();
    QString _nr_opt = ui->lineEdit_nr_opt->text();
    QString _status = ui->lineEdit_status->text();

    QString _nr_opt_disponibile = ui->lineEdit_nr_opt_disponibile->text();
    this->nr_opt = _nr_opt.toInt();
    vot->setNrOptiuni(this->nr_opt);
    vot->setDescriere(_descriere);
    vot->setNrOtiunuiPosibile(_nr_opt_disponibile.toInt());

    QDate currentDate = QDate::currentDate();
    QString data = currentDate.toString("yyyy-MM-dd");

    QString msg = QString(QString("3") + "|" + _descriere + "|" + _nr_opt + "|" + data + "|" + _status + "|" + _nr_opt_disponibile);
    cont->sendMsgToServer(msg);
    QStringList res = cont->getLastMsg();
    qDebug() << res;
    id_sesiune = res[2];
}

void MeniuPrincipal::on_pb_opt_clicked()
{
    QString opt = ui->lineEdit_opt->text();
    if(nr_opt)
    {
        vot->adaugaOptiune(opt, "");
        nr_opt--;

        QString msg = QString(QString("4") + "|" + QString(id_sesiune) + "|" + opt);
        cont->sendMsgToServer(msg);
        cont->getLastMsg();
    }
}


void MeniuPrincipal::on_pb_login_clicked()
{
    MainWindow *login = new MainWindow();
    login->show();
    close();
}


void MeniuPrincipal::on_pb_cauta_clicked()
{
    QVBoxLayout *lay_search= new QVBoxLayout(this);
    QString text_cautat = ui->lineEdit_cauta->text();

    QString msg = "8|" + text_cautat;
    cont->sendMsgToServer(msg);
    QStringList res = cont->getLongMsg();

    int j = res.length();
    int i = 0;
    foreach(QString element, res)
    {
        if(i < (j - 1))
        {
            i++;
            QStringList lst = element.split("|");
            if(lst[1] == "1")
            {
                qDebug() << "Sesiune Vot Cautata:" << lst[2].toInt() << lst[3] << lst[4].toInt() << lst[5] << lst[6] << lst[7];
                SesiuneVot *sv = new SesiuneVot();
                sv->setUser(cont);
                SesiuneVotare *s = new SesiuneVotare(this);
                sv->setFereastra(s);
                sv->setDescriere(lst[3]);
                sv->setSesiuneActiva(lst[2].toInt(), lst[3], lst[4].toInt(), lst[5], lst[6], lst[7].toInt());
                lay_search->addLayout(sv->getLayout());
                lay_search->addSpacing(30);
            }
            else
            {
                qDebug() << "Eroare: " << lst[0] << "\t" << lst[1];
            }
        }
    }
    QScrollArea* scrollArea = new QScrollArea(this);
    QWidget* scrollAreaWidgetContents = new QWidget();
    scrollArea->setGeometry(200, 60, 1000, 540);

    scrollAreaWidgetContents->setLayout(lay_search);
    scrollArea->setWidget(scrollAreaWidgetContents);
    scrollArea->show();
    scrollArea->raise();   
}


void MeniuPrincipal::on_pushButton_clicked()
{
    QVBoxLayout *lay = new QVBoxLayout(this);

    QString _id = ui->lineEdit_genereaza->text();

    QString msg = ( "9|" + _id );
    cont->sendMsgToServer(msg);
    QStringList res = cont->getLongMsg();

    int j = res.length();
    int i = 0;
    QLabel* info = new QLabel("ID\tDescriere\tNumar Voturi");
    info->setFixedSize(950, 30);
    info->setStyleSheet("background-color: #004d3b;border-radius: 10px;");
    lay->addWidget(info);
    lay->addSpacing(20);

    foreach(QString element, res)
    {
        if(i < (j - 1))
        {
            i++;
            QStringList lst = element.split("|");
            if(lst[1] == "1")
            {
                qDebug() << "AFISARE Sesiune Vot:" << lst[2].toInt() << lst[3] << lst[4].toInt();
                QString  _date = ( lst[2] + "\t" + lst[3] + "\t\t" + lst[4]);
                QLabel* lb_des = new QLabel(_date);
                lb_des->setFixedSize(950, 30);
                lb_des->setStyleSheet("background-color: #007459;border-radius: 10px;");
                lay->addWidget(lb_des);
                lay->addSpacing(20);
            }
            else
            {
                qDebug() << "Eroare: " << lst[0] << "\t" << lst[1];
            }
        }
    }

    QScrollArea* scrollArea = new QScrollArea(this);
    QWidget* scrollAreaWidgetContents = new QWidget();
    scrollArea->setGeometry(200, 60, 1000, 540);

    scrollAreaWidgetContents->setLayout(lay);
    scrollArea->setWidget(scrollAreaWidgetContents);
    scrollArea->show();
    scrollArea->raise();
}

void MeniuPrincipal::on_pb_activ_clicked()
{
    QString _id = ui->lineEdit_id->text();
    QString msg = ( "12|" + _id );
    cont->sendMsgToServer(msg);
    cont->getLongMsg();
}


void MeniuPrincipal::on_pb_inactiv_clicked()
{
    QString _id = ui->lineEdit_id->text();
    QString msg = ( "13|" + _id );
    cont->sendMsgToServer(msg);
    cont->getLongMsg();
}

void MeniuPrincipal::setMeniuClient(bool set)
{
    if(set)
    {
        ui->pb_add_Vot->hide();
        ui->label_admin_mode->hide();
    }
    else
        ui->label_admin_mode->show();
}
