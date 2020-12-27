#include "stat_employe.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

Statistique_employe::Statistique_employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
}

Statistique_employe::~Statistique_employe()
{
    delete ui;
}
int Statistique_employe::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from employe where position = 'Administration' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statistique_employe::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from employe where position = 'Employe' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statistique_employe::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from employe where position = 'Ouvrier' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}

void Statistique_employe::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    //cout<<b<<endl ;
    int c=Statistique_partie3();
    // cout<<c<<endl ;
    int d=Statistique_partie4();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;

    QPainter painter(this);
    QRectF size=QRectF(0,0,500,500);
    setMinimumSize(500,500);

    painter.setBrush(Qt::gray);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("Administration");
    painter.setBrush(Qt::magenta);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("Employe");
    painter.setBrush(Qt::cyan);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("Ouvier");
    qDebug() << this;
}
