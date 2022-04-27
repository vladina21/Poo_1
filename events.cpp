#include "events.h"
#include "ui_events.h"
#include "expozitii_si_evenimente.h"
#include "giorgio.h"
Events::Events(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Events)
{
    ui->setupUi(this);
}

Events::~Events()
{
    delete ui;
}

void Events::on_pushButton_2_clicked()
{
    Expozitii_si_evenimente EE;
    this->hide();
    EE.setModal(true);
    EE.exec();
}


void Events::on_pushButton_3_clicked()
{
    Giorgio G;
    this->hide();
    G.setModal(true);
    G.exec();

}

