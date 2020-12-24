#include "projets.h"
#include <QObject>
#include <QSqlQuery>
#include <QtDebug>
#include<QDate>
projets::projets()
{
    NumProjet=Budget=0;
    NomProjet=DirecteurProjet=Lieu=DateDebut=DateFin="";
}


projets::projets(int NumProjet,int Budget,QString DateDebut,QString DateFin,QString NomProjet,QString DirecteurProjet,QString Lieu)
{
 this->NumProjet=NumProjet; this->DateDebut=DateDebut; this->DateFin=DateFin; this->NomProjet=NomProjet;
    this->DirecteurProjet=DirecteurProjet; this->Budget=Budget; this->Lieu=Lieu;
}

 int projets::getBudget(){return Budget;}
int projets::getNumProjet(){return NumProjet;}
QString projets::getDateDebut() {return DateDebut;}
QString projets::getDateFin() {return DateFin;}
QString projets::getNomProjet(){return NomProjet;}
QString projets::getDirecteurProjet(){return DirecteurProjet;}
QString projets::getLieu(){return Lieu;}

void projets::setBudget(int Budget){this->Budget=Budget;}
void projets::setNumProjet(int NumProjet){this->NumProjet=NumProjet;}
void projets::setDateDebut(QString DateDebut){this->DateDebut=DateDebut;}
void projets::setDateFin(QString DateFin){this->DateFin=DateFin;}
void projets::setNomProjet(QString NomProjet){this->NomProjet=NomProjet;}
void projets::setDirecteurProjet(QString DirecteurProjet){this->DirecteurProjet=DirecteurProjet;}
void projets::setLieu(QString Lieu){this->Lieu=Lieu;}

bool projets::ajouter(int NumProjet,int Budget,QString DateDebut,QString DateFin,QString NomProjet,QString DirecteurProjet,QString Lieu)
{
    QSqlQuery query;
    QString NumProjet_string= QString::number(NumProjet);
    QString Budget_string= QString::number(Budget);
    QDate DateDebut_date =QDate::fromString(DateDebut,"dd/MM/yyyy");
    QDate DateFin_date =QDate::fromString(DateFin,"dd/MM/yyyy");



          query.prepare("INSERT INTO projets (Budget,NumProjet,DateDebut,DateFin,NomProjet,DirecteurProjet,Lieu) "
                        "VALUES ( :Budget,:NumProjet, :DateDebut, :DateFin, :NomProjet, :DirecteurProjet, :Lieu)");
          query.bindValue(":NumProjet", NumProjet_string);
          query.bindValue(":Budget", Budget_string);
          query.bindValue(":DateDebut", DateDebut_date);
          query.bindValue(":DateFin", DateFin_date);
          query.bindValue(":NomProjet", NomProjet);
          query.bindValue(":DirecteurProjet", DirecteurProjet);
          query.bindValue(":Lieu", Lieu);



          return query.exec();
}



QSqlQueryModel* projets::afficher()
{

    QSqlQueryModel*  model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM projets");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Budget"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NumProjet"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateDebut"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateFin"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("NomProjet"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("DirecteurProjet"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Lieu"));

    return model;
}

QSqlQueryModel* projets::afficheridp()
{

    QSqlQueryModel*  model=new QSqlQueryModel();

         model->setQuery("SELECT NumProjet FROM projets");


    return model;
}

bool projets::supprimer(int NumProjet)
{
     QSqlQuery query;
     query.prepare("delete from projets where NumProjet=:NumProjet");
     query.bindValue(":NumProjet", NumProjet);

      return query.exec();
}


bool projets ::modifier()
{

    QSqlQuery query;
    QString NumProjet_string= QString::number(NumProjet);
    QString Budget_string= QString::number(Budget);
    QDate DateDebut_date= QDate::fromString(DateDebut,"dd/MM/yy");
    QDate DateFin_date= QDate::fromString(DateFin,"dd/MM/yy");


    query.prepare(" UPDATE projets SET Budget=:Budget,DateDebut=:DateDebut,DateFin=:DateFin,NomProjet=:NomProjet,DirecteurProjet=:DirecteurProjet,Lieu=:Lieu WHERE NumProjet=:NumProjet");

    query.bindValue(":NumProjet", NumProjet_string);
    query.bindValue(":Budget", Budget_string);
    query.bindValue(":DateDebut", DateDebut_date);
    query.bindValue(":DateFin", DateFin_date);
    query.bindValue(":NomProjet", NomProjet);
    query.bindValue(":DirecteurProjet", DirecteurProjet);
    query.bindValue(":Lieu", Lieu);
          return query.exec();

}


QSqlQueryModel *  projets::chercher(int test,QString text)
{

    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(test==0)
       { query.prepare("SELECT * FROM projets where NumProjet like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(test==1)
          {
           query.prepare("SELECT * FROM projets where NomProjet like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }
       if(test==2)
          {
           query.prepare("SELECT * FROM projets where Lieu like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }


         return model;


}


