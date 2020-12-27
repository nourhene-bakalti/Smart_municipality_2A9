#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    c.ouvrirConnexion();
    MainWindow w;

             w.show();


    return a.exec();
}
