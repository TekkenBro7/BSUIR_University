#include "fifthwindow.h"
#include "ui_fifthwindow.h"
#include <QMessageBox>

fifthwindow::fifthwindow(List _arr, int _size, double _rostt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fifthwindow)
{
    ui->setupUi(this);
    arr = _arr;
    size = _size;
    rostt = _rostt;
    int j = 0;
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < size; i++)
    {
        if (rostt <= arr[i]->rost.toDouble())
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

fifthwindow::~fifthwindow()
{
    delete ui;
}
