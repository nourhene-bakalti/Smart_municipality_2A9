#include "materiel.h"
#include <QSqlQuery>
materiel::materiel()
{

}
QSqlQueryModel* materiel::afficherREFM()
{
    QSqlQueryModel*  model=new QSqlQueryModel();

         model->setQuery("SELECT NomMateriel FROM materiel ");
         return model;

}
int materiel::chercherREFM(QString NomMateriel)
{int ref;
    QSqlQuery query;
   query.prepare("SELECT refe FROM materiel where NomMateriel=:ref ");
   query.bindValue(":ref",NomMateriel);
       query.exec();
       while(query.next())
       { ref=query.value(0).toInt();}

       return ref;
}
