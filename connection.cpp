#include "commande.h"
#include <QDebug>
Commande::Commande()
{
piece="";
referance=0;
nombre=0;
prix=0;
}
Commande::Commande(QString piece,int referance,int nombre,int prix)
{
    this->piece=piece;
    this->referance=referance;
    this->nombre=nombre;
    this->prix=prix;
}
QString Commande::get_piece(){return piece;}
int Commande::get_referance(){return referance;}
int Commande::get_nombre(){return nombre;}
int Commande::get_prix(){return prix;}



bool Commande::ajouter()
{
QSqlQuery query;
QString res=QString::number(numero);
query.prepare("INSERT INTO reclamation (piece, referance, nombre, prix )"VALUES (:piece ,:referance, :nombre,:prix)");
query.bindvalue(":piece",piece);
query.bindvalue(":referance",referance);
query.bindvalue(":nombre",nombre);
query.bindvalue(":prix",prix);
return query.exec();
}



QSqlQueryModel * Commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from reclamation");
 model->setheaderData(0,Qt::Horizontal,Qobject::tr("piece"));
 model->setheaderData(1,Qt::Horizontal,Qobject::tr("referance"));
 model->setheaderData(2,Qt::Horizontal,Qobject::tr("nombre"));
 model->setheaderData(2,Qt::Horizontal,Qobject::tr("prix"));
 return model ;

}



bool Commande::supprimer(QString piece)
{
    QSqlQuery query ;
    QString res= QString number(piece);
    query.prepare("delete from reclamation where piece = :piece");
    query.bindaValue(":piece",res);
    return query.exect();
}

