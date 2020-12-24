#ifndef PROJETS_H
#define PROJETS_H
#include <QString>
#include <QSqlQueryModel>
class projets
{
private:
    int NumProjet,Budget;
    QString NomProjet,DirecteurProjet,Lieu,DateDebut,DateFin;
public:
    projets();
    projets(int,int,QString,QString,QString,QString,QString);
    int getBudget();
    int getNumProjet();
    QString getDateDebut();
    QString getDateFin();
    QString getNomProjet();
    QString getDirecteurProjet();
    QString getLieu();
QSqlQueryModel* afficheridp();
    void setBudget(int);
    void setNumProjet(int);
    void setDateDebut(QString);
    void setDateFin(QString);
    void setNomProjet(QString);
    void setDirecteurProjet(QString);
    void setLieu(QString);

    bool ajouter(int,int,QString,QString,QString,QString,QString);
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
     QSqlQueryModel * chercher(int,QString);
};

#endif // PROJETS_H
