#include "operations.h"
#include <QSqlQuery>
#include <QtDebug>
#include<iostream>
operations::operations()
{
      NumOperation=DateOperation=IdClient=0;
      Nom=Prenom="";
}
operations::operations(int NumOperation,int DateOperation,int IdClient,QString Nom,QString Prenom)
{
    this->NumOperation=NumOperation;
    this->DateOperation= DateOperation;
    this->IdClient= IdClient;
    this->Nom=Nom;
    this->Prenom=Prenom;
}

int operations::getNumOperation(){return NumOperation;}
int  operations::getDateOperation() {return DateOperation;}
int  operations::getIdClient() {return IdClient;}
QString  operations::getNom(){return Nom;}
QString  operations::getPrenom(){return Prenom;}

void operations::setNumOperation(int NumOperation){this->NumOperation=NumOperation;}
void operations::setDateOperation(int DateOperation){this->DateOperation=DateOperation;}
void operations::setIdClient(int IdClient){this->IdClient=IdClient;}
void operations::setNom(QString Nom){this->Nom=Nom;}
void operations::setPrenom(QString Prenom){this->Prenom=Prenom;}

bool operations::ajouter(int NumOperation,int DateOperation,int IdClient,QString Nom,QString Prenom)
{bool test=false;
    QSqlQuery query;

    QString NumOperation_string= QString::number(NumOperation);
    QString DateOperation_string= QString::number(DateOperation);
    QString IdClient_string= QString::number(IdClient);

          query.prepare("INSERT INTO operations (NumOperation,DateOperation,IdClient,Nom,Prenom) "
                        "VALUES (:NumOperation, :DateOperation, :IdClient, :Nom, :Prenom )");
          query.bindValue(":NumOperation", NumOperation_string);
          query.bindValue(":DateOperation", DateOperation_string);
          query.bindValue(":IdClient", IdClient_string);
          query.bindValue(":Nom", Nom);
          query.bindValue(":Prenom", Prenom);



          return query.exec();

}
