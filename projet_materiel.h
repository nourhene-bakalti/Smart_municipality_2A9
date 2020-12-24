#ifndef PROJET_MATERIEL_H
#define PROJET_MATERIEL_H
#include <QSqlQueryModel>


class projet_materiel
{
public:
    projet_materiel();
    projet_materiel(int,int);
    int getNumProjet();
    int getrefe();
    void setNumProjet(int);
    void setrefe(int);

    QSqlQueryModel* afficherPM();
    bool inserer();


private:
    int NumProjet,refe;
};

#endif // PROJET_MATERIEL_H
