#include "equipement.h"
#include "connexion.h"
#include <QSqlDatabase>
#include <QObject>
#include<QMessageBox>
#include<QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

equipement::equipement()
{
quantite="";
objet="";
ref="";

}
 equipement::equipement(QString objet, QString ref, QString quantite)
 {
     this->objet=objet;
     this->ref=ref;
     this->quantite=quantite;

 }
 QString equipement::get_object(){return objet;}
 QString equipement::get_ref(){return ref;}
 QString equipement::get_quantite(){return quantite;}
 void equipement::set_object(QString objet){this->objet=objet;}
 void equipement::set_ref(QString ref ){this->ref=ref;}
 void equipement::set_quantite(QString quantite){this->quantite=quantite;}

 bool equipement::ajouterE()
 {
     QSqlQuery query;

     query.prepare("INSERT INTO equipement(objet,ref,quantite)" " VALUES (:objet,:ref, :quantite)");
     query.bindValue(":objet",objet);
     query.bindValue(":ref",ref);
     query.bindValue(":quantite",quantite);
     return query.exec();

 }

QSqlQueryModel* equipement::afficherE()
 {

     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM EQUIPEMENT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));


     return model;
 }

bool equipement::supprimerE(QString ref)
{
    QSqlQuery query;

          query.prepare(" delete from equipement where ref = :ref");
          query.bindValue(0, ref);

    return query.exec();

}

QSqlQueryModel* equipement::chercherE(int index,QString text)
{
QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    if(index==0)
   { query.prepare("SELECT * FROM equipement where objet like '"+text+"'");
     query.exec();
     model->setQuery(query);
     }
   if(index==1)
      {
       query.prepare("SELECT * FROM equipement where ref like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }
   if(index==2)
      {
       query.prepare("SELECT * FROM equipement where quantite like '"+text+"'");
           query.exec();
           model->setQuery(query);
   }


    return model;

}
bool equipement ::modifierE()
{
    bool test=false;
    QSqlQuery query;




    query.prepare(" UPDATE equipement SET objet=:objet,ref=:ref,quantite=:quantite WHERE objet=:objet");
      query.bindValue(":objet", objet);
      query.bindValue(":ref", ref);
      query.bindValue(":quantite", quantite);
          return query.exec();
          return test;
}

QSqlQueryModel * equipement::affichercrE()
{
QSqlQuery query;
    query.prepare("SELECT * FROM equipement ORDER BY objet ASC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));

return model;
}

QSqlQueryModel * equipement::afficherdcE()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM equipement ORDER BY objet DESC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref "));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));

 return model;
}



















QSqlQueryModel * equipement::affichercrER()
{
QSqlQuery query;
    query.prepare("SELECT * FROM equipement ORDER BY ref ASC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));

return model;
}

QSqlQueryModel * equipement::afficherdcER()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM equipement ORDER BY ref DESC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref "));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));

 return model;
}

QSqlQueryModel * equipement::afficherdcEQ()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM equipement ORDER BY quantite DESC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref "));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));

 return model;
}

QSqlQueryModel * equipement::affichercrEQ()
{
QSqlQuery query;
    query.prepare("SELECT * FROM equipement ORDER BY quantite ASC;");

    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("objet"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("ref "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));

return model;
}
