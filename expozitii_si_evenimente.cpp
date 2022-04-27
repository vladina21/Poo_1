#include "expozitii_si_evenimente.h"
#include "ui_expozitii_si_evenimente.h"

Expozitii_si_evenimente::Expozitii_si_evenimente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Expozitii_si_evenimente)
{
    ui->setupUi(this);
}

Expozitii_si_evenimente::~Expozitii_si_evenimente()
{
    delete ui;
}
