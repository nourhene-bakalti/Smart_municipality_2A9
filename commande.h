#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Commande
{
public:
    Commande();
    Commande(QString,int,int,int);
    QString get_piece();
    int get_referance();
    int get_nombre();
    int get_prix();
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
private:
    QString piece;
    int referance,nombre,prix;


};

#endif // COMMANDE_H
