#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Employe::Employe()
{
id=0; cin=0; nom=" "; prenom=""; position="";tel=0;
}

Employe::Employe(int id, int cin, QString nom,QString prenom ,QString position,int tel)
{this->id=id; this->cin=cin; this->nom=nom; this->prenom=prenom; this->position=position;this->tel=tel;}
int Employe::getid(){return id;}
int Employe::getcin(){return cin;}
QString Employe::getnom(){return  nom;}
QString Employe::getprenom(){return prenom;}
QString Employe::getposition(){return position;}
int Employe::gettel(){return tel;}

void Employe::setid(int id){this->id=id;}
void Employe::setcin(int cin){this->cin=cin;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
void Employe::setposition(QString position){this->position=position;}
void Employe::settel(int tel){this->tel=tel;}


bool Employe::ajouter()
{

    QSqlQuery query;
  QString id_string= QString::number(this->id);
  QString cin_string= QString::number(this->cin);
  QString tel_string = QString::number(this->tel);
         query.prepare("INSERT INTO Employe (id, cin, nom, prenom, position,tel) "
                       "VALUES (:id, :cin, :forename, :surname, :position, :tel)");
         query.bindValue(":id",id_string);
         query.bindValue(":cin",cin_string);
         query.bindValue(":forename", nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":position", position);
         query.bindValue(":tel", tel_string);
        return query.exec();

}
bool Employe::supprimer(int id)
{
    QSqlQuery query;
         query.prepare(" Delete from Employe where id=:id");
         query.bindValue(0, id);

        return query.exec();


}
QSqlQueryModel* Employe::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM Employe");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Position"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));


  return  model;
}



bool Employe::modifier(int id,int cin,QString nom,QString prenom,QString position,int tel)
{
    QSqlQuery query;
    query.prepare("UPDATE Employe SET cin=:cin,nom=:nom,prenom=:prenom,position=:position,tel=:tel WHERE id=:id");
    QString res= QString::number(id);
    QString ress=QString::number(cin);
    QString reess=QString::number(tel);
    query.bindValue(":id",res);
    query.bindValue(":cin",ress);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":position",position);
    query.bindValue(":tel",reess);
    return query.exec();
}

QSqlQueryModel * Employe::chercher(QString res)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe WHERE (id LIKE '%"+res+"%' or cin LIKE '%"+res+"%' or nom LIKE '%"+res+"%'  or prenom LIKE '%"+res+"%' or position LIKE '%"+res+"%'  or tel LIKE '%"+res+"%' ) ");
    return  model;
}
