#include "operations.h"
#include <QSqlQuery>
#include <QObject>
#include <QtDebug>
#include<QDate>


operations::operations()
{
      NumOperation=IdClient=0;
     DateOperation=TypeOperation="";
}
operations::operations(int NumOperation,QString DateOperation,int IdClient,QString TypeOperation)
{
    this->NumOperation=NumOperation;
    this->DateOperation= DateOperation;
    this->IdClient= IdClient;
    this->TypeOperation=TypeOperation;

}

int operations::getNumOperation(){return NumOperation;}
QString  operations::getDateOperation() {return DateOperation;}
int  operations::getIdClient() {return IdClient;}
QString operations::getTypeOperation() {return TypeOperation;}

void operations::setNumOperation(int NumOperation){this->NumOperation=NumOperation;}
void operations::setDateOperation(QString DateOperation){this->DateOperation=DateOperation;}
void operations::setIdClient(int IdClient){this->IdClient=IdClient;}
void operations::setTypeOperation(QString TypeOperation){this->TypeOperation=TypeOperation;}

bool operations::ajouter()
{
    QSqlQuery query;
    QString NumOperation_string= QString::number(NumOperation);
    QDate DateOperation_date =QDate::fromString(DateOperation,"dd/MM/yyyy");
    QString IdClient_string= QString::number(IdClient);


          query.prepare("INSERT INTO operations (NumOperation,DateOperation,IdClient,TypeOperation) "
                        "VALUES (:NumOperation, :DateOperation, :IdClient, :TypeOperation)");

          query.bindValue(":NumOperation", NumOperation_string);
          query.bindValue(":DateOperation", DateOperation_date);
          query.bindValue(":IdClient", IdClient_string);
          query.bindValue(":TypeOperation", TypeOperation);

         return query.exec();

}

QSqlQueryModel* operations::afficher()
{
   QSqlQueryModel*  model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM operations");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumOperation"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("DateOperation"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("IdClient"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("TypeOperation"));


    return model;
}

bool operations::supprimer(int NumOperation)
{
     QSqlQuery query;
     query.prepare("delete from operations where NumOperation=:NumOperation");
     query.bindValue(":NumOperation", NumOperation);

      return query.exec();
}

bool operations ::modifier()
{

    QSqlQuery query;

    QString NumOperation_string= QString::number(NumOperation);
     QString IdClient_string= QString::number(IdClient);
     QDate DateOperation_date =QDate::fromString(DateOperation,"dd/MM/yyyy");

          query.prepare("UPDATE operations SET DateOperation=:DateOperation,IdClient=:IdClient,TypeOperation=:TypeOperation WHERE NumOperation=:NumOperation");
          query.bindValue(":NumOperation", NumOperation_string);
          query.bindValue(":DateOperation", DateOperation_date);
          query.bindValue(":IdClient", IdClient_string);
          query.bindValue(":TypeOperation", TypeOperation);

          return query.exec();


}


QSqlQueryModel * operations::afficher_idclient()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select IdClient from  citoyens");
     return model ;

}



QSqlQueryModel *  operations::chercher(int test,QString text)
{

    QSqlQuery query;
        QSqlQueryModel* model=new QSqlQueryModel();
        if(test==0)
       { query.prepare("SELECT * FROM operations where NumOperation like '"+text+"'");
         query.exec();
         model->setQuery(query);
         }
       if(test==1)
          {
           query.prepare("SELECT * FROM operations where IdClient like '"+text+"'");
               query.exec();
               model->setQuery(query);
       }


         return model;


}
