#include "firstpage.h"
#include "ui_firstpage.h"
#include <QMessageBox>

firstPage::firstPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstPage)
{
    ui->setupUi(this);
}

firstPage::~firstPage()
{
    delete ui;
}

void firstPage::on_pushButton_login_clicked()
{
    QString nom = ui->lineEdit_Nom->text();
    QString mdp = ui->lineEdit_mdp->text();

    if(nom == "smartPaladeya" && mdp == "test")
    {
        QMessageBox::information(this, "login", "Connexion avec succes");
        hide();
        mainwindow = new MainWindow(this);
        mainwindow->show();

    }
    else {
        QMessageBox::warning(this, "login", "connextion echouer");
    }
}
