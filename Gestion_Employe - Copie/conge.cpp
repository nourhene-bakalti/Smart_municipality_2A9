#include "conge.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Conge::Conge()
{
id=0; nom=" "; prenom=""; date=""; duree=0;
}

Conge::Conge(int id, int duree, QString nom,QString prenom ,QString date)
{this->id=id; this->duree=duree; this->nom=nom; this->prenom=prenom; this->date=date;}
int Conge::getid(){return id;}
int Conge::getduree(){return duree;}
QString Conge::getnom(){return  nom;}
QString Conge::getprenom(){return prenom;}
QString Conge::getdate(){return date;}
void Conge::setid(int id){this->id=id;}
void Conge::setduree(int duree){this->duree=duree;}
void Conge::setnom(QString nom){this->nom=nom;}
void Conge::setprenom(QString prenom){this->prenom=prenom;}
void Conge::setdate(QString datee){this->date=datee;}
bool Conge::ajouter()
{

    QSqlQuery query;
  QString id_string= QString::number(id);
  QString duree_string= QString::number(duree);
         query.prepare("INSERT INTO Conge (id, nom, prenom, datee, duree) "
                       "VALUES (:id, :forename, :surname, :datee, :duree)");
         query.bindValue(":id",id_string);
         query.bindValue(":forename", this->nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":datee", date);
         query.bindValue(":duree",duree_string);

        return query.exec();

}
bool Conge::supprimer(int id)
{
    QSqlQuery query;
         query.prepare(" Delete from Conge where id=:id");
         query.bindValue(0, id);

        return query.exec();


}
QSqlQueryModel* Conge::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM Conge");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("duree"));

  return  model;
}

bool Conge::modifier(int id,int duree, QString nom,QString prenom,QString datee){
    QSqlQuery query;
    query.prepare("UPDATE conge SET duree=:duree,nom=:nom,prenom=:prenom,datee=:datee WHERE id=:id");
    QString res= QString::number(id);
    QString ress=QString::number(duree);
    query.bindValue(":id",res);
    query.bindValue(":duree",ress);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":datee",datee);
    return query.exec();
}

QSqlQueryModel * Conge::chercher(QString res)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM conge WHERE (id LIKE '%"+res+"%' or nom LIKE '%"+res+"%' or prenom LIKE '%"+res+"%' or datee LIKE '%"+res+"%') ");
    return  model;


}

