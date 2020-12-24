#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <QString>
#include <QSqlQueryModel>

class operations
{
private:
  int   NumOperation, IdClient;
   QString DateOperation,TypeOperation;


public:
    operations();
    operations(int,QString,int,QString);

    int getNumOperation();
    QString getDateOperation();
    int getIdClient();
    QString getTypeOperation();


    void setNumOperation(int);
    void setDateOperation(QString);
    void setIdClient(int);
    void setTypeOperation(QString);



    bool ajouter();

    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel *afficher_idclient();
    QSqlQueryModel * chercher(int,QString);
};

#endif // OPERATIONS_H
