#include "firstwindow.h"
#include "ui_firstwindow.h"
#include <QMessageBox>

firstwindow::firstwindow(Vector _arr, int _size, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstwindow)
{
    ui->setupUi(this);
    arr = _arr;
    size = _size;


    int j = 0;
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < size; i++)
    {
        if (arr[i].gotov == "Да" || arr[i].gotov == "да")
        {
            ui->tableWidget->insertRow(j);
            ui->tableWidget->setItem(j,0,new QTableWidgetItem(arr[i].group));
            ui->tableWidget->setItem(j,1,new QTableWidgetItem(arr[i].marka));
            ui->tableWidget->setItem(j,2,new QTableWidgetItem(arr[i].data));
            ui->tableWidget->setItem(j,3,new QTableWidgetItem(arr[i].gotov));
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


firstwindow::~firstwindow()
{
    delete ui;
}
