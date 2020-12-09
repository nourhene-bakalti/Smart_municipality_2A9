#include "projets.h"

#include <QSqlQuery>
#include <QtDebug>
#include<iostream>
projets::projets()
{
    NumProjet=Budget=DateDebut=DateFin=0;
    NomProjet=DirecteurProjet=Lieu="";
}


projets::projets(int NumProjet,int Budget,int DateDebut,int DateFin,QString NomProjet,QString DirecteurProjet,QString Lieu)
{
 this->NumProjet=NumProjet; this->DateDebut=DateDebut; this->DateFin=DateFin; this->NomProjet=NomProjet;
    this->DirecteurProjet=DirecteurProjet; this->Budget=Budget; this->Lieu=Lieu;
}

 int projets::getBudget(){return Budget;}
int projets::getNumProjet(){return NumProjet;}
int projets::getDateDebut() {return DateDebut;}
int projets::getDateFin() {return DateFin;}
QString projets::getNomProjet(){return NomProjet;}
QString projets::getDirecteurProjet(){return DirecteurProjet;}
QString projets::getLieu(){return Lieu;}

void projets::setBudget(int Budget){this->Budget=Budget;}
void projets::setNumProjet(int NumProjet){this->NumProjet=NumProjet;}
void projets::setDateDebut(int DateDebut){this->DateDebut=DateDebut;}
void projets::setDateFin(int DateFin){this->DateFin=DateFin;}
void projets::setNomProjet(QString NomProjet){this->NomProjet=NomProjet;}
void projets::setDirecteurProjet(QString DirecteurProjet){this->DirecteurProjet=DirecteurProjet;}
void projets::setLieu(QString Lieu){this->Lieu=Lieu;}

bool projets::ajouter(int NumProjet,int Budget,int DateDebut,int DateFin,QString NomProjet,QString DirecteurProjet,QString Lieu)
{bool test=false;
    QSqlQuery query;
    QString NumProjet_string= QString::number(NumProjet);
    QString Budget_string= QString::number(Budget);
    QString DateDebut_string= QString::number(DateDebut);
    QString DateFin_string= QString::number(DateFin);

          query.prepare("INSERT INTO projets (NumProjet,Budget,DateDebut,DateFin,NomProjet,DirecteurProjet,Lieu) "
                        "VALUES (:NumProjet, :Budget, :DateDebut, :DateFin, :NomProjet, :DirecteurProjet, :Lieu)");
          query.bindValue(":NumProjet", NumProjet_string);
          query.bindValue(":Budget", Budget_string);
          query.bindValue(":DateDebut", DateDebut_string);
          query.bindValue(":DateFin", DateFin_string);
          query.bindValue(":NomProjet", NomProjet);
          query.bindValue(":DirecteurProjet", DirecteurProjet);
          query.bindValue(":Lieu", Lieu);



          return query.exec();

}

