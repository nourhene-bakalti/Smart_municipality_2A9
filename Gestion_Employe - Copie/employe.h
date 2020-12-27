#ifndef Employe_H
#define Employe_H

#include <QString>
#include <QSqlQueryModel>
class Employe
{
public:
    Employe();
    Employe(int,int,QString,QString,QString,int);
    int getid();
    int getcin();
    int gettel();
    QString getnom();
    QString getprenom();
    QString getposition();
    void setid(int);
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setposition(QString);
    void settel(int);
    bool ajouter();
    QSqlQueryModel * chercher(QString);
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString,QString,int);
private:
    int id,cin,tel;
    QString nom, prenom, position;
};

#endif // Employe_H
