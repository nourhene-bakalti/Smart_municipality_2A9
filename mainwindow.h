#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"equipement.h"
#include"fournisseur.h"
#include <QMainWindow>
#include<QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterE_clicked();

    void on_ajouterF_clicked();




    void on_supprimerE_clicked();

    void on_refreshE_clicked();

    void on_refreshF_clicked();

    void on_rechercheE_clicked();

    void on_modificationE_clicked();

    void on_trier_clicked();

    void on_supprimerF_clicked();

    void on_modificationF_clicked();

    void on_rechercheF_clicked();


    void on_trierF_clicked();

private:
    Ui::MainWindow *ui;
    equipement afE;
    fournisseur ih,afF;
     QMediaPlayer * player;
};
#endif // MAINWINDOW_H
