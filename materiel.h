#ifndef MATERIEL_H
#define MATERIEL_H
#include <QSqlQueryModel>
#include <QString>

class materiel
{
public:
    materiel();
    QSqlQueryModel* afficherREFM();
    int chercherREFM(QString);
private:
    QString NomMateriel;
    int refMateriel;

};

#endif // MATERIEL_H
