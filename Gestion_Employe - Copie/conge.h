#ifndef Conge_H
#define Conge_H

#include <QString>
#include <QSqlQueryModel>
class Conge
{
public:
    Conge();
    Conge(int, int, QString, QString, QString);
    int getid();
    QString getdate();
    QString getnom();
    QString getprenom();
    int getduree();
    void setid(int);
    void setdate(QString);
    void setnom(QString);
    void setprenom(QString);
    void setduree(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString,QString);
    QSqlQueryModel* chercher(QString);
private:
    int id,duree;
    QString nom, prenom, date;
};

#endif // Conge_H
