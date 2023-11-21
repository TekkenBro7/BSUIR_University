#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <functions.h>


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



void MainWindow::on_pushButton_clicked()
{
    String str;
    QString main = ui->lineEdit->text();
    const QByteArray stringData = main.toUtf8();
    char text[100];
    text[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text);
    int size = str.strlen(text);
    QString otvet = "Размер: " + QString::number(size);
    ui->textBrowser->setText(otvet);
}

void MainWindow::on_pushButton_2_clicked()
{
   String str;
   int size = ui->spinBox->text().toInt();
   QString main = ui->lineEdit->text();
   const QByteArray stringData = main.toUtf8();
   char text1[100];
   text1[qMin(99,stringData.size())] ='\0';
   std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
   QString main2 = ui->lineEdit_2->text();
   const QByteArray stringData1 = main2.toUtf8();
   char text2[100];
   text2[qMin(99,stringData1.size())] ='\0';
   std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
   str.memcpy(text1,text2,size);
   if(size <= main2.size())
   {
       ui->textBrowser->setText(text1);
   }

}

void MainWindow::on_pushButton_3_clicked()
{
    String str;
    QString main = ui->lineEdit->text();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    str.strcpy(text1,text2);
    ui->textBrowser->setText(text2);
}

void MainWindow::on_pushButton_4_clicked()
{
    String str;
    QString main = ui->lineEdit->text();
    int size = ui->spinBox->text().toInt();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    str.strncpy(text1,text2,size);
    if(size <= main2.size())
    {
        ui->textBrowser->setText(text1);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
   String str;
   QString main = ui->lineEdit->text();
   int size = ui->spinBox->text().toInt();
   const QByteArray stringData = main.toUtf8();
   char text1[100];
   text1[qMin(99,stringData.size())] ='\0';
   std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
   QString main2 = ui->lineEdit_2->text();
   const QByteArray stringData1 = main2.toUtf8();
   char text2[100];
   text2[qMin(99,stringData1.size())] ='\0';
   std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
   str.memmove(text1,text2,size);
   if(size <= main2.size())
   {
    ui->textBrowser->setText(text1);
   }
}

void MainWindow::on_pushButton_6_clicked()
{
    String str;
    QString main = ui->lineEdit->text();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    str.strcat(text1,text2);
    ui->textBrowser->setText(text1);
}

void MainWindow::on_pushButton_7_clicked()
{
    String str;
    QString main = ui->lineEdit->text();
    int size = ui->spinBox->text().toInt();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    str.strncat(text1,text2,size);
    if(size <= main2.size())
    {
        ui->textBrowser->setText(text1);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    String str;
    int size = ui->spinBox->text().toInt();
    QString main = ui->lineEdit->text();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    ui->textBrowser->setText(QString::number(str.memcmp(text1,text2,size)));
}

void MainWindow::on_pushButton_9_clicked()
{
    String str;
    QString main = ui->lineEdit->text();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    ui->textBrowser->setText(QString::number(str.strcmp(text1,text2)));
}

void MainWindow::on_pushButton_10_clicked()
{
    String str;
    int size = ui->spinBox->text().toInt();
    QString main = ui->lineEdit->text();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    ui->textBrowser->setText(QString::number(str.strncmp(text1,text2,size)));
}

void MainWindow::on_pushButton_11_clicked()
{
    String str;
    int size = ui->spinBox->text().toInt();
    QString main = ui->lineEdit->text();
    const QByteArray stringData = main.toUtf8();
    char text1[100];
    text1[qMin(99,stringData.size())] ='\0';
    std::copy(stringData.constBegin(),stringData.constBegin()+qMin(99,stringData.size()),text1);
    QString main2 = ui->lineEdit_2->text();
    const QByteArray stringData1 = main2.toUtf8();
    char text2[100];
    text2[qMin(99,stringData1.size())] ='\0';
    std::copy(stringData1.constBegin(),stringData1.constBegin()+qMin(99,stringData1.size()),text2);
    str.memset(text1,'_',size);
    ui->textBrowser->setText(text1);
}
