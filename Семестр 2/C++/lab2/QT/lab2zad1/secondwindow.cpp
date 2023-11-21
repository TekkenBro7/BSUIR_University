#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>
#include <secondwindow.h>
#include <mainwindow.h>

SecondWindow::SecondWindow(List _arr, int _size, QString _a, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    arr = _arr;
    size = _size;
    a = _a;
    ui->setupUi(this);

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
    ui->tableWidget->update();
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
      for (int col = 0; col < ui->tableWidget->columnCount(); ++col)
      {
        QTableWidgetItem* item = ui->tableWidget->item(row, col);
        if (item)
        {
          item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
      }
    }
    if (j == 0)
    {
        QMessageBox::information(this, "ХЗ", "Ничего не найдено");
    }
    else
    QMessageBox::information(this, "УРА", "Найдено");
}

SecondWindow::~SecondWindow()
{
    delete ui;
}


