#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "secdialog.h"
#include "meniuadministrator.h"
#include "register.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username =ui->lineEdit_username->text();
    QString password =ui->lineEdit_password->text();

    if(username== "user" && password=="user")
    {

       secDialog secdialog;
        this->hide();
       secdialog.setModal(true);
       secdialog.exec();
    }
    else if(username== "admin" && password=="admin")
    {
        meniuadministrator Meniuadm;
        this->hide();
        Meniuadm.setModal(true);
        Meniuadm.exec();

    }
    else {
        QMessageBox::critical(this,"Login","Username and password are not correct\nTry again...");


    }
}



void MainWindow::on_pushButton_register_clicked()
{
      Register register1;
      this->hide();
      register1.setModal(true);
      register1.exec();
}

