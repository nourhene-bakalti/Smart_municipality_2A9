#ifndef CITOYENS_H
#define CITOYENS_H
#include <QString>


class citoyens
{
private:
int IdClient;
QString Nom,Prenom;

public:
    citoyens();
    citoyens(int,QString,QString);

    int getIdClient();
    QString getNom();
    QString getPrenom();

    void setIdClient(int);
    void setNom(QString);
    void setPrenom(QString);

};

#endif // CITOYENS_H
