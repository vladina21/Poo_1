#include "register.h"
#include "ui_register.h"
#include "secdialog.h"
#include <QMessageBox>
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}



void Register::on_pushButton_submit_clicked()
{
    QString username =ui->lineEdit_username->text();
    QString password =ui->lineEdit_password->text();
    QString email =ui->lineEdit_email->text();
    QString confirmpassword =ui->lineEdit_confirmpassword->text();

    if(password==confirmpassword)
    {

       secDialog secdialog;
        this->hide();
       secdialog.setModal(true);
       secdialog.exec();
    }
    else {
        QMessageBox::critical(this,"Login","Passwords do not match\nTry again...");


    }
}

