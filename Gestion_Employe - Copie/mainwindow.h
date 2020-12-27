#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include "conge.h"
#include "stat_employe.h"
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_conge_clicked();

    void on_pb_supprimer_conge_clicked();

    void on_pb_modifier_conge_clicked();



    void on_pb_modifier_emp_clicked();

    void on_bn_conge_clicked();

    void on_bn_employe_clicked();

    void on_pdf_employe_clicked();

    void on_pdf_conge_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_le_chercher_conge_textChanged(const QString &arg1);

    void on_rechercher_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Statistique_employe *se;
    Employe E;
    Conge C;
};
#endif // MAINWINDOW_H
