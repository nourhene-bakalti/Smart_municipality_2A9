#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class equipement
{
public:
    equipement();

    equipement(QString,QString,QString);
    QString get_object();
    QString get_ref();
    QString get_quantite();
    void set_object(QString);
    void set_ref(QString);
    void set_quantite(QString);
    bool ajouterE();
    QSqlQueryModel * afficherE();
    bool supprimerE(QString);
    bool modifierE();
    QSqlQueryModel* chercherE(int,QString);
    QSqlQueryModel * affichercrE();
        QSqlQueryModel * afficherdcE();
        QSqlQueryModel * affichercrER();
            QSqlQueryModel * afficherdcER();
            QSqlQueryModel * affichercrEQ();
                QSqlQueryModel * afficherdcEQ();


private :
    QString objet,ref,quantite;

};

#endif // EQUIPEMENT_H
