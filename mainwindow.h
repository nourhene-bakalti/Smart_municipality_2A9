#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "projets.h"
#include "operations.h"
#include "arduino.h"
#include "materiel.h"
#include "projet_materiel.h"

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
    void on_BoutonAjouter_clicked();


    void on_boutonSuppProjet_clicked();

    void on_Button_modif_projet__clicked();

    void on_Button_supp_op_clicked();

    void on_Button_modif_op_clicked();

    void on_ButtonAjouter_Operation_2_clicked();


    void on_pushButton_chercherOP_clicked();

    void on_affiche_tout_clicked();

    void on_pushButton_chercherPR_clicked();

    void on_afficherPR_clicked();

    void on_pushButton_materiel_2_clicked();

    void on_button_affecter_clicked();

private:
    Ui::MainWindow *ui;
    projets p;
    operations o;
  materiel m;
    QByteArray Data;
    Arduino A;
    projet_materiel pm;

};
#endif // MAINWINDOW_H
