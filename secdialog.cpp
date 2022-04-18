#include "secdialog.h"
#include "ui_secdialog.h"
#include "about.h"
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

