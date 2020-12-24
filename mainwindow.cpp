#include "mainwindow.h"
#include "firstpage.h"
#include "ui_firstpage.h"
#include "ui_mainwindow.h"
#include "projets.h"
#include "operations.h"
#include "projet_materiel.h"
#include <QPushButton>
#include <QMessageBox>
#include <QIntValidator>
#include <QWidget>
#include <QTableWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
        ui->setupUi(this);
     ui->le_id_2->setValidator(new QIntValidator(0, 99999999, this));
     ui->le_numOperation_2->setValidator(new QIntValidator(0, 99999999, this));
     ui->le_NumProjet_2->setValidator(new QIntValidator(0, 99999999, this));
     ui->tableView_projet_2->setModel(p.afficher());
     ui->tableView_operation_2->setModel(o.afficher());
     ui->le_id_2->setModel(o.afficher_idclient());

     int NumProjet=ui->idprojets->currentText().toInt();

     ui->tableView_materiel->setModel(pm.afficherPM());

     ui->comboBox_rechercheOP->addItem("NumOperation");
     ui->comboBox_rechercheOP->addItem("IdClient");
     ui->comboBox_recherchePR->addItem("NumProjet");
     ui->comboBox_recherchePR->addItem("NomProjet");
     ui->comboBox_recherchePR->addItem("Lieu");
   ui->idprojets->setModel(p.afficheridp());
    ui->refMateriels->setModel(m.afficherREFM());
     int ret=A.connect_arduino(); // lancer la connexion à arduino
         switch(ret){
         case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
             break;
         case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
            break;
         case(-1):qDebug() << "arduino is not available";
         }
          QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_BoutonAjouter_clicked()
{
    int NumProjet=ui->le_NumProjet_2->text().toInt();
    int Budget=ui->le_budget_2->text().toInt();
    QString DateDebut=ui->la_DateDebut_3->text();
    QString DateFin=ui->la_DateFin_3->text();
    QString NomProjet=ui->le_NomProjet_2->text();
    QString DirecteurProjet=ui->Le_DirecteurProjet_2->text();
    QString Lieu=ui->le_lieu_2->currentText();


    projets p(NumProjet,Budget,DateDebut,DateFin,NomProjet,DirecteurProjet,Lieu);



     bool test=p.ajouter( p.getNumProjet(), p.getBudget(), p.getDateDebut(), p.getDateFin(), p.getNomProjet(),
                         p.getDirecteurProjet(), p.getLieu());
     QMessageBox msgBox;

     if(test)
     { msgBox.setText("ajout avec succes");
         ui->tableView_projet_2->setModel(p.afficher());
          ui->idprojets->setModel(p.afficheridp());

     }
else
         msgBox.setText("echec d'ajout");
     msgBox.exec();
}




void MainWindow::on_boutonSuppProjet_clicked()
{
projets p;
p.setNumProjet(ui->le_NumProjet_2->text().toInt());


bool test=p.supprimer(p.getNumProjet());

QMessageBox msgBox;

if(test)
{ msgBox.setText("suppression avec succes");
 ui->tableView_projet_2->setModel(p.afficher());
}
else
    msgBox.setText("echec de suppression");
msgBox.exec();
}

void MainWindow::on_Button_modif_projet__clicked()
{


    int NumProjet=ui->le_NumProjet_2->text().toInt();
    int Budget=ui->le_budget_2->text().toInt();
    QString DateDebut=ui->la_DateDebut_3->text();
    QString DateFin=ui->la_DateFin_3->text();
    QString NomProjet=ui->le_NomProjet_2->text();
    QString DirecteurProjet=ui->Le_DirecteurProjet_2->text();
    QString Lieu=ui->le_lieu_2->currentText();



             projets p(NumProjet,Budget,DateDebut,DateFin,NomProjet,DirecteurProjet,Lieu);

            QMessageBox msgBox;
       bool test=p.modifier();
            if(test)
              {
                msgBox.setText("modification avec succes ");
                  ui->tableView_projet_2->setModel(p.afficher());



            }
            else
               { msgBox.setText("projet n'exite pas ");


    }
            msgBox.exec();

}

void MainWindow::on_ButtonAjouter_Operation_2_clicked()
{
    int NumOperation=ui->le_numOperation_2->text().toInt();
   QString DateOperation=ui->la_dateOperation_2->text();
    int IdClient=ui->le_id_2->currentText().toInt();
    QString TypeOperation=ui->le_typeOperation->text();


    operations o(NumOperation,DateOperation,IdClient,TypeOperation);

    bool test=o.ajouter();

    QMessageBox msgBox;

    if(test)
    { msgBox.setText("ajout avec succes");
        ui->tableView_operation_2->setModel(o.afficher());

    }
else
        msgBox.setText("echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_Button_supp_op_clicked()
{
    operations o;
    o.setNumOperation(ui->le_numOperation_2->text().toInt());


    bool test=o.supprimer(o.getNumOperation());

    QMessageBox msgBox;

    if(test)
    { msgBox.setText("suppression avec succes");
     ui->tableView_operation_2->setModel(o.afficher());
    }
    else
        msgBox.setText("echec de suppression");
    msgBox.exec();
}

void MainWindow::on_Button_modif_op_clicked()
{
    int NumOperation=ui->le_numOperation_2->text().toInt();
    QString DateOperation=ui->la_dateOperation_2->text();
    int IdClient=ui->le_id_2->currentText().toInt();
    QString TypeOperation=ui->le_typeOperation->text();



    operations o(NumOperation,DateOperation,IdClient,TypeOperation);

    QMessageBox msgBox;
bool test=o.modifier();
    if(test)
      {
        msgBox.setText("modification avec succes ");
          ui->tableView_operation_2->setModel(o.afficher());



    }
    else
       { msgBox.setText("projet n'exite pas ");


}
    msgBox.exec();


}



void MainWindow::on_pushButton_chercherOP_clicked()
{
    int choix;
          choix=ui->comboBox_rechercheOP->currentIndex();
          QString le_rechercher=ui->le_rechercher->text();
           ui->tableView_operation_2->setModel(o.chercher(choix,le_rechercher));
}

void MainWindow::on_affiche_tout_clicked()
{
    ui->tableView_operation_2->setModel(o.afficher());
}

void MainWindow::on_pushButton_chercherPR_clicked()
{
    int choix;
          choix=ui->comboBox_recherchePR->currentIndex();
          QString lineEdit_cherchPR=ui->lineEdit_cherchPR->text();
           ui->tableView_projet_2->setModel(p.chercher(choix,lineEdit_cherchPR));
}

void MainWindow::on_afficherPR_clicked()
{
     ui->tableView_projet_2->setModel(p.afficher());
}


void MainWindow::on_pushButton_materiel_2_clicked()
{
   ui->gestionProjets->setCurrentIndex(2);
}

void MainWindow::on_button_affecter_clicked()
{
  int NumProjet=ui->idprojets->currentText().toInt();
  QString nomm=ui->refMateriels->currentText();
int refe=m.chercherREFM(nomm);
qDebug()<<refe;
  projet_materiel pm(NumProjet,refe);

  bool test=pm.inserer();

  QMessageBox msgBox;

  if(test)
  { msgBox.setText("insertion avec succes");
      ui->tableView_materiel->setModel(pm.afficherPM());

  }
else
      msgBox.setText("echec d'insertion");
  msgBox.exec();
}
