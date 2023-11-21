#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <list.h>
#include <QMessageBox>
#include "secondwindow.h"
#include <thirdwindow.h>
#include <fourthwindow.h>
#include <fifthwindow.h>

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
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()      // Чтение с файла
{
    for (int i = 0; i < 500; i++)
    {
        arr.pop_front();
    }
    for (int i = 0; i < 500; i++)
    {
        arr.push_back("0", "0", "0", "0", "0", "0", "0");
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
    bool check = true;
            do
            {
                ans=file.readLine();
                int t = ans.length();
                while (i < ans.length() - 1)
                {
                    while (ans[i] != ' ' && i < ans.length())
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
                        for (int i = 0; i < n.size(); i++)
                        {
                         if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                         {
                             check = false;
                         }
                        }
                       arr[cur]->setCountry(n);
                       n="";
                       stat++;
                    }
                    else if (stat==1)
                    {
                        arr[cur]->setKomanda(n);
                        n="";
                        stat++;
                    }
                    else if (stat==2)
                    {
                        for (int i = 0; i < n.size(); i++)
                        {
                         if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                         {
                             check = false;
                         }
                        }
                        arr[cur]->setFam(n);
                        n="";
                        stat++;
                    }
                    else if (stat==3)
                    {
                        int num = n.toInt();
                        for (int i = 0; i < n.size(); i++)
                        {
                         if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                         {
                             check = false;
                         }
                         if (num == 0)
                         {
                             check = false;
                             break;
                         }
                        }
                        n = n.number(num);
                        arr[cur]->setNomer(n);
                        n="";
                        stat++;
                    }
                    else if (stat==4)
                    {
                        int num = n.toInt();
                        for (int i = 0; i < n.size(); i++)
                        {
                         if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                         {
                             check = false;
                         }
                         if (num == 0)
                         {
                             check = false;
                             break;
                         }
                        }
                        n = n.number(num);
                        arr[cur]->setAge(n);
                        n="";
                        stat++;
                    }
                    else if (stat==5)
                    {
                        double num = n.toDouble();
                        for (int i = 0; i < n.size(); i++)
                        {
                         if ((n[i] < '0' || n[i] > '9') || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                         {
                             check = false;
                         }
                         if (num == 0)
                         {
                             check = false;
                             break;
                         }
                        }
                        n = n.number(num);
                        arr[cur]->setRost(n);
                        n="";
                        stat++;
                    }
                    else if (stat == 6)
                    {
                        double num = n.toDouble();
                        for (int i = 0; i < n.size() - 1; i++)
                        {
                         if ((n[i] < '0' || n[i] > '9')|| n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                         {
                             check = false;
                         }
                         if (num == 0)
                         {
                             check = false;
                             break;
                         }
                        }
                        n = n.number(num);
                        arr[cur]->setVes(n);
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
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_14->setEnabled(true);
    if(g == 0)
    {
        QMessageBox::information(this, "ФАЙЛ", "Файл пуст, но можно работать");
    }
    else
    {
        QMessageBox::information(this, "Ура", "Выполнено успешно");
    }
    }
    else
    {
        QMessageBox::critical(this, "Беда", "Потрачено");    
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_13->setEnabled(false);
        ui->pushButton_14->setEnabled(false);
    }
        file.close();
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Пока", "Программа завершена");
    QApplication::quit();
}


void MainWindow::on_pushButton_2_clicked()  // Добавление
{
    QString country = ui->lineEdit_7->text();
    QString komanda = ui->lineEdit_8->text();
    QString famil = ui->lineEdit_9->text();
    QString nomer = ui->lineEdit_10->text();
    QString age = ui->lineEdit_11->text();
    QString rost = ui->lineEdit_12->text();
    QString ves = ui->lineEdit_13->text();

    QString n = country;
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = komanda;
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    n = famil;
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = nomer;
    int num = n.toInt();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
     if (num == 0)
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = age;
    num = n.toInt();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
     if (num == 0)
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = rost;
    num = n.toInt();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
     if (num == 0)
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = ves;
    num = n.toDouble();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
   for (int i = 0; i < n.size() - 1; i++)
   {
    if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
        return;
    }
    if (num == 0)
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
        return;
    }
   }
    int size = 0;
    size = g;
    ui->tableWidget->setRowCount(0);
    arr[size]->setCountry(country);
    arr[size]->setKomanda(komanda);
    arr[size]->setFam(famil);
    arr[size]->setNomer(nomer);
    arr[size]->setAge(age);
    arr[size]->setRost(rost);
    arr[size]->setVes(ves);
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
    stream << country;
    stream << ' ';
    stream << komanda;
    stream << ' ';
    stream << famil;
    stream << ' ';
    stream << nomer;
    stream << ' ';
    stream << age;
    stream << ' ';
    stream << rost;
    stream << ' ';
    stream << ves;
 //   stream << '\n';
    g++;

    int i = 0;
    while (i < g)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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

    file.close();
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

void MainWindow::on_pushButton_8_clicked()  // Сортировка
{
    int pro = ui->radioButton->isChecked();
    int zad = ui->radioButton_2->isChecked();
    int fioisp = ui->radioButton_3->isChecked();
    int fioruk = ui->radioButton_4->isChecked();
    int dayn = ui->radioButton_5->isChecked();
    int daye = ui->radioButton_6->isChecked();
    int dar = ui->radioButton_7->isChecked();

    if (pro == 1)
    {
        int size=0;
        size = g;
        for(int i = 1; i < size; i++)
        {
         for(int j = i; j > 0 && stt(arr[j-1]->country, arr[j]->country); j--)
          {
            QString f;
            f = arr[j-1]->country;
            arr[j-1]->country = arr[j]->country;
            arr[j]->country = f;

            f = arr[j-1]->komanda;
            arr[j-1]->komanda = arr[j]->komanda;
            arr[j]->komanda = f;

            f = arr[j-1]->fam;
            arr[j-1]->fam = arr[j]->fam;
            arr[j]->fam = f;

            f = arr[j-1]->nomer;
            arr[j-1]->nomer = arr[j]->nomer;
            arr[j]->nomer = f;

            f = arr[j-1]->age;
            arr[j-1]->age = arr[j]->age;
            arr[j]->age = f;

            f = arr[j-1]->rost;
            arr[j-1]->rost = arr[j]->rost;
            arr[j]->rost = f;

            f = arr[j-1]->ves;
            arr[j-1]->ves = arr[j]->ves;
            arr[j]->ves = f;

          }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
            stream << arr[i]->country;
            stream << ' ';
            stream << arr[i]->komanda;
            stream << ' ';
            stream << arr[i]->fam;
            stream << ' ';
            stream << arr[i]->nomer;
            stream << ' ';
            stream << arr[i]->age;
            stream << ' ';
            stream << arr[i]->rost;
            stream << ' ';
            stream << arr[i]->ves;
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
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
         for(int j = i; j > 0 && stt(arr[j-1]->komanda, arr[j]->komanda); j--)
          {
             QString f;
             f = arr[j-1]->country;
             arr[j-1]->country = arr[j]->country;
             arr[j]->country = f;

             f = arr[j-1]->komanda;
             arr[j-1]->komanda = arr[j]->komanda;
             arr[j]->komanda = f;

             f = arr[j-1]->fam;
             arr[j-1]->fam = arr[j]->fam;
             arr[j]->fam = f;

             f = arr[j-1]->nomer;
             arr[j-1]->nomer = arr[j]->nomer;
             arr[j]->nomer = f;

             f = arr[j-1]->age;
             arr[j-1]->age = arr[j]->age;
             arr[j]->age = f;

             f = arr[j-1]->rost;
             arr[j-1]->rost = arr[j]->rost;
             arr[j]->rost = f;

             f = arr[j-1]->ves;
             arr[j-1]->ves = arr[j]->ves;
             arr[j]->ves = f;
          }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
            stream << arr[i]->country;
            stream << ' ';
            stream << arr[i]->komanda;
            stream << ' ';
            stream << arr[i]->fam;
            stream << ' ';
            stream << arr[i]->nomer;
            stream << ' ';
            stream << arr[i]->age;
            stream << ' ';
            stream << arr[i]->rost;
            stream << ' ';
            stream << arr[i]->ves;
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
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
        for(int i = 1; i < size; i++)
        {
         for(int j = i; j > 0 && stt(arr[j-1]->fam, arr[j]->fam); j--)
          {
             QString f;
             f = arr[j-1]->country;
             arr[j-1]->country = arr[j]->country;
             arr[j]->country = f;

             f = arr[j-1]->komanda;
             arr[j-1]->komanda = arr[j]->komanda;
             arr[j]->komanda = f;

             f = arr[j-1]->fam;
             arr[j-1]->fam = arr[j]->fam;
             arr[j]->fam = f;

             f = arr[j-1]->nomer;
             arr[j-1]->nomer = arr[j]->nomer;
             arr[j]->nomer = f;

             f = arr[j-1]->age;
             arr[j-1]->age = arr[j]->age;
             arr[j]->age = f;

             f = arr[j-1]->rost;
             arr[j-1]->rost = arr[j]->rost;
             arr[j]->rost = f;

             f = arr[j-1]->ves;
             arr[j-1]->ves = arr[j]->ves;
             arr[j]->ves = f;
          }
        }
        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i]->country;
            stream << ' ';
            stream << arr[i]->komanda;
            stream << ' ';
            stream << arr[i]->fam;
            stream << ' ';
            stream << arr[i]->nomer;
            stream << ' ';
            stream << arr[i]->age;
            stream << ' ';
            stream << arr[i]->rost;
            stream << ' ';
            stream << arr[i]->ves;
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
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
        int num1;
        int num2;
        for (int i = 0; i < size - 1; i++)
        {
                for (int j = 0; j < size - i - 1; j++)
                {
                    num1 = arr[j]->nomer.toInt();
                    num2 = arr[j+1]->nomer.toInt();
                    if (num1 > num2)
                    {
                        QString f;
                        f = arr[j]->country;
                        arr[j]->country = arr[j+1]->country;
                        arr[j+1]->country = f;

                        f = arr[j]->komanda;
                        arr[j]->komanda = arr[j+1]->komanda;
                        arr[j + 1]->komanda = f;

                        f = arr[j]->fam;
                        arr[j]->fam = arr[j+1]->fam;
                        arr[j+1]->fam = f;

                        f = arr[j]->nomer;
                        arr[j]->nomer = arr[j+1]->nomer;
                        arr[j+1]->nomer = f;

                        f = arr[j]->age;
                        arr[j]->age = arr[j+1]->age;
                        arr[j+1]->age = f;

                        f = arr[j]->rost;
                        arr[j]->rost = arr[j+1]->rost;
                        arr[j+1]->rost = f;

                        f = arr[j]->ves;
                        arr[j]->ves = arr[j+1]->ves;
                        arr[j+1]->ves = f;
                    }
                }
        }
        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i]->country;
            stream << ' ';
            stream << arr[i]->komanda;
            stream << ' ';
            stream << arr[i]->fam;
            stream << ' ';
            stream << arr[i]->nomer;
            stream << ' ';
            stream << arr[i]->age;
            stream << ' ';
            stream << arr[i]->rost;
            stream << ' ';
            stream << arr[i]->ves;
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
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
    else if (dayn == 1)
    {
        int size=0;
        size = g;
        int num1;
        int num2;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                num1 = arr[j]->age.toInt();
                num2 = arr[j+1]->age.toInt();
                if (num1 > num2)
                {
                    QString f;
                    f = arr[j]->country;
                    arr[j]->country = arr[j+1]->country;
                    arr[j+1]->country = f;

                    f = arr[j]->komanda;
                    arr[j]->komanda = arr[j+1]->komanda;
                    arr[j + 1]->komanda = f;

                    f = arr[j]->fam;
                    arr[j]->fam = arr[j+1]->fam;
                    arr[j+1]->fam = f;

                    f = arr[j]->nomer;
                    arr[j]->nomer = arr[j+1]->nomer;
                    arr[j+1]->nomer = f;

                    f = arr[j]->age;
                    arr[j]->age = arr[j+1]->age;
                    arr[j+1]->age = f;

                    f = arr[j]->rost;
                    arr[j]->rost = arr[j+1]->rost;
                    arr[j+1]->rost = f;

                    f = arr[j]->ves;
                    arr[j]->ves = arr[j+1]->ves;
                    arr[j+1]->ves = f;
                }
            }
        }
        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i]->country;
            stream << ' ';
            stream << arr[i]->komanda;
            stream << ' ';
            stream << arr[i]->fam;
            stream << ' ';
            stream << arr[i]->nomer;
            stream << ' ';
            stream << arr[i]->age;
            stream << ' ';
            stream << arr[i]->rost;
            stream << ' ';
            stream << arr[i]->ves;
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
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
    else if (daye == 1)
    {
        int size = g;
        double num1;
        double num2;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                num1 = arr[j]->rost.toDouble();
                num2 = arr[j+1]->rost.toDouble();
                if (num1 > num2)
                {
                    QString f;
                    f = arr[j]->country;
                    arr[j]->country = arr[j+1]->country;
                    arr[j+1]->country = f;

                    f = arr[j]->komanda;
                    arr[j]->komanda = arr[j+1]->komanda;
                    arr[j + 1]->komanda = f;

                    f = arr[j]->fam;
                    arr[j]->fam = arr[j+1]->fam;
                    arr[j+1]->fam = f;

                    f = arr[j]->nomer;
                    arr[j]->nomer = arr[j+1]->nomer;
                    arr[j+1]->nomer = f;

                    f = arr[j]->age;
                    arr[j]->age = arr[j+1]->age;
                    arr[j+1]->age = f;

                    f = arr[j]->rost;
                    arr[j]->rost = arr[j+1]->rost;
                    arr[j+1]->rost = f;

                    f = arr[j]->ves;
                    arr[j]->ves = arr[j+1]->ves;
                    arr[j+1]->ves = f;
                }
            }
        }
        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i]->country;
            stream << ' ';
            stream << arr[i]->komanda;
            stream << ' ';
            stream << arr[i]->fam;
            stream << ' ';
            stream << arr[i]->nomer;
            stream << ' ';
            stream << arr[i]->age;
            stream << ' ';
            stream << arr[i]->rost;
            stream << ' ';
            stream << arr[i]->ves;
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
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
    else if(dar == 1)
    {
        int size = g;
        double num1;
        double num2;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                num1 = arr[j]->ves.toDouble();
                num2 = arr[j+1]->ves.toDouble();
                if (num1 > num2)
                {
                    QString f;
                    f = arr[j]->country;
                    arr[j]->country = arr[j+1]->country;
                    arr[j+1]->country = f;

                    f = arr[j]->komanda;
                    arr[j]->komanda = arr[j+1]->komanda;
                    arr[j + 1]->komanda = f;

                    f = arr[j]->fam;
                    arr[j]->fam = arr[j+1]->fam;
                    arr[j+1]->fam = f;

                    f = arr[j]->nomer;
                    arr[j]->nomer = arr[j+1]->nomer;
                    arr[j+1]->nomer = f;

                    f = arr[j]->age;
                    arr[j]->age = arr[j+1]->age;
                    arr[j+1]->age = f;

                    f = arr[j]->rost;
                    arr[j]->rost = arr[j+1]->rost;
                    arr[j+1]->rost = f;

                    f = arr[j]->ves;
                    arr[j]->ves = arr[j+1]->ves;
                    arr[j+1]->ves = f;
                }
            }
        }
        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
            stream << arr[i]->country;
            stream << ' ';
            stream << arr[i]->komanda;
            stream << ' ';
            stream << arr[i]->fam;
            stream << ' ';
            stream << arr[i]->nomer;
            stream << ' ';
            stream << arr[i]->age;
            stream << ' ';
            stream << arr[i]->rost;
            stream << ' ';
            stream << arr[i]->ves;
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
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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





