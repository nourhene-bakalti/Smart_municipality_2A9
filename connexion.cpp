#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirConnexion()
{
  db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("mezenDB");
db.setUserName("mezen");
db.setPassword("mezen2000");

if (db.open()) return true;
return false ;
}

void connexion::fermerConnexion()
{db.close();}
