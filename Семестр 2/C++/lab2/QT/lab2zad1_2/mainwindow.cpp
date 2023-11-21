#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <algorithm>
#include <QTextStream>
#include <vector.h>
#include <QMessageBox>
#include <QFile>
#include <firstwindow.h>
#include <secondwindow.h>
#include <thirdwindow.h>

using namespace std;

QString str;
int g = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < 500; i++)
    {
       arr.PopBack();
    }
    for (int i = 0; i < 500; i++)
    {
        arr.pushback("0", "0", "0", "0");
    }
    ui->tableWidget->setRowCount(0);
    g = 0;
    str = QFileDialog::getOpenFileName(this, "Выбрать файл");
    QFile file(str);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int cur=0;
    QTextStream stream(&file);
    QString ans;
    int stat=0;
    QString n;
    int i=0;
    bool check = 1;
            do
            {
                ans=file.readLine();
                int t = ans.length();
                while (i < ans.length() - 1)
                {
                    while (ans[i] != ' ' && i < ans.length() - 1)
                    {
                        n += ans[i];
                        i++;
                        if (i == t)
                        {
                            break;
                        }
                    }
                    if (stat==0)
                    {
                       arr[cur].setGroup(n);
                       for (int i = 0; i < n.size(); i++)
                       {
                           if (n[i] > '9' || n[i] < '0' || (i == 0 && n[i] == '0'))
                           {
                               check = 0;
                           }
                       }
                       n="";
                       stat++;
                    }
                    else if (stat==1)
                    {
                        arr[cur].setMarka(n);
                        n="";
                        stat++;
                    }
                    else if (stat==2)
                    {
                        arr[cur].setData(n);
                        if (n.length() != 10)
                        {
                           check = 0;
                           break;
                        }
                        if (n[2] != '.' || n[5] != '.')
                        {
                               check = 0;
                               break;
                        }
                        int days=n[0].digitValue()*10+n[1].digitValue();
                        int mounth=n[3].digitValue()*10+n[4].digitValue();
                        int year=n[6].digitValue()*1000+n[7].digitValue()*100+n[8].digitValue()*10+n[9].digitValue();
                        if (n.length() != 10 || !(QDate::isValid(year, mounth, days)))
                        {
                            check = 0;
                        }
                        if (n[0] > '9' || n[0] < '0' || n[1] > '9' || n[1] < '0' || n[3] > '9' || n[3] < '0' || n[4] > '9' || n[4] < '0' || n[6] > '9' || n[6] < '0' || n[7] > '9' || n[7] < '0' || n[8] > '9' || n[8] < '0' || n[9] > '9' || n[9] < '0')
                        {
                            check = 0;
                        }
                        if (n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0)
                        {
                            check = 0;
                        }
                        n="";
                        stat++;
                    }
                    else if (stat==3)
                    {
                        if (n != "Да" && n != "да" && n != "нет" && n != "Нет")
                        {
                            check = 0;
                        }
                        arr[cur].setGotov(n);
                        n="";
                        stat++;
                    }
                    i++;
            }
                if (!ans.isEmpty())
                {
                    g++;
                }
            ans="";
            i=0;
            n="";
            cur++;
            stat=0;

        } while (!file.atEnd());
    if (file.isOpen() && check == true)
    {
    for(int i = 0;i < g;i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
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
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    if(g == 0)
    {
        QMessageBox::critical(this, "ФАЙЛ", "Файл пуст");
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        return;
    }
    else
    {
        QMessageBox::information(this, "Ура", "Выполнено успешно");
        return;
    }
    }
    else
    {
        QMessageBox::critical(this, "Беда", "Потрачено");
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        return;
    }
        file.close();
}




void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this, "Пока", "Программа завершена");
    QApplication::quit();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->setRowCount(0);
    int i = 0;
    while (i < g)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
        i++;
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
    QMessageBox::information(this, "УРА", "Выведено успешно");
    return;
}

bool MainWindow::stt(QString s1, QString s2)
{
    int min;
    if (s1.length() > s2.length())
    {
         min = s2.length();
    }
    else
    {
        min = s1.length();
    }
    for (int i = 0; i < min; i++)
    {
        if (s1[i] < s2[i])
        {
            return false;

        }
        else if (s1[i] > s2[i])
        {
            return true;
        }
    }
    if (s1.length() > s2.length())
    {
        return false;
    }
    else if (s1.length() == s2.length())
    {
        return true;
    }
    else
    {
        return true;
    }

}

