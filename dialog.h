#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *Ui;
};

#endif // DIALOG_H
