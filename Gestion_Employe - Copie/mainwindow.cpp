#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "conge.h"
#include "stat_employe.h"
#include <QMessageBox>
#include <QPaintEvent>
#include <QTextDocument>
#include <QPdfWriter>
#include <QDebug>
#include <QSqlQuery>
#include <QFileDialog>
#include <QPrinter>
#include <QComboBox>
#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(1, 99999999, this));
    ui->le_cin->setValidator(new QIntValidator(1, 99999999, this));
    ui->le_tel->setValidator(new QIntValidator(19999999, 99999999, this));
    ui->tab_employe->setModel(E.afficher());
    ui->tab_conge->setModel(E.afficher());
    ui->le_chercher_conge->setPlaceholderText("Recherche");
    ui->rechercher->setPlaceholderText("Recherche");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bn_employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_bn_conge_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int cin=ui->le_cin->text().toInt();
    int tel=ui->le_tel->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString position=ui->comboBox->currentText();
    Employe E(id,cin,nom,prenom,position,tel);
    bool test=E.ajouter();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Ajout avec succes.");
        ui->tab_employe->setModel(E.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Employe E1; E1.setid(ui->le_id_supp->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_employe->setModel(E.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void MainWindow::on_pb_ajouter_conge_clicked()
{
    int id=ui->le_id_conge->text().toInt();
    int duree=ui->le_duree->text().toInt();
    QString nom=ui->le_nom_conge->text();
    QString prenom=ui->le_prenom_conge->text();
    QString date=ui->le_date->text();
    Conge E(id,duree,nom,prenom,date);
 bool test=E.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tab_conge->setModel(E.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void MainWindow::on_pb_supprimer_conge_clicked()
{
    Conge E1;
    E1.setid(ui->le_id_supp_conge->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_conge->setModel(E1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void MainWindow::on_pb_modifier_conge_clicked(){

    int id = ui->le_id_conge_mod->text().toInt(); //lineEdit_id_eventmodif
    int duree=ui->le_duree_mod->text().toInt(); //lineEdit_nouv_idsalle
    QString nom= ui->le_nom_conge_mod->text();  //lineEdit_nouv_nom
    QString prenom=ui->le_prenom_conge_mod->text(); //comboBox2
    QString date=ui->le_date_mod->text();
    Conge c8(id,duree,nom,prenom,date);
    bool test=c8.modifier(id,duree,nom,prenom,date);
    QMessageBox msgBox;
        if(test)
           { msgBox.setText("Modification avec succes.");
        ui->tab_conge->setModel(c8.afficher());

        }
        else
            msgBox.setText("Echec de modification");
            msgBox.exec();

            }


void MainWindow::on_pb_modifier_emp_clicked()
{
        QString nom= ui->le_nom_modifier->text();
        int id = ui->le_id_modifier->text().toInt();
        int cin=ui->le_cin_modifier->text().toInt();
        int tel=ui->le_tel->text().toInt();
        QString prenom=ui->le_prenom_modifier->text();
        QString position=ui->le_position_modifier->text();
        Employe e(id,cin,nom,prenom,position,tel);
        bool test=e.modifier(id,cin,nom,prenom,position,tel);
        QMessageBox msgBox;
            if(test)
               { msgBox.setText("Modification avec succes.");
            ui->tab_conge->setModel(e.afficher());

            }
            else
                msgBox.setText("Echec de modification");
                msgBox.exec();

  }

void MainWindow::on_pdf_employe_clicked()
{
        QString strStream;
                QTextStream out(&strStream);

                 const int rowCount = ui->tab_employe->model()->rowCount();
                 const int columnCount = ui->tab_employe->model()->columnCount();
                out <<  "<html>\n"
                "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 <<  QString("<title>%1</title>\n").arg("strTitle")
                                 <<  "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"

                                //     "<align='right'> " << datefich << "</align>"
                                 "<center> <H1>Liste des Employes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                             // headers
                             out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                             out<<"<cellspacing=10 cellpadding=3>";
                             for (int column = 0; column < columnCount; column++)
                                 if (!ui->tab_employe->isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(ui->tab_employe->model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             // data table
                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!ui->tab_employe->isColumnHidden(column)) {
                                         QString data = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";
                             }
                             out <<  "</table> </center>\n"
                                 "</body>\n"
                                 "</html>\n";

                       QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                         if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                        QPrinter printer (QPrinter::PrinterResolution);
                         printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setPaperSize(QPrinter::A4);
                       printer.setOutputFileName(fileName);

                        QTextDocument doc;
                         doc.setHtml(strStream);
                         doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                         doc.print(&printer);

}

void MainWindow::on_pdf_conge_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

             const int rowCount = ui->tab_conge->model()->rowCount();
             const int columnCount = ui->tab_conge->model()->columnCount();
            out <<  "<html>\n"
            "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"

                            //     "<align='right'> " << datefich << "</align>"
                             "<center> <H1>Liste des Conges </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                         // headers
                         out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                         out<<"<cellspacing=10 cellpadding=3>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tab_conge->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tab_conge->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tab_conge->isColumnHidden(column)) {
                                     QString data = ui->tab_conge->model()->data(ui->tab_conge->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n"
                             "</body>\n"
                             "</html>\n";

                   QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                    QPrinter printer (QPrinter::PrinterResolution);
                     printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(fileName);

                    QTextDocument doc;
                     doc.setHtml(strStream);
                     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                     doc.print(&printer);

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    int count=0,count1=0,count2=0 ;
    QSqlQuery requete("select * from employe where position = 'Employe' ") ;
    while(requete.next())
    {
            count++ ;
    }
    QSqlQuery requete1("select * from employe where position = 'Administration' ") ;
    while(requete1.next())
    {
            count1++ ;
    }
    QSqlQuery requete2("select * from employe where position = 'Ouvrier' ") ;
    while(requete2.next())
    {
            count2++ ;
    }

    float nb = count+count1+count2 ;

    float x = ( count * 360 ) / nb ;
    float y = ( count1 * 360 ) / nb;
    float z = ( count2 * 360 ) / nb ;

    if(index == 1){

        QPieSeries *series = new QPieSeries();

            series->append("Employe", x);
            series->append("Administration", y);
            series->append("Ouvrier", z);



            QPieSlice *slice = series->slices().at(1);
            slice->setExploded(true);
            slice->setLabelVisible(true);
            slice->setPen(QPen(Qt::darkGreen, 2)); 
            slice->setBrush(Qt::green);


            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Statistique Employe");


            QChartView *chartview = new QChartView(chart);
            chartview->setParent(ui->stat_employe);
    }
}

void MainWindow::on_le_chercher_conge_textChanged(const QString &arg1)
{
    if(arg1 == "")
        ui->tab_conge->setModel(C.afficher());
    else{
        ui->tab_conge->setModel(C.chercher(ui->le_chercher_conge->text()));
    }
}

void MainWindow::on_rechercher_textChanged(const QString &arg1)
{
    if(arg1 == "")
        ui->tab_employe->setModel(E.afficher());
    else{
        ui->tab_employe->setModel(E.chercher(ui->rechercher->text()));
    }
}
