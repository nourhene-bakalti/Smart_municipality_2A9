#include "projet_materiel.h"
#include <QObject>
#include <QSqlQuery>
#include <QtDebug>


projet_materiel::projet_materiel()
{
 NumProjet=refe=0;
}
projet_materiel::projet_materiel(int NumProjet,int refe)
{
    this->NumProjet=NumProjet;
    this->refe=refe;
}

int projet_materiel::getNumProjet(){return NumProjet;}
int projet_materiel::getrefe(){return refe;}

void projet_materiel::setNumProjet(int NumProjet){this->NumProjet=NumProjet;}
void projet_materiel::setrefe(int refe){this->refe=refe;}


QSqlQueryModel * projet_materiel::afficherPM()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select * from  projet_materiel");
     return model ;

}



 bool projet_materiel::inserer()
 {
     QSqlQuery query;
     QString NumProjet_string= QString::number(NumProjet);
      QString refe_string= QString::number(refe);

     query.prepare("INSERT INTO projet_materiel (NumProjet,refe) "
                   "VALUES (:NumProjet, :refe)");
     query.bindValue(":NumProjet", NumProjet_string);
     qDebug()<<refe;
     query.bindValue(":refe", refe_string);
     qDebug()<<refe_string;
     return query.exec();
 }
