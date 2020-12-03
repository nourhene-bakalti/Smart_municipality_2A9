#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new ui::Dialog)
{
    ui->setup(this);
}

Dialog::~Dialog()
{
    delete ui;
}
