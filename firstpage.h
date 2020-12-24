#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class firstPage;
}

class firstPage : public QDialog
{
    Q_OBJECT

public:
    explicit firstPage(QWidget *parent = nullptr);
    ~firstPage();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::firstPage *ui;
    MainWindow *mainwindow;
};

#endif // FIRSTPAGE_H
