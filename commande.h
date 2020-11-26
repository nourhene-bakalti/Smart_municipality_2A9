#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Commande
{
public:
    Commande();
    Commande(int,int,int,QString);
    QString get_piece();
    int get_referance();
    int get_nombre();
    int get_prix();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString piece;
    int referance,nombre,prix;
};

#endif // COMMANDE_H
