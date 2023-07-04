#include "vot.h"
#include "sesiunevotare.h"

Vot::Vot()
{
    voteaza_acum = nullptr;
    lay = new QVBoxLayout();
    this->status_bar = "";

    descriere = nullptr;
    s = nullptr;
    user = nullptr;
}

Vot::~Vot()
{
    if(voteaza_acum != nullptr)
        delete voteaza_acum;
    if(lay != nullptr)
        delete lay;
    if(descriere != nullptr)
        delete descriere;
    if(s != nullptr)
        delete s;
    if(user != nullptr)
        delete user;
}

void Vot::preiaUser(User *user)
{
    this->user = user;
}

void Vot::setId(int id)
{
    this->id = id;
}

void Vot::setDescriere(QString text)
{
    this->descriere_text = text;
    descriere = new QLabel(text);
    lay->addWidget(descriere);
}

void Vot::setNrOptiuni(int nr)
{
    nr_optiunui = nr;
    for(int i = 0; i < nr; i++)
        stat[i] = 0;
}

void Vot::setNrOtiunuiPosibile(int nr)
{
    this->nr_optiunui_posibile = nr;
}

void Vot::setData(QString data)
{
    this->data = data;
}

void Vot::setStatus(QString status)
{
    this->status = status;
}

void Vot::adaugaOptiune(QString optiune, QString id_optiune)
{
    desc_idOpt.insert(optiune, id_optiune);
    optiuni_votate.insert(optiune, false);
    QPushButton *opt = new QPushButton(optiune);
    opt->setStyleSheet("QPushButton { background-color: gray;border-radius: 4px; } QPushButton:hover { background-color: #6c6c6c; border-radius: 4px;}");
    connect(opt, &QPushButton::clicked, this, &Vot::on_pb_opt_clicked);
    optiunui.push_back(opt);
    lay->addWidget(opt);
}

void Vot::preiaStatus(SesiuneVotare *s)
{
    this->s = s;
    if(nr_optiunui_posibile > 1)
        s->setStatusBar("Vot multiplu. Optiunui: " + QString::number(nr_optiunui_posibile));
    else
        s->setStatusBar("Vot simplu. Optiunui: " + QString::number(nr_optiunui_posibile));
}

QVBoxLayout *Vot::getLayout()
{
    return lay;
}

QString Vot::getDescriere()
{
    return this->descriere_text;
}

QString Vot::getStatusBar()
{
    return this->status_bar;
}

int Vot::getNrOptiunui()
{
    return nr_optiunui;
}

int Vot::getId()
{
    return this->id;
}

void Vot::on_pb_opt_clicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString _descriere = clickedButton->text();
    qDebug() << "S-a apasat optiunea" << _descriere;
    QString _id_optiune;
    QString value;

    QMap<QString, QString>::const_iterator iter;
    for (iter = desc_idOpt.constBegin(); iter != desc_idOpt.constEnd(); ++iter)
    {
        QString key = iter.key();
        value = iter.value();
        if(key == _descriere)
        {
            _id_optiune = value;
        }
    }

    bool logic = false;
    QMap<QString, bool>::iterator it;

    for (it = optiuni_votate.begin(); it != optiuni_votate.end(); ++it)
    {
        if(it.key() == _descriere && it.value() == true)
        {
            logic = true;
        }

        if(it.key() == _descriere && it.value() == false && nr_optiunui_posibile > 0)
        {
            nr_optiunui_posibile--;
            s->setStatusBar("Optiuni: " + QString::number(nr_optiunui_posibile));

            it.value() = true;
            QString msg = ("10|" + _id_optiune + "|" + QString::number(id));
            user->sendMsgToServer(msg);
            user->getLastMsg();
            qDebug() << "MSG optiune votata:" << msg;
            clickedButton->setStyleSheet("background-color: red;");
        }
    }

    if(logic)
    {
        qDebug() << "Optiunea a fost votata deja";
        status_bar = ("Optiunea a fost votata deja. \t\t Optiuni: " + QString::number(nr_optiunui_posibile));
        s->setStatusBar(status_bar);
    }
}
