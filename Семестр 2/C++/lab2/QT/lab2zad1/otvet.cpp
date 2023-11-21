#include "otvet.h"
#include "ui_otvet.h"
#include <QMessageBox>
#include <mainwindow.h>
#include<ui_mainwindow.h>
#include <QMainWindow>

extern int g;
extern QString Famqwe;

Dialog::Dialog(List _arr, QWidget *parent) :
    QDialog(parent),
    ui1(new Ui::Dialog)
{
    arr = _arr;
    ui1->setupUi(this);


    int size = g;
    int j = 0;
    ui1->tableWidget->setRowCount(0);
    for (int i = 0; i < size; i++)
    {
        if (Famqwe == arr[i]->fam)
        {

            ui1->tableWidget->insertRow(j);
            ui1->tableWidget->setItem(j,0,new QTableWidgetItem(arr[i]->country));
            ui1->tableWidget->setItem(j,1,new QTableWidgetItem(arr[i]->komanda));
            ui1->tableWidget->setItem(j,2,new QTableWidgetItem(arr[i]->fam));
            ui1->tableWidget->setItem(j,3,new QTableWidgetItem(arr[i]->nomer));
            ui1->tableWidget->setItem(j,4,new QTableWidgetItem(arr[i]->age));
            ui1->tableWidget->setItem(j,5,new QTableWidgetItem(arr[i]->rost));
            ui1->tableWidget->setItem(j,6,new QTableWidgetItem(arr[i]->ves));
            j++;
        }
    }
    ui1->tableWidget->update();
    if (j == 0)
    {
        QMessageBox::information(this, "ХЗ", "Ничего не найдено");
    }
    else
    QMessageBox::information(this, "УРА", "Найдено");
    return;

}

Dialog::~Dialog()
{
    delete ui1;
}
