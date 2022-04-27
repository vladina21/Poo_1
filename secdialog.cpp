#include "secdialog.h"
#include "ui_secdialog.h"
#include "about.h"
#include "contact.h"
#include "events.h"
#include <QMessageBox>
secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_pushButton_clicked()
{
 About A;
    this->hide();
    A.setModal(true);
    A.exec();
}


void secDialog::on_pushButton_5_clicked()
{
    Contact C;
    this->hide();
    C.setModal(true);
    C.exec();
}


void secDialog::on_pushButton_2_clicked()
{
    Events E;
    this->hide();
    E.setModal(true);
    E.exec();
}

