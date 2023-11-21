#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <mainwindow.h>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
   delete ui;
}

void Form::slot(QString a, int size, List arr)
{


    int j = 0;
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < size; i++)
    {
        if (a == arr[i]->fam)
        {

            ui->tableWidget->insertRow(j);
            ui->tableWidget->setItem(j,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(j,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(j,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(j,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(j,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(j,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(j,6,new QTableWidgetItem(arr[i]->ves));
            j++;
        }
    }
 //   ui->tableWidget->update();
    if (j == 0)
    {
        QMessageBox::information(this, "ХЗ", "Ничего не найдено");
    }
    else
    QMessageBox::information(this, "УРА", "Найдено");

}
