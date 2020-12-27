#include <QDebug>
#include <QSqlError>
#include"connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{ db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("Source_Projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur
qDebug ()<<db.lastError();
if (db.open())
return true;
    return  false;
}

void Connexion::fermerConnexion()
{db.close();}
