#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

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


void MainWindow::on_capacity_clicked()
{
    QMessageBox::information(this,"Размер: ",QString::number(a.Size()));
    return;
}


void MainWindow::on_capacity_2_clicked()
{
    QMessageBox::information(this,"ПУСТ?", a.empty() ? QString("Пуст"): QString("Не пуст"));
    return;
}


void MainWindow::on_erase_clicked()
{
    if (a.empty())
    {
        QMessageBox::information(this, "ДА", "Было пусто");
        return;
    }
    a.clear();
    return;
}


void MainWindow::on_push_clicked()
{
    QString str = ui->pushLine->text();
    if (str.isEmpty())
    {
        QMessageBox::critical(this,"Беда","Некорректный ввод");
        return;
    }
    if (str.toInt())
    {
        a.push_back(str.toInt());
        ui->pushLine->clear();
        return;
    }
    else
    {
        QMessageBox::critical(this,"Беда","Некорректный ввод");
        ui->pushLine->clear();
        return;
    }
}


void MainWindow::on_pop_clicked()
{
    QString str = ui->pushLine->text();
    if (str.isEmpty())
    {
        QMessageBox::critical(this,"Беда","Некорректный ввод");
        return;
    }
    if (str.toInt())
    {
        a.push_front(str.toInt());
        ui->pushLine->clear();
        return;
    }
    else
    {
        QMessageBox::critical(this,"Беда","Некорректный ввод");
        ui->pushLine->clear();
        return;
    }
}


void MainWindow::on_empty_clicked()
{
    if(a.empty())
    {
        QMessageBox::warning(this,"Беда","Было пусто");
        return;
    }
    a.pop_back();
    return;
}


void MainWindow::on_size_clicked()
{
    if(a.empty())
    {
        QMessageBox::warning(this,"Беда","Было пусто");
        return;
    }
    a.pop_front();
    return;
}


void MainWindow::on_erase_2_clicked()
{
    ui->output_2->clear();
    QString otvet = "";
    for(int i = 0; i < a.Size(); i++)
    {
        otvet += QString::number(a[i]);
        otvet += " ";
    }
    ui->output_2->setText(otvet);
    return;
}


void MainWindow::on_erase_3_clicked()
{
    ui->output_2->clear();
    QString otvet = "";
    auto it = a.begin();
    for(; it != a.end(); it++)
    {
        otvet += QString::number(*it);
        otvet += " ";
    }
    ui->output_2->setText(otvet);
    return;
}

