#include "fournisseur.h"
#include "connexion.h"
#include <QSqlDatabase>
#include <QObject>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>



fournisseur::fournisseur()
{
numero="";
nom="";
adress="";

}
 fournisseur::fournisseur(QString nom, QString adress, QString numero)
 {
     this->nom=nom;
     this->adress=adress;
     this->numero=numero;

 }
 QString fournisseur::get_nom(){return nom;}
 QString fournisseur::get_adress(){return adress;}
 QString fournisseur::get_numero(){return numero;}
 void fournisseur::set_nom(QString nom){this->nom=nom;}
 void fournisseur::set_adress(QString adress ){this->adress=adress;}
 void fournisseur::set_numero(QString numero){this->numero=numero;}

 bool fournisseur::ajouterF()
 {
     QSqlQuery query;

     query.prepare("INSERT INTO fournisseur(nom,adress,numero)" " VALUES (:nom,:adress, :numero)");
     query.bindValue(":nom",nom);
     query.bindValue(":adress",adress);
     query.bindValue(":numero",numero);
     return query.exec();

 }

QSqlQueryModel* fournisseur::afficherF()
  {
      QSqlQueryModel* model=new QSqlQueryModel();

      model->setQuery("SELECT* FROM fournisseur");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("adress"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));



      return model;
  }
bool fournisseur::supprimerF(QString numero)
{
    QSqlQuery query;

          query.prepare(" delete from fournisseur where numero = :numero");
          query.bindValue(0, numero);

    return query.exec();

}

bool fournisseur::modifierF()
{
    bool test=false;
    QSqlQuery query;
    query.prepare(" UPDATE fournisseur SET nom=:nom,adress=:adress,numero=:numero WHERE nom=:nom");
      query.bindValue(":nom", nom);
      query.bindValue(":adress", adress);
      query.bindValue(":numero", numero);
          return query.exec();
          return test;
}



QSqlQueryModel* fournisseur::chercherF(int index,QString text)
{
QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(index==0)
   { query.prepare("SELECT * FROM fournisseur where nom like '"+text+"'");
     query.exec();
     model->setQuery(query);
     }
   if(index==1)
      {
       query.prepare("SELECT * FROM fournisseur where adress like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   if(index==2)
      {
       query.prepare("SELECT * FROM fournisseur where numero like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   return model;

}

   QSqlQueryModel * fournisseur::affichercrF()
   {
   QSqlQuery query;
       query.prepare("SELECT * FROM fournisseur ORDER BY adress ASC;");

       query.exec();
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adress"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));


   return model;
   }

   QSqlQueryModel * fournisseur::afficherdcF()
   {
       QSqlQuery query;
       query.prepare("SELECT * FROM fournisseur ORDER BY adress DESC;");

       query.exec();
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adress "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));

    return model;
   }









   QSqlQueryModel * fournisseur::affichercrFN()
   {
   QSqlQuery query;
       query.prepare("SELECT * FROM fournisseur ORDER BY nom ASC;");

       query.exec();
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adress"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));


   return model;
   }

   QSqlQueryModel * fournisseur::afficherdcFN()
   {
       QSqlQuery query;
       query.prepare("SELECT * FROM fournisseur ORDER BY nom DESC;");

       query.exec();
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adress "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));

    return model;
   }



   QSqlQueryModel * fournisseur::affichercrFM()
   {
   QSqlQuery query;
       query.prepare("SELECT * FROM fournisseur ORDER BY numero ASC;");

       query.exec();
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adress"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));


   return model;
   }

   QSqlQueryModel * fournisseur::afficherdcFM()
   {
       QSqlQuery query;
       query.prepare("SELECT * FROM fournisseur ORDER BY numero DESC;");

       query.exec();
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adress "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));

    return model;
   }





