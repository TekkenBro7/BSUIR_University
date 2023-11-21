#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>

secondwindow::secondwindow(Vector _arr, int _size, QString _a, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    arr = _arr;
    size = _size;
    a = _a;

    int j = 0;
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < size; i++)
    {
        if (a == arr[i].group)
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

secondwindow::~secondwindow()
{
    delete ui;
}
