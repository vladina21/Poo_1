#include "meniuadministrator.h"
#include "ui_meniuadministrator.h"

meniuadministrator::meniuadministrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meniuadministrator)
{
    ui->setupUi(this);
}

meniuadministrator::~meniuadministrator()
{
    delete ui;
}
