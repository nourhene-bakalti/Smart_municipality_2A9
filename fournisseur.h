#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class fournisseur
{
public:
    fournisseur();

   fournisseur(QString,QString,QString);
    QString get_nom();
    QString get_adress();
    QString get_numero();
    void set_nom(QString);
    void set_adress(QString);
    void set_numero(QString);
    bool ajouterF();
    QSqlQueryModel * afficherF();
    bool supprimerF(QString);
    bool modifierF();
    QSqlQueryModel* chercherF(int,QString);
    QSqlQueryModel * affichercrF();
        QSqlQueryModel * afficherdcF();
        QSqlQueryModel * affichercrFN();
            QSqlQueryModel * afficherdcFN();
            QSqlQueryModel * affichercrFM();
                QSqlQueryModel * afficherdcFM();
private :
    QString nom,adress,numero;
   };
#endif // FOURNISSEUR_H
