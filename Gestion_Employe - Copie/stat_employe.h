#ifndef STAT_EMPLOYE_H
#define STAT_EMPLOYE_H


#include <QDialog>
#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>
namespace Ui {
 class MainWindow;
}

class Statistique_employe : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique_employe(QWidget *parent = nullptr);
    ~Statistique_employe();
    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;

    void paintEvent(QPaintEvent *) ;

private:
    Ui::MainWindow *ui;
};

#endif // STAT_EMPLOYE_H
