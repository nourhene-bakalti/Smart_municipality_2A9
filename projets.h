#ifndef PROJETS_H
#define PROJETS_H
#include <QString>

class projets
{
private:
    int NumProjet,Budget,DateDebut,DateFin;
    QString NomProjet,DirecteurProjet,Lieu;
public:
    projets();
    projets(int,int,int,int,QString,QString,QString);
    int getBudget();
    int getNumProjet();
    int getDateDebut();
    int getDateFin();
    QString getNomProjet();
    QString getDirecteurProjet();
    QString getLieu();

    void setBudget(int);
    void setNumProjet(int);
    void setDateDebut(int);
    void setDateFin(int);
    void setNomProjet(QString);
    void setDirecteurProjet(QString);
    void setLieu(QString);

    bool ajouter(int,int,int,int,QString,QString,QString);
};

#endif // PROJETS_H
