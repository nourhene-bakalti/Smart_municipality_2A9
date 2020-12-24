#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{

    db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("DB_SmartPaladeya");
db.setUserName("amal");//inserer nom de l'utilisateur
db.setPassword("test");//inserer mot de passe de cet utilisateur


if (db.open())
return true;
    return  false;
}
bool Connexion::fermerConnexion()
{db.close();}
