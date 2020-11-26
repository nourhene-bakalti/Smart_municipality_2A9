#include "reclamation.h"
#include <QDebug>
Reclamation::Reclamation()
{
nom="";
problem="";
definition="";

}
Reclamation::Reclamation(QString nom,QString problem,QString definition)
{
    this->nom=nom;
    this->problem=problem;
    this->definition=definition;

}
QString Reclamation::get_nom(){return nom;}
QString Reclamation::get_problem(){return problem;}
QString Reclamation::get_definition(){return definition;}

bool Reclamation::ajouter()
{
QSqlQuery query;
QString res=QString::number(numero);
query.prepare("INSERT INTO reclamation (nom, problem, definition)"VALUES (:nom ,:problem, :definition)");
query.bindvalue(":nom",nom);
query.bindValue(":problem",problem);
query.bindValue(":definition",definition);
return query.exec();
}



QSqlQueryModel * Reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from reclamation");
 model->setheaderData(0,Qt::Horizontal,Qobject::tr("nom"));
 model->setheaderData(1,Qt::Horizontal,Qobject::tr("problem"));
 model->setheaderData(2,Qt::Horizontal,Qobject::tr("definition"));
 return model ;

}



bool Reclamation::supprimer(QString nom)
{
    QSqlQuery query ;
    QString res= QString number(nom);
    query.prepare("delete from reclamation where nom = :nom");
    query.bindValue(":nom",res);
    return query.exect();
}

