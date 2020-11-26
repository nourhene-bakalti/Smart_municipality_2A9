#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reclamation
{
public:
    Reclamation();
    Reclamation(QString,QString,QString);
    QString get_nom();
    QString get_problem();
    QString get_definition();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom,problem,definition;

};

#endif // COMMANDE_H
