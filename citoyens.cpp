#include "citoyens.h"

citoyens::citoyens()
{
    IdClient=0;
    Nom=Prenom="";
}

citoyens::citoyens(int IdClient,QString Nom,QString Prenom)
{
    this->IdClient=IdClient;
    this->Nom=Nom;
    this->Prenom=Prenom;

}

int citoyens::getIdClient(){return IdClient;}
QString  citoyens::getNom() {return Nom;}
QString citoyens::getPrenom() {return Prenom;}


void citoyens::setIdClient(int IdClient) {this->IdClient=IdClient;}
void citoyens::setNom(QString Nom){this->Nom=Nom;}
void citoyens::setPrenom(QString Prenom){this->Prenom=Prenom;}