Vector SortByStaj(Vector b, int position, int t)
{
    for (int i = 0; i < t; i++)
    {
        int curretly = -1;
        QString str = b[i].data;
        QString New = "";
        QString s = "";
        QString s2 = "";
        s += str[3];
        s += str[4];
        s2 += str[0];
        s2 += str[1];
        New += str[6];
        New += str[7];
        New += str[8];
        New += str[9];
        int min = New.toInt();
        int min2 = s.toInt();
        int min4 = s2.toInt();
        for (int q = i + 1; q < t; q++)
        {
          QString str1 = b[q].data;
          QString New1 = "";
          QString s1 = "";
          QString s3 = "";
          s1 += str1[3];
          s1 += str1[4];
          s3 += str1[0];
          s3 += str1[1];
          New1 += str1[6];
          New1 += str1[7];
          New1 += str1[8];
          New1 += str1[9];
          int min1 = New1.toInt();
          int min3 = s1.toInt();
          int min5 = s3.toInt();
          if (min1 > min || (min1 == min && min3 > min2) || (min1 == min && min3 == min2 && min5 > min4))
          {
            curretly = q;
          }
        }

        if (curretly != -1)
        {
          //std::swap(b[i], b[curretly]);
        }
    }
    return b;
}

void MainWindow::on_pushButton_8_clicked()
{
    int pro = ui->radioButton->isChecked();
    int zad = ui->radioButton_2->isChecked();
    int fioisp = ui->radioButton_3->isChecked();
    int fioruk = ui->radioButton_4->isChecked();

    if (pro == 1)
    {

        int size=0;
        size = g;
        int num1;
        int num2;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                num1 = arr[j].group.toInt();
                num2 = arr[j+1].group.toInt();
                if (num1 > num2)
                {
                    QString f;
                    f = arr[j].group;
                    arr[j].group = arr[j+1].group;
                    arr[j+1].group = f;

                    f = arr[j].marka;
                    arr[j].marka = arr[j+1].marka;
                    arr[j + 1].marka = f;

                    f = arr[j].data;
                    arr[j].data = arr[j+1].data;
                    arr[j+1].data = f;

                    f = arr[j].gotov;
                    arr[j].gotov = arr[j+1].gotov;
                    arr[j+1].gotov = f;
                }
            }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
            stream << arr[i].group;
            stream << ' ';
            stream << arr[i].marka;
            stream << ' ';
            stream << arr[i].data;
            stream << ' ';
            stream << arr[i].gotov;
            stream << ' ';
            if (i + 1 == g)
            {
                break;
            }
            stream << '\n';
            i++;
         }
        file.close();
        ui->tableWidget->setRowCount(0);
        i = 0;
        while (i < g)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
            i++;
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
        QMessageBox::information(this, "УРА", "Отсортировано успешно");
        return;
    }


    else if (zad == 1)
    {
        int size=0;
        size = g;
        for(int i = 1; i < size; i++)
        {
         for(int j = i; j > 0 && stt(arr[j-1].marka, arr[j].marka); j--)
          {
             QString f;
             f = arr[j-1].group;
             arr[j-1].group = arr[j].group;
             arr[j].group = f;

             f = arr[j-1].marka;
             arr[j-1].marka = arr[j].marka;
             arr[j].marka = f;

             f = arr[j-1].data;
             arr[j-1].data = arr[j].data;
             arr[j].data = f;

             f = arr[j-1].gotov;
             arr[j-1].gotov = arr[j].gotov;
             arr[j].gotov = f;
          }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
            stream << arr[i].group;
            stream << ' ';
            stream << arr[i].marka;
            stream << ' ';
            stream << arr[i].data;
            stream << ' ';
            stream << arr[i].gotov;
            stream << ' ';
            if (i + 1 == g)
            {
                break;
            }
            stream << '\n';
            i++;
         }
        file.close();
        ui->tableWidget->setRowCount(0);
        i = 0;
        while (i < g)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
            i++;
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
        QMessageBox::information(this, "УРА", "Отсортировано успешно");
        return;
    }


    else if (fioisp == 1)
    {
        int size=0;
        size = g;

        // хз
       arr = SortByStaj(arr, 1, size);

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i].group;
            stream << ' ';
            stream << arr[i].marka;
            stream << ' ';
            stream << arr[i].data;
            stream << ' ';
            stream << arr[i].gotov;
            stream << ' ';
            if (i + 1 == g)
            {
                break;
            }
            stream << '\n';
            i++;
         }
        file.close();
        ui->tableWidget->setRowCount(0);
        i = 0;
        while (i < g)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
            i++;
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
        QMessageBox::information(this, "УРА", "Отсортировано успешно");
        return;
    }
    else if (fioruk == 1)
    {
        int size=0;
        size = g;
        for(int i = 0; i < size - 1; i++)
        {
     //    for(int j = i; j > 0 && stt(arr[j-1].gotov, arr[j].gotov); j--)
     //     {

            for (int j = 0; j < size - i - 1; j++)
            {
                if ((arr[j].gotov == "Нет" || arr[j].gotov == "нет") && (arr[j+1].gotov == "Да" || arr[j+1].gotov == "да"))
                {

                 QString f;
                 f = arr[j].group;
                 arr[j].group = arr[j + 1].group;
                 arr[j + 1].group = f;

                 f = arr[j].marka;
                 arr[j].marka = arr[j+1].marka;
                 arr[j+1].marka = f;

                 f = arr[j].data;
                 arr[j].data = arr[j+1].data;
                 arr[j+1].data = f;

                 f = arr[j].gotov;
                 arr[j].gotov = arr[j+1].gotov;
                 arr[j+1].gotov = f;
           }
                }
      //  }
        }
        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i].group;
            stream << ' ';
            stream << arr[i].marka;
            stream << ' ';
            stream << arr[i].data;
            stream << ' ';
            stream << arr[i].gotov;
            stream << ' ';
            if (i + 1 == g)
            {
                break;
            }
            stream << '\n';
            i++;
         }
        file.close();
        ui->tableWidget->setRowCount(0);
        i = 0;
        while (i < g)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
            i++;
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
        QMessageBox::information(this, "УРА", "Отсортировано успешно");
        return;
    }
    else
    {
        QMessageBox::critical(this, "БЕДА", "Ничего не нажато");
        return;
    }
}





