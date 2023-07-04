#include "sesiunevot.h"

SesiuneVot::SesiuneVot()
{
    lay = new QVBoxLayout();
    s = nullptr;
    sesiune = nullptr;
    lb_descriere = nullptr;
    user = nullptr;
    this->optiunui_adaugate = false;
}

SesiuneVot::~SesiuneVot()
{
    if(lb_descriere != nullptr)
        delete lb_descriere;
    if(lay != nullptr)
        delete lay;
    if(user != nullptr)
        delete user;
    if(s != nullptr)
        delete s;
    if(sesiune != nullptr)
        delete sesiune;
}

void SesiuneVot::setDescriere(QString text)
{
    this->descriere = text;
}

QVBoxLayout *SesiuneVot::getLayout()
{
    return lay;
}

void SesiuneVot::setSesiuneActiva(int id, QString descriere, int nr_optiuni, QString data, QString status, int nr_opt_disponibile)
{
    this->id = id;
    this->descriere = descriere;
    sesiune = new Vot();
    sesiune->setId(id);
    sesiune->setDescriere(descriere);
    sesiune->setNrOptiuni(nr_optiuni);
    sesiune->setNrOtiunuiPosibile(nr_opt_disponibile);
    sesiune->setData(data);
    sesiune->setStatus(status);

    QString text = (QString::number(id) + "\t" + descriere);
    lb_descriere = new QLabel(text);
    lb_descriere->setFixedSize(950, 30);
    lb_descriere->setStyleSheet("background-color: #007459;border-radius: 10px;");

    lay->addWidget(lb_descriere);

    QPushButton *voteaza_acum = new QPushButton("Voteaza acum");
    voteaza_acum->setStyleSheet("QPushButton { background-color: gray;border-radius: 10px; } QPushButton:hover { background-color: #6c6c6c; border-radius: 10px;}");

    voteaza_acum->setFixedSize(950, 30);
    connect(voteaza_acum, &QPushButton::clicked, this, &SesiuneVot::on_voteaza_acum_clicked);
    lay->addWidget(voteaza_acum);
}

void SesiuneVot::setSesiuneInactiva(int id, QString descriere, int nr_optiuni, QString data, QString status)
{
    this->id = id;
    sesiune = new Vot();
    sesiune->setId(id);
    sesiune->setDescriere(descriere);
    sesiune->setNrOptiuni(nr_optiuni);
    sesiune->setData(data);
    sesiune->setStatus(status);

    QString text = (QString::number(id) + "\t" + descriere + "\t" + data);
    lb_descriere = new QLabel(text);
    lb_descriere->setFixedSize(950, 30);
    lb_descriere->setStyleSheet("background-color: #007459;border-radius: 10px;");
    lay->addWidget(lb_descriere);
}

void SesiuneVot::setFereastra(SesiuneVotare *s)
{
    this->s = s;
}

void SesiuneVot::setUser(User *user)
{
    this->user = user;
}

QString SesiuneVot::getDescriere()
{
    return this->descriere;
}

int SesiuneVot::getId()
{
    return this->id;
}

void SesiuneVot::on_voteaza_acum_clicked()
{
    qDebug() << "VOTEAZA ACUM!!!";

    if(!optiunui_adaugate)
    {
        sesiune->preiaUser(user);
        optiunui_adaugate = true;

        int _id_sesiune = sesiune->getId();
        QString msg = ("11|" + QString::number(_id_sesiune));
        user->sendMsgToServer(msg);
        QStringList res = user->getLongMsg();

        int j = res.length();
        int i = 0;
        {
            foreach(QString element, res)
            {
                if(i < (j - 1))
                {
                    i++;
                    QStringList lst = element.split("|");
                    if(lst[1] == "1")
                    {
                        sesiune->adaugaOptiune(lst[3], lst[2]);
                    }
                }
            }
        }
    }

    s->setSesiune(sesiune);
    sesiune->preiaStatus(s);
    s->show();
    s->raise();

}
