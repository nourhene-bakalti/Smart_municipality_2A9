#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projets.h"
#include "operations.h"
#include <QPushButton>
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


void MainWindow::on_BoutonAjouter_clicked()
{
    int NumProjet=ui->le_NumProjet->text().toInt();
    int Budget=ui->le_budget->text().toInt();
    int DateDebut=ui->la_DateDebut->text().toInt();
    int DateFin=ui->la_DateFin->text().toInt();

    QString NomProjet=ui->le_NomProjet->text();
    QString DirecteurProjet=ui->Le_DirecteurProjet->text();
    QString Lieu=ui->le_lieu->currentText();


    projets P(NumProjet,Budget,DateDebut,DateFin,NomProjet,DirecteurProjet,Lieu);

    P.ajouter(NumProjet,Budget,DateDebut,DateFin,NomProjet,DirecteurProjet,Lieu);

}

void MainWindow::on_ButtonAjouter_Operation_clicked()
{
    int NumOperation=ui->le_numOperation->text().toInt();
    int DateOperation=ui->la_dateOperation->text().toInt();
    int IdClient=ui->le_id->text().toInt();

    QString Nom=ui->le_nom->text();
    QString Prenom=ui->le_prenom->text();

    operations op(NumOperation,DateOperation,IdClient,Nom,Prenom);
    op.ajouter(NumOperation,DateOperation,IdClient,Nom,Prenom);
}
