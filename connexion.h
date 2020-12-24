#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>


class  Connexion
{
private:
    QSqlDatabase db;
public:
     Connexion();
    bool ouvrirConnexion();
    bool fermerConnexion();
};

#endif // CONNEXION_H
