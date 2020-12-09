#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <QString>

class operations
{
private:
  int   NumOperation, DateOperation, IdClient;
   QString Nom, Prenom;


public:
    operations();
    operations(int,int,int,QString,QString);

    int getNumOperation();
    int getDateOperation();
    int getIdClient();
    QString getNom();
    QString getPrenom();

    void setNumOperation(int);
    void setDateOperation(int);
    void setIdClient(int);
    void setNom(QString);
    void setPrenom(QString);


    bool ajouter(int,int,int,QString,QString);
};

#endif // OPERATIONS_H