void MainWindow::on_pushButton_10_clicked()
{
    ui->tableWidget->setRowCount(0);
    int i = 0;
    while (i < g)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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


void MainWindow::on_pushButton_9_clicked()
{
   QString Famqwe = ui->lineEdit_14->text();
   QString n = Famqwe;
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    int size = g;
    SecondWindow window(arr, size, Famqwe);
    window.setModal(true);
    window.exec();

    return;
}


void MainWindow::on_pushButton_11_clicked()
{
    QString nom = ui->lineEdit_15->text();
    int s = g;
    int n = nom.toInt();
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
    arr.NachDeleteNodeAtIndex(n - 1);
    g--;
    ui->tableWidget->setRowCount(0);
    int i = 0;
    while (i < g)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
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
        stream << arr[i]->country;
        stream << ' ';
        stream << arr[i]->komanda;
        stream << ' ';
        stream << arr[i]->fam;
        stream << ' ';
        stream << arr[i]->nomer;
        stream << ' ';
        stream << arr[i]->age;
        stream << ' ';
        stream << arr[i]->rost;
        stream << ' ';
        stream << arr[i]->ves;
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


void MainWindow::on_pushButton_12_clicked()
{
   QString min = ui->lineEdit_16->text();
   QString max = ui->lineEdit_17->text();
   QString n = min;
   double num = n.toDouble();
   for (int i = 0; i < n.size() - 1; i++)
   {
    if ((n[i] < '0' || n[i] > '9')|| n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
    {
        QMessageBox::critical(this, "Беда", "Ошибка в заполнении");
        return;
    }
    if (num == 0)
    {
        QMessageBox::critical(this, "Беда", "Ошибка в заполнении");
        return;
    }
   }
   if (n.isEmpty())
   {
       QMessageBox::critical(this, "Ошибка", "Пустое поле");
       return;
   }
   n = max;
   num = n.toDouble();
      for (int i = 0; i < n.size() - 1; i++)
      {
       if ((n[i] < '0' || n[i] > '9')|| n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
       {
           QMessageBox::critical(this, "Беда", "Ошибка в заполнении");
           return;
       }
       if (num == 0)
       {
           QMessageBox::critical(this, "Беда", "Ошибка в заполнении");
           return;
       }
      }
      if (n.isEmpty())
      {
          QMessageBox::critical(this, "Ошибка", "Пустое поле");
          return;
      }
      num = min.toDouble();
      double f = max.toDouble();
      if (num > f)
      {
        QMessageBox::critical(this, "Беда", "Минимальная больше максимального");
        return;
      }
      int size = g;
      thirdwindow window(arr, size, min, max);
      window.setModal(true);
      window.exec();

      return;
}


void MainWindow::on_pushButton_13_clicked()
{
   int size = g;
   int min = INT_MAX;
   for (int i = 0; i < size; i++)
   {
       if (arr[i]->age.toInt() < min)
       {
           min = arr[i]->age.toInt();
       }
   }
   fourthwindow window(arr, size, min);
   window.setModal(true);
   window.exec();

   return;
}


void MainWindow::on_pushButton_14_clicked()
{
    QString rostt = ui->lineEdit_18->text();
    QString n = rostt;
    double num = n.toDouble();
    for (int i = 0; i < n.size() - 1; i++)
    {
     if ((n[i] < '0' || n[i] > '9')|| n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Беда", "Ошибка в заполнении");
         return;
     }
     if (num == 0)
     {
         QMessageBox::critical(this, "Беда", "Ошибка в заполнении");
         return;
     }
    }
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    int size = g;
    fifthwindow window(arr, size, num);
    window.setModal(true);
    window.exec();

    return;
}

void MainWindow::on_pushButton_4_clicked()
{
    QString country = ui->lineEdit_7->text();
    QString komanda = ui->lineEdit_8->text();
    QString famil = ui->lineEdit_9->text();
    QString nomer = ui->lineEdit_10->text();
    QString age = ui->lineEdit_11->text();
    QString rost = ui->lineEdit_12->text();
    QString ves = ui->lineEdit_13->text();

    QString n = country;
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = komanda;
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    n = famil;
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = nomer;
    int num = n.toInt();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
     if (num == 0)
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = age;
    num = n.toInt();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
     if (num == 0)
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = rost;
    num = n.toInt();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < n.size(); i++)
    {
     if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
     if (num == 0)
     {
         QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
         return;
     }
    }
    n = ves;
    num = n.toDouble();
    if (n.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
   for (int i = 0; i < n.size() - 1; i++)
   {
    if ((n[i] < '0' || n[i] > '9') || (i == 0 && n[i] == '0') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
        return;
    }
    if (num == 0)
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка в добавлении");
        return;
    }
   }
   int s = g;
   QString numm = ui->lineEdit_19->text();
   if (s < numm.toInt() || numm.toInt() < 1)
   {
       QMessageBox::critical(this, "Ошибка", "Нет такого номера");
       return;
   }
   int siz = numm.toInt();
   ui->tableWidget->setRowCount(0);
   arr[siz - 1]->setCountry(country);
   arr[siz - 1]->setKomanda(komanda);
   arr[siz - 1]->setFam(famil);
   arr[siz - 1]->setNomer(nomer);
   arr[siz - 1]->setAge(age);
   arr[siz - 1]->setRost(rost);
   arr[siz - 1]->setVes(ves);
   QFile file(str);
   file.open(QIODevice::ReadWrite | QIODevice::Text);
   QTextStream stream(&file);
   int i = 0;
   while (true)
   {
     //
       stream << arr[i]->country;
       stream << ' ';
       stream << arr[i]->komanda;
       stream << ' ';
       stream << arr[i]->fam;
       stream << ' ';
       stream << arr[i]->nomer;
       stream << ' ';
       stream << arr[i]->age;
       stream << ' ';
       stream << arr[i]->rost;
       stream << ' ';
       stream << arr[i]->ves;
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
       ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i]->country));
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i]->komanda));
       ui->tableWidget->setItem(i,2,new QTableWidgetItem(arr[i]->fam));
       ui->tableWidget->setItem(i,3,new QTableWidgetItem(arr[i]->nomer));
       ui->tableWidget->setItem(i,4,new QTableWidgetItem(arr[i]->age));
       ui->tableWidget->setItem(i,5,new QTableWidgetItem(arr[i]->rost));
       ui->tableWidget->setItem(i,6,new QTableWidgetItem(arr[i]->ves));
       i++;
   }
   ui->tableWidget->update();
   QMessageBox::information(this, "УРА", "Изменено успешно");
   return;

}