void MainWindow::on_pushButton_2_clicked()
{
    QString groupp = ui->lineEdit_7->text();
    QString markaa = ui->lineEdit_8->text();
    QString dataa = ui->lineEdit_9->text();
    QString gotovv = ui->lineEdit_10->text();

    int size = 0;
    size = g;
    int check = 1;
    QString n;
    n = groupp;
    if(n.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] > '9' || n[i] < '0' || (i == 0 && n[i] == '0'))
        {
            check = 0;
        }
    }
    n = markaa;
    if(n.isEmpty())
    {
        check = 0;
    }
    n = dataa;
    if (n.isEmpty())
    {
        check = 0;
    }
    if (n.length() != 10)
    {
       check = 0;
    }
    if (n[2] != '.' || n[5] != '.')
    {
           check = 0;
    }
    int days=n[0].digitValue()*10+n[1].digitValue();
    int mounth=n[3].digitValue()*10+n[4].digitValue();
    int year=n[6].digitValue()*1000+n[7].digitValue()*100+n[8].digitValue()*10+n[9].digitValue();
    if (n.length() != 10 || !(QDate::isValid(year, mounth, days)))
    {
        check = 0;
    }
    if (n[0] > '9' || n[0] < '0' || n[1] > '9' || n[1] < '0' || n[3] > '9' || n[3] < '0' || n[4] > '9' || n[4] < '0' || n[6] > '9' || n[6] < '0' || n[7] > '9' || n[7] < '0' || n[8] > '9' || n[8] < '0' || n[9] > '9' || n[9] < '0')
    {
        check = 0;
    }
    if (n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0)
    {
        check = 0;
    }
    n = gotovv;
    if(n.isEmpty())
    {
        check = 0;
    }
    if (n != "Да" && n != "да" && n != "нет" && n != "Нет")
    {
        check = 0;
    }
    if (check == 0)
    {
        QMessageBox::critical(this, "БЕДА", "Неправильная информация");
        return;
    }
    else
    {
        size = g;
       arr[size].setGroup(groupp);
       arr[size].setMarka(markaa);
       arr[size].setData(dataa);
       arr[size].setGotov(gotovv);
       ui->tableWidget->setRowCount(0);
       QFile file(str);
       file.open(QIODevice::ReadWrite | QIODevice::Text);
       QTextStream stream(&file);
       int j = 0;
       QString line;
       while (j != g + 1)
       {
           line = stream.readLine();
           j++;
       }
       stream << '\n';
       stream << groupp;
       stream << ' ';
       stream << markaa;
       stream << ' ';
       stream << dataa;
       stream << ' ';
       stream << gotovv;
    //   stream << '\n';
       g++;
       int i = 0;
       while (i < g)
       {
           ui->tableWidget->insertRow(i);
           ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
           ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
           i++;
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
       QMessageBox::information(this, "УРА", "Успешно");
       return;
   }
}











void MainWindow::on_pushButton_9_clicked()
{
    int size = g;
    firstwindow window(arr, size);
    window.setModal(true);
    window.exec();

    return;
}


void MainWindow::on_pushButton_10_clicked()
{
    QString groupp = ui->lineEdit_21->text();
    QString n;
    n = groupp;
    if(n.isEmpty())
    {
        QMessageBox::critical(this, "БЕДА", "Ничего не введено");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] > '9' || n[i] < '0' || (i == 0 && n[i] == '0'))
        {
            QMessageBox::critical(this, "БЕДА", "Ошибка");
            return;
        }
    }

    int size = g;
    secondwindow window(arr, size, groupp);
    window.setModal(true);
    window.exec();

    return;
}


