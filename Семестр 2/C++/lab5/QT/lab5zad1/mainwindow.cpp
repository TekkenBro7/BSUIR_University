#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

QueueSort<int> intVector;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_clicked()
{
    QString input = ui->pushLine->text();
    if (input.toInt())
    {
          intVector.push(input.toInt());
          ui->output_2->append(input + " ");
          ui->pushLine->clear();
          return;
    }
    else
    {
          QMessageBox::critical(this,"Беда","Некорректный ввод");
          return;
    }
}


void MainWindow::on_pop_clicked()
{
    if(intVector.empty())
    {
        QMessageBox::warning(this,"Беда","Очередь пуста");
        return;
    }
    intVector.pop();
    ui->output_2->clear();
    for(int i = 0;i < intVector.size();i++)
    {
        ui->output_2->append(QString::number(intVector[i]) + " ");
    }
}


void MainWindow::on_empty_clicked()
{
    QMessageBox::information(this,"ПУСТ?",intVector.empty() ? QString("Пуст"): QString("Не пуст"));
    return;
}


void MainWindow::on_size_clicked()
{
    QMessageBox::information(this,"Размер: ",QString::number(intVector.size()));
    return;
}


void MainWindow::on_erase_clicked()
{
    if(intVector.empty())
    {
        QMessageBox::information(this,"Да", "Вектор пуст");
        return;
    }
    QString str = ui->pushLine->text();
    if (str.isEmpty())
    {
        QMessageBox::information(this,"Back: ",QString::number(intVector.back()));
        return;
    }
    else
    {
        if (!str.toInt())
        {
            QMessageBox::critical(this,"Беда","Некорректный ввод");
            return;
        }
        int num = str.toInt();
        intVector.back() = num;
        ui->output_2->clear();
        for(int i = 0; i < intVector.size(); i++)
        {
            ui->output_2->append(QString::number(intVector[i]));
        }
        QMessageBox::information(this,"Now back: ",QString::number(intVector.back()));
        ui->pushLine->clear();
        return;
    }
}


void MainWindow::on_capacity_clicked()
{
    if(intVector.empty())
    {
        QMessageBox::information(this,"Да", "Вектор пуст");
        return;
    }
    QString str = ui->pushLine->text();
    if (str.isEmpty())
    {
        QMessageBox::information(this,"Front: ",QString::number(intVector.front()));
        return;
    }
    else
    {
        if (!str.toInt())
        {
            QMessageBox::critical(this,"Беда","Некорректный ввод");
            return;
        }
        int num = str.toInt();
        intVector.front() = num;
        ui->output_2->clear();
        for(int i = 0; i < intVector.size(); i++)
        {
            ui->output_2->append(QString::number(intVector[i]));
        }
        QMessageBox::information(this,"Now front: ",QString::number(intVector.back()));
        ui->pushLine->clear();
        return;
    }
}


void MainWindow::on_capacity_2_clicked()
{
    if(intVector.empty())
    {
        QMessageBox::information(this,"Да", "Вектор пуст");
        return;
    }
    intVector.sort();
    ui->output_2->clear();
    for(int i = 0; i < intVector.size(); i++)
    {
        ui->output_2->append(QString::number(intVector[i]));
    }
    QMessageBox::information(this,"Ура", "Отсортировано успешно!");
    return;
}

