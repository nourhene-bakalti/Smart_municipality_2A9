#include "connexion.h"
connexion::connexion()
{}

bool connexion::ouvrirconnexion()
{ db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("test-bd");
db.setUserName("Abdou");
db.setPassword("151198");

if(db.open())
    return true;
        return false;

}
void connexion::fermerconnexion()
{db.close();}
