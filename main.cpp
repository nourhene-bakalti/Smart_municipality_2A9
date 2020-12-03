#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test= c.ouvrirconnexion();
    MainWindow w;
    if(test)
    {w.show();}
                else
   QMessageBox::information(nullptr, QObject::tr("Database is opent."),
                            QObject::tr("connexion succefull"));









    return a.exec();
}
