#include "giorgio.h"
#include "ui_giorgio.h"

Giorgio::Giorgio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Giorgio)
{
    ui->setupUi(this);
}

Giorgio::~Giorgio()
{
    delete ui;
}