void MainWindow::on_pushButton_6_clicked()
{
    QString nomer = ui->lineEdit_20->text();
    int s = g;
    if (nomer.isEmpty())
    {
        QMessageBox::critical(this, "БЕДА", "Ничего не введено");
        return;
    }
    if (s < nomer.toInt() || nomer.toInt() < 1)
    {
        QMessageBox::critical(this, "Ошибка", "Нет такого номера");
        return;
    }
    int siz = nomer.toInt();
    thirdwindow window(arr, s, siz);
    window.setModal(true);
    window.exec();

    return;
}


void MainWindow::on_pushButton_4_clicked()
{
    QString groupp = ui->lineEdit_7->text();
    QString markaa = ui->lineEdit_8->text();
    QString dataa = ui->lineEdit_9->text();
    QString gotovv = ui->lineEdit_10->text();

    int check = 1;
    QString n;
    n = groupp;
    if(n.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] > '9' || n[i] < '0' || (i == 0 && n[i] == '0'))
        {
            check = 0;
        }
    }
    n = markaa;
    if(n.isEmpty())
    {
        check = 0;
    }
    n = dataa;
    if (n.isEmpty())
    {
        check = 0;
    }
    if (n.length() != 10)
    {
       check = 0;
    }
    if (n[2] != '.' || n[5] != '.')
    {
           check = 0;
    }
    int days=n[0].digitValue()*10+n[1].digitValue();
    int mounth=n[3].digitValue()*10+n[4].digitValue();
    int year=n[6].digitValue()*1000+n[7].digitValue()*100+n[8].digitValue()*10+n[9].digitValue();
    if (n.length() != 10 || !(QDate::isValid(year, mounth, days)))
    {
        check = 0;
    }
    if (n[0] > '9' || n[0] < '0' || n[1] > '9' || n[1] < '0' || n[3] > '9' || n[3] < '0' || n[4] > '9' || n[4] < '0' || n[6] > '9' || n[6] < '0' || n[7] > '9' || n[7] < '0' || n[8] > '9' || n[8] < '0' || n[9] > '9' || n[9] < '0')
    {
        check = 0;
    }
    if (n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0)
    {
        check = 0;
    }
    n = gotovv;
    if(n.isEmpty())
    {
        check = 0;
    }
    if (n != "Да" && n != "да" && n != "нет" && n != "Нет")
    {
        check = 0;
    }
    if (check == 0)
    {
        QMessageBox::critical(this, "БЕДА", "Неправильная информация");
        return;
    }
    else
    {
        int s = g;
        QString numm = ui->lineEdit_19->text();
        if (s < numm.toInt() || numm.toInt() < 1)
        {
            QMessageBox::critical(this, "Ошибка", "Нет такого номера");
            return;
        }
        int siz = numm.toInt();
        arr[siz - 1].setGroup(groupp);
        arr[siz - 1].setMarka(markaa);
        arr[siz - 1].setData(dataa);
        arr[siz - 1].setGotov(gotovv);
        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i].group;
            stream << ' ';
            stream << arr[i].marka;
            stream << ' ';
            stream << arr[i].data;
            stream << ' ';
            stream << arr[i].gotov;
            stream << ' ';
            if (i + 1 == g)
            {
                break;
            }
            stream << '\n';
            i++;
         }
        file.close();
        ui->tableWidget->setRowCount(0);
        i = 0;
        while (i < g)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
            i++;
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
        QMessageBox::information(this, "УРА", "Изменено успешно");
        return;
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QString nom = ui->lineEdit_20->text();
    int s = g;
    if (s == 0)
    {
        QMessageBox::information(this, "ОП", "В файле нет информации");
        return;
    }
    if (s < nom.toInt() || nom.toInt() < 1)
    {
        QMessageBox::critical(this, "Беда", "Ошибка");
        return;
    }
    QFile file(str);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file);
    arr.Erase(nom.toInt() - 1);
    g--;
    ui->tableWidget->setRowCount(0);
    int i = 0;
    while (i < g)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].group));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marka));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i].data));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i].gotov));
        i++;
    }
    ui->tableWidget->update();
    i = 0;
    while (true)
    {
        if (g == 0)
        {
            break;
        }
        stream << arr[i].group;
        stream << ' ';
        stream << arr[i].marka;
        stream << ' ';
        stream << arr[i].data;
        stream << ' ';
        stream << arr[i].gotov;
        stream << ' ';
        if (i + 1 == g)
        {
            break;
        }
        stream << '\n';
        i++;
     }
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
    if (g == 1)
    {
        QMessageBox::information(this, "ОП", "Файл измненён");
        return;
    }
    file.close();
    QMessageBox::information(this, "ОП", "Файл измненён");
}
