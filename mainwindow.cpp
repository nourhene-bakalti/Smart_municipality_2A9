#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"equipement.h"
#include<QMessageBox>
#include"fournisseur.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QIntValidator>
#include<QSqlDatabase>
#include "connexion.h"
#include<QIntValidator>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabE->setModel(afE.afficherE());
    ui->tabF->setModel(afF.afficherF());
    ui->ref->setValidator(new QIntValidator(0, 999999, this));
   ui->refmodif->setValidator(new QIntValidator(0, 999999, this));
   ui->numero->setValidator(new QIntValidator(0, 99999999, this));
   ui->numeromodif->setValidator(new QIntValidator(0, 99999999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouterE_clicked()
{
    QString objet = ui->objet->text();
    QString ref = ui->ref->text();
    QString quantite = ui->quantite->text();
   equipement E (objet, ref,quantite);
bool test =E.ajouterE();
if (test)
{

    ui->tabE->setModel(afE.afficherE());
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
    qDebug() << player->errorString();
    player->setVolume(100);
    player->play();

}
}

void MainWindow::on_ajouterF_clicked()
{
    QString nom = ui->nom->text();
    QString adress = ui->adress->text();
    QString numero = ui->numero->text();
  fournisseur F (nom, adress,numero);
bool test =F.ajouterF();
if (test)
{ ui->tabF->setModel(afF.afficherF());
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
    qDebug() << player->errorString();
    player->setVolume(100);
    player->play();

}
}





void MainWindow::on_supprimerE_clicked()
{
    equipement c1;
        c1.set_ref(ui->supprimerparE->text());
        bool test=c1.supprimerE(c1.get_ref());
        if(test)
        {

          ui->tabE->setModel(c1.afficherE());

          player = new QMediaPlayer(this);
          player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
          qDebug() << player->errorString();
          player->setVolume(100);
          player->play();
        }

        else
        {
            QMessageBox::information (nullptr,QObject::tr("echec de suppression "),QObject::tr("echec"))   ;
        }
}

void MainWindow::on_refreshE_clicked()
{
    ui->tabE->setModel(afE.afficherE());
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
    qDebug() << player->errorString();
    player->setVolume(100);
    player->play();
}

void MainWindow::on_refreshF_clicked()
{
    ui->tabF->setModel(afF.afficherF());
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
    qDebug() << player->errorString();
    player->setVolume(100);
    player->play();
}

void MainWindow::on_rechercheE_clicked()
{
    int choix;
          choix=ui->combrecherche->currentIndex();
           QString rechercheparE=ui->rechercheparE->text();
           ui->tabE->setModel(afE.chercherE(choix,rechercheparE));

           player = new QMediaPlayer(this);
           player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
           qDebug() << player->errorString();
           player->setVolume(100);
           player->play();

}

void MainWindow::on_modificationE_clicked()
{
    QString choix1,choix2;

             QString  objet=ui->objetmodif->text();
             QString ref=ui->refmodif->text();
             QString quantite=ui->quantitemodif->text();


       equipement  eq(objet,ref,quantite);
            QMessageBox msgBox;
       bool test=eq.modifierE();
            if(test)
              {
                  ui->tabE->setModel(eq.afficherE());

                  player = new QMediaPlayer(this);
                  player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
                  qDebug() << player->errorString();
                  player->setVolume(100);
                  player->play();
                  msgBox.exec();
            }
            else
               { msgBox.setText("commande n'exite pas ");


    }

}


void MainWindow::on_supprimerF_clicked()
{
    fournisseur c1;

        c1.set_numero(ui->supprimerparF->text());
        bool test=c1.supprimerF(c1.get_numero());
        if(test)
        {

          ui->tabF->setModel(c1.afficherF());

          player = new QMediaPlayer(this);
          player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
          qDebug() << player->errorString();
          player->setVolume(100);
          player->play();
        }

        else
        {
            QMessageBox::information (nullptr,QObject::tr("echec de suppression "),QObject::tr("echec"))   ;
        }
}




void MainWindow::on_modificationF_clicked()
{
    QString choix1,choix2;

             QString  nom=ui->nommodif->text();
             QString adress=ui->adressmodif->text();
             QString numero=ui->numeromodif->text();


      fournisseur  fr(nom,adress,numero);
            QMessageBox msgBox;
       bool test=fr.modifierF();
            if(test)
              {
                  ui->tabF->setModel(fr.afficherF());

                  player = new QMediaPlayer(this);
                  player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
                  qDebug() << player->errorString();
                  player->setVolume(100);
                  player->play();

            }
            else
               { msgBox.setText("commande n'exite pas ");


    }
            msgBox.exec();
}

void MainWindow::on_rechercheF_clicked()
{
    int choix;
          choix=ui->combchercheF->currentIndex();
           QString rechercheparF=ui->rechercheparF->text();
           ui->tabF->setModel(afF.chercherF(choix,rechercheparF));

           player = new QMediaPlayer(this);
           player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
           qDebug() << player->errorString();
           player->setVolume(100);
           player->play();


}



void MainWindow::on_trierF_clicked()
{
    int choix;

    if(ui->triec->isChecked())
               {

ui->tabF->setModel(afF.affichercrF());

                player = new QMediaPlayer(this);
                player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
                qDebug() << player->errorString();
                player->setVolume(100);
                player->play();

               }
            else if (ui->tried->isChecked())
            {
        ui->tabF->setModel(ih.afficherdcF());

                player = new QMediaPlayer(this);
                player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
                qDebug() << player->errorString();
                player->setVolume(100);
                player->play();
            }


    else if (ui->trieFN->isChecked())
    {
ui->tabF->setModel(ih.affichercrFN());

        player = new QMediaPlayer(this);
        player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
        qDebug() << player->errorString();
        player->setVolume(100);
        player->play();
    }
    else if (ui->trieFN2->isChecked())
    {
ui->tabF->setModel(ih.afficherdcFN());

        player = new QMediaPlayer(this);
        player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
        qDebug() << player->errorString();
        player->setVolume(100);
        player->play();
    }


    else if (ui->trieFM->isChecked())
    {
ui->tabF->setModel(ih.affichercrFM());

        player = new QMediaPlayer(this);
        player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
        qDebug() << player->errorString();
        player->setVolume(100);
        player->play();
    }
    else if (ui->trieFM2->isChecked())
    {
ui->tabF->setModel(ih.afficherdcFM());

        player = new QMediaPlayer(this);
        player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
        qDebug() << player->errorString();
        player->setVolume(100);
        player->play();
    }






}



























































void MainWindow::on_trier_clicked()
{

    if(ui->trie_c->isChecked())
               {
                ui->tabE->setModel(afE.affichercrE());

                player = new QMediaPlayer(this);
                player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
                qDebug() << player->errorString();
                player->setVolume(100);
                player->play();

               }
            else if (ui->trie_d->isChecked())
            {
                ui->tabE->setModel(afE.afficherdcE());

                player = new QMediaPlayer(this);
                player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
                qDebug() << player->errorString();
                player->setVolume(100);
                player->play();

            }




    else if (ui->trieER->isChecked())
    {
        ui->tabE->setModel(afE.affichercrER());

        player = new QMediaPlayer(this);
        player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
        qDebug() << player->errorString();
        player->setVolume(100);
        player->play();

    }
    else if (ui->trieER2->isChecked())
    {
        ui->tabE->setModel(afE.afficherdcER());

        player = new QMediaPlayer(this);
        player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
        qDebug() << player->errorString();
        player->setVolume(100);
        player->play();


}



        else if (ui->trieEQ->isChecked())
        {
            ui->tabE->setModel(afE.affichercrEQ());

            player = new QMediaPlayer(this);
            player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
            qDebug() << player->errorString();
            player->setVolume(100);
            player->play();

        }
        else if (ui->trieEQ2->isChecked())
        {
            ui->tabE->setModel(afE.afficherdcEQ());

            player = new QMediaPlayer(this);
            player->setMedia(QUrl::fromLocalFile("C:/Users/Asus/Desktop/Welcome.mp3"));
            qDebug() << player->errorString();
            player->setVolume(100);
            player->play();

    }

}

