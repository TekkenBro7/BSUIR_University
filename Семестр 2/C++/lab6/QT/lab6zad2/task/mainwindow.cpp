#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

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

void MainWindow::on_search_clicked()
{
    int index = ui->comboBox->currentIndex();
    int size = ui->comboBox->currentText().toInt();
    MyHashTable t(index);
    Vector<int> nums(size);
    for(int i = 0; i < size; i++)
    {
        int random = QRandomGenerator::global()->bounded(0, 1000);
        nums[i] = random;
        t.insert(std::to_string(random), i);
    }
    QVector<double> x(size);
    QVector<double> y(size);
    QElapsedTimer timer;
    timer.start();
    for(int i = 0; i < size; i++)
    {
        x[i] = i;
        int num = nums[i];
        timer.restart();
        t.find(std::to_string(num));
        int zxc = abs(timer.nsecsElapsed()) % 1000;
        y[i] = zxc;
    }
    ui->customplot->addGraph();
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->xAxis->setLabel("Операции");
    ui->customplot->yAxis->setLabel("Время(наносекунды)");
    ui->customplot->xAxis->setRange(0, size);
    if(size <= 64)
    {
        ui->customplot->yAxis->setRange(0, size*60);
    }
    else if(size == 128)
    {
        ui->customplot->yAxis->setRange(0, size * 10);
    }
    else
    {
        ui->customplot->yAxis->setRange(0, size);
    }
    ui->customplot->replot();
    return;
}

void MainWindow::on_kolizii_clicked()
{
    int index = ui->comboBox->currentIndex();
    int size = ui->comboBox->currentText().toInt();
    MyHashTable t (index);
    for(int i = 0; i < size; i++)
    {
       t.insert1(std::to_string(i), i);
    }
    QVector<double> x(size);
    QVector<double> y(size);
    QElapsedTimer timer;
    timer.start();
    for(int i = 0; i < size; i++)
    {
        x[i] = i;
        timer.restart();
        t.find1(std::to_string(i));
        y[i] = timer.nsecsElapsed();
    }
    ui->customplot->addGraph();
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->xAxis->setLabel("Операции");
    ui->customplot->yAxis->setLabel("Время(наносекунды)");
    ui->customplot->yAxis->setRange(0,100*size);
    ui->customplot->xAxis->setRange(0,size);
    ui->customplot->replot();
    return;
}
