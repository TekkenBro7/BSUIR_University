#include "mainwindow.h"
#include ".\ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QTime>
#include <QDate>
#include <QMessageBox>

QString str;
static int current = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i=0;i<100;i++)
    {
        arr[i].SetDate("0");
    }
    current = 0;
    str = QFileDialog::getOpenFileName(this, "Выбрать файл");
    QFile file(str);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int days, mounth, year;
    int i=0, q = 0;
    QTextStream stream(&file);
    QString c;
    while (!file.atEnd())
    {
        c="";
        c=stream.read(10);
        if (c.length() != 10)
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        if (c[2] != '.' || c[5] != '.')
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        days=c[0].digitValue()*10+c[1].digitValue();
        mounth=c[3].digitValue()*10+c[4].digitValue();
        year=c[6].digitValue()*1000+c[7].digitValue()*100+c[8].digitValue()*10+c[9].digitValue();
        if (c.length() != 10 || !(QDate::isValid(year, mounth, days)))
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка!");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        if (c[0] > '9' || c[0] < '0' || c[1] > '9' || c[1] < '0' || c[3] > '9' || c[3] < '0' || c[4] > '9' || c[4] < '0' || c[6] > '9' || c[6] < '0' || c[7] > '9' || c[7] < '0' || c[8] > '9' || c[8] < '0' || c[9] > '9' || c[9] < '0')
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка!");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        if (c[6] == 0 && c[7] == 0 && c[8] == 0 && c[9] == 0)
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка!");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        arr[i].SetDate(c);
        q+=11;
        stream.seek(q);
        i++;
        current++;
    }
    for(int i = 0;i < current;i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].getDate()));
    }
    ui->tableWidget->update();
    if (file.isOpen())
    {
        QMessageBox::information(this, "Успешно", "Файл успешно открыт!");
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_17->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_19->setEnabled(true);
        ui->pushButton_20->setEnabled(true);
        ui->pushButton_21->setEnabled(true);
        return;
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка!");
        ui->pushButton_13->setEnabled(false);
        ui->pushButton_14->setEnabled(false);
        ui->pushButton_15->setEnabled(false);
        ui->pushButton_16->setEnabled(false);
        ui->pushButton_17->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
        ui->pushButton_20->setEnabled(false);
        ui->pushButton_21->setEnabled(false);
        return;
    }
        file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_12_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_13_clicked()
{
    QString s;
    Date a;

    for(int i = 0;i < current;i++)
    {
        s = arr[i].getDate();
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(a.WeekNumber(s))));
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    QString s;
    Date a;
    for(int i = 0;i < current;i++)
    {
        s = arr[i].getDate();
        if (s == "01.01.0001")
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("Выход за рамки"));
            continue;
        }
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(a.PreviosDay(s)));
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    QString s;
    Date a;
    for(int i = 0;i < current;i++)
    {
       s = arr[i].getDate();
       if (s == "31.12.9999")
       {
            ui->tableWidget->setItem(i,1,new QTableWidgetItem("Выход за рамки"));
            continue;
       }
       ui->tableWidget->setItem(i,1,new QTableWidgetItem(a.NextDay(s)));
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    QString s;
    Date a;
    for(int i =0;i < current;i++)
    {
        s = arr[i].getDate();
        if(a.isLeap(s))
        {
            ui->tableWidget->setItem(i,3,new QTableWidgetItem("Год високосный"));
        }
        else
        {
         ui->tableWidget->setItem(i,3,new QTableWidgetItem("Год не високосный"));
        }
    }
}


void MainWindow::on_pushButton_17_clicked()
{
    QString bday = ui->lineEdit_6->text();
    if (bday.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < bday.length(); i++)
    {
        if (bday.length() != 2 && bday.length() != 1)
        {
            QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
            return;
        }
        if ((bday[0] == '0' && bday.length() == 1) || (bday[0] == '0' && bday[1] == '0' && bday.length() == 2))
        {
            QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
            return;
        }
        if (bday[i] < '0' || bday[i] > '9')
        {
            QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
            return;
        }
    }
    QString bmonth = ui->lineEdit_7->text();
    if (bmonth.isEmpty())
    {
        QMessageBox::critical(this, "Ошибка", "Пустое поле");
        return;
    }
    for (int i = 0; i < bmonth.length(); i++)
    {
        if (bmonth.length() != 2 && bmonth.length() != 1)
        {
            QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
            return;
        }
        if ((bmonth[0] == '0' && bmonth.length() == 1) || (bmonth[0] == '0' && bmonth[1] == '0' && bmonth.length() == 2))
        {
            QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
            return;
        }
        if (bmonth[i] < '0' || bmonth[i] > '9')
        {
            QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
            return;
        }
    }
     int days;
     int mounth;
    int year = 2004;

    if (bday.length() == 1)
        days=bday[0].digitValue();
    else
        days=bday[0].digitValue()*10+bday[1].digitValue();

    if (bmonth.length() == 1)
        mounth=bmonth[0].digitValue();
    else
        mounth=bmonth[0].digitValue()*10+bmonth[1].digitValue();

    if (QDate::isValid(year, mounth, days))
    {
        Date birthday;
        QString s;
        Date a;
        for(int i = 0;i < current;i++)
        {
            s = arr[i].getDate();
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(a.DaysTillYourBithday(days, mounth, s))));
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Неверная дата");
        return;
    }


}


void MainWindow::on_pushButton_18_clicked()
{
    QString day = ui->lineEdit_8->text();
    int days, mounth, year;
    if (day.length() == 10)
    {
    days = day[0].digitValue()*10+day[1].digitValue();
    mounth = day[3].digitValue()*10+day[4].digitValue();
    year = day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
        return;
    }
    if (day.length() != 10 || !(QDate::isValid(year, mounth, days)))
    {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
        return;
    }
    if (day[2] != '.' || day[5] != '.')
    {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
        return;
    }
    if(day[0] > '9' || day[0] < '0' || day[1] > '9' || day[1] < '0' || day[3] > '9' || day[3] < '0' || day[4] > '9' || day[4] < '0' || day[6] > '9' || day[6] < '0' || day[7] > '9' || day[7] < '0' || day[8] > '9' || day[8] < '0' || day[9] > '9' || day[9] < '0')
    {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
        return;
    }
     if (day[6] == 0 && day[7] == 0 && day[8] == 0 && day[9] == 0)
     {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
        return;
     }

    else
    {
               int size=0;
               while (arr[size].getDate() != "0")
               {
                 size++;
               }
               arr[size].SetDate(day);
               size++;
               QFile file(str);
               file.open(QIODevice::ReadWrite | QIODevice::Text);
               QTextStream stream(&file);
               stream.seek((size - 1) * 11);
               // arr[size - 1].setDate(day);
               stream << day;

               current++;
               ui->tableWidget->insertRow(current-1);
               ui->tableWidget->setItem(current-1,0,new QTableWidgetItem(arr[current-1].getDate()));
               QString s, s1;
               Date a;
               QString bday = ui->lineEdit_6->text();
               if (bday.isEmpty())
               {
                   QMessageBox::critical(this, "Ошибка", "Заполните дату дня рождения, чтобы автоматически считало при добавлении");
                   return;
               }
               for (int i = 0; i < bday.length(); i++)
               {
                   if (bday.length() != 2 && bday.length() != 1)
                   {
                       QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                       return;
                   }
                   if ((bday[0] == '0' && bday.length() == 1) || (bday[0] == '0' && bday[1] == '0' && bday.length() == 2))
                   {
                       QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                       return;
                   }
                   if (bday[i] < '0' || bday[i] > '9')
                   {
                       QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                       return;
                   }
               }
               QString bmonth = ui->lineEdit_7->text();
               if (bmonth.isEmpty())
               {
                   QMessageBox::critical(this, "Ошибка", "Пустое поле");
                   return;
               }
               for (int i = 0; i < bmonth.length(); i++)
               {
                   if (bmonth.length() != 2 && bmonth.length() != 1)
                   {
                       QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                       return;
                   }
                   if ((bmonth[0] == '0' && bmonth.length() == 1) || (bmonth[0] == '0' && bmonth[1] == '0' && bmonth.length() == 2))
                   {
                       QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                       return;
                   }
                   if (bmonth[i] < '0' || bmonth[i] > '9')
                   {
                       QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                       return;
                   }
               }
                int d;
                int m;
               //int year = 2004;

               if (bday.length() == 1)
                   d=bday[0].digitValue();
               else
                   d=bday[0].digitValue()*10+bday[1].digitValue();

               if (bmonth.length() == 1)
                   m=bmonth[0].digitValue();
               else
                   m=bmonth[0].digitValue()*10+bmonth[1].digitValue();

               QMessageBox::information(this, "Успешно", "Дата добавлена");

               for(int i = 0;i < current;i++)
               {

                   s = arr[i].getDate();
                   s1 = arr[i + 1].getDate();
                   ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(a.WeekNumber(s))));
                   ui->tableWidget->setItem(i,2,new QTableWidgetItem(a.PreviosDay(s)));
                   ui->tableWidget->setItem(i,1,new QTableWidgetItem(a.NextDay(s)));
                   if(a.isLeap(s))
                   {
                       ui->tableWidget->setItem(i,3,new QTableWidgetItem("Год високосный"));
                   }
                   else
                   {
                    ui->tableWidget->setItem(i,3,new QTableWidgetItem("Год не високосный"));
                   }
                   ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(a.DaysTillYourBithday(d, m, s))));
                   ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(a.Duration(s, s1))));

                   if (i == current - 1)
                   {
                       ui->tableWidget->setItem(i,6,new QTableWidgetItem("Последняя дата"));
                       return;
                   }
                   ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(a.Duration2(s, s1))));
               }
               file.close();
    }
}


void MainWindow::on_pushButton_19_clicked()
{
         QString s;
         QString s1;
         Date a;
    for(int i = 0;i < current;i++)
    {
         s = arr[i].getDate();
         s1 = arr[i].getDate();
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(a.Duration(s, s1))));
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    QString s;
    QString s1;
    Date a;
for(int i = 0;i < current;i++)
{
    if (i == current - 1)
    {
        ui->tableWidget->setItem(i,6,new QTableWidgetItem("Последняя дата"));
        return;
    }
    s = arr[i].getDate();
    s1 = arr[i + 1].getDate();
    ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(a.Duration2(s, s1))));
}
}


void MainWindow::on_pushButton_21_clicked()
{
    int size = 0;
    while (arr[size].getDate() != "0")
    {
        size++;
    }
    QString number = ui->lineEdit_10->text();
    if (size >= number.toInt() && number.toInt() >= 1)
    {
        QString day = ui->lineEdit_9->text();
        int days=day[0].digitValue()*10+day[1].digitValue();
        int mounth=day[3].digitValue()*10+day[4].digitValue();
        int year=day[6].digitValue()*1000+day[7].digitValue()*100+day[8].digitValue()*10+day[9].digitValue();
        if (day.length() != 10 || !(QDate::isValid(year, mounth, days)))
        {
            QMessageBox::critical(this, "Ошибка", "Некорректный ввод!");
        }
        if (day[2] != '.' || day[5] != '.')
        {
            QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
            return;
        }
        if(day[0] > '9' || day[0] < '0' || day[1] > '9' || day[1] < '0' || day[3] > '9' || day[3] < '0' || day[4] > '9' || day[4] < '0' || day[6] > '9' || day[6] < '0' || day[7] > '9' || day[7] < '0' || day[8] > '9' || day[8] < '0' || day[9] > '9' || day[9] < '0')
        {
            QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
            return;
        }
        if (day[6] == 0 && day[7] == 0 && day[8] == 0 && day[9] == 0)
        {
           QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
           return;
        }
        else
        {
            int num=number.toInt();
            QFile file(str);
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream stream(&file);
            stream.seek((num-1) * 11);
            arr[num-1].SetDate(day);
            stream << day;
            ui->tableWidget->setItem(num - 1,0,new QTableWidgetItem(arr[num-1].getDate()));
            QMessageBox::information(this, "Успешно", "Дата изменена успешно!");
            QString s, s1;
            Date a;
            QString bday = ui->lineEdit_6->text();
            if (bday.isEmpty())
            {
                QMessageBox::critical(this, "Ошибка", "Пустое поле");
                return;
            }
            for (int i = 0; i < bday.length(); i++)
            {
                if (bday.length() != 2 && bday.length() != 1)
                {
                    QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                    return;
                }
                if ((bday[0] == '0' && bday.length() == 1) || (bday[0] == '0' && bday[1] == '0' && bday.length() == 2))
                {
                    QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                    return;
                }
                if (bday[i] < '0' || bday[i] > '9')
                {
                    QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                    return;
                }
            }
            QString bmonth = ui->lineEdit_7->text();
            if (bmonth.isEmpty())
            {
                QMessageBox::critical(this, "Ошибка", "Пустое поле");
                return;
            }
            for (int i = 0; i < bmonth.length(); i++)
            {
                if (bmonth.length() != 2 && bmonth.length() != 1)
                {
                    QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                    return;
                }
                if ((bmonth[0] == '0' && bmonth.length() == 1) || (bmonth[0] == '0' && bmonth[1] == '0' && bmonth.length() == 2))
                {
                    QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                    return;
                }
                if (bmonth[i] < '0' || bmonth[i] > '9')
                {
                    QMessageBox::critical(this, "Ошибка", "Неверный формат дня");
                    return;
                }
            }
             int d;
             int m;
            //int year = 2004;

            if (bday.length() == 1)
                d=bday[0].digitValue();
            else
                d=bday[0].digitValue()*10+bday[1].digitValue();

            if (bmonth.length() == 1)
                m=bmonth[0].digitValue();
            else
                m=bmonth[0].digitValue()*10+bmonth[1].digitValue();
            for(int i = 0;i < current;i++)
            {
                if (i == current - 1)
                {
                    ui->tableWidget->setItem(i,6,new QTableWidgetItem("Последняя дата"));
                    return;
                }
                s = arr[i].getDate();
                s1 = arr[i + 1].getDate();
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(a.WeekNumber(s))));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(a.PreviosDay(s)));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(a.NextDay(s)));
                if(a.isLeap(s))
                {
                    ui->tableWidget->setItem(i,3,new QTableWidgetItem("Год високосный"));
                }
                else
                {
                 ui->tableWidget->setItem(i,3,new QTableWidgetItem("Год не високосный"));
                }


                ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(a.DaysTillYourBithday(d, m, s))));


                ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(a.Duration(s, s1))));
                ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(a.Duration2(s, s1))));
            }


            file.close();
        }
    }
    else
    {
        QMessageBox::critical(this, "Успешно", "Ошибка");
    }
}


void MainWindow::on_pushButton_22_clicked()
{
    current = 0;
    int f = current;
    str = QFileDialog::getOpenFileName(this, "Выбрать файл");
    QFile file(str);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int days, mounth, year;
    int i=0, q = 0;
    QTextStream stream(&file);
    QString c;
    int ht = 0;
    while (!file.atEnd())
    {
        ht++;
        c="";
        c=stream.read(10);
        if (c.length() != 10)
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        if (c[2] != '.' || c[5] != '.')
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        days=c[0].digitValue()*10+c[1].digitValue();
        mounth=c[3].digitValue()*10+c[4].digitValue();
        year=c[6].digitValue()*1000+c[7].digitValue()*100+c[8].digitValue()*10+c[9].digitValue();
        if (c.length() != 10 || !(QDate::isValid(year, mounth, days)))
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка!");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        if (c[0] > '9' || c[0] < '0' || c[1] > '9' || c[1] < '0' || c[3] > '9' || c[3] < '0' || c[4] > '9' || c[4] < '0' || c[6] > '9' || c[6] < '0' || c[7] > '9' || c[7] < '0' || c[8] > '9' || c[8] < '0' || c[9] > '9' || c[9] < '0')
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка!");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        if (c[6] == 0 && c[7] == 0 && c[8] == 0 && c[9] == 0)
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка!");
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_19->setEnabled(false);
            ui->pushButton_20->setEnabled(false);
            ui->pushButton_21->setEnabled(false);
            return;
        }
        arr[i].SetDate(c);
        q+=11;
        stream.seek(q);
        i++;
        f++;
        current++;
    }

    for (int i = current - 1; i > -1; i--)
    {
        ui->tableWidget->removeRow(i);
    }

    for(int i = 0;i < current;i++)
    {
       // ui->tableWidget->removeRow(i);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].getDate()));
    }

    if (ht == 0)
    {
        QMessageBox::information(this, "Успешно", "Файл пуст!");
        return;
    }

//    ui->tableWidget->update();

    if (file.isOpen())
    {
        QMessageBox::information(this, "Успешно", "Файл успешно открыт!");
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_17->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_19->setEnabled(true);
        ui->pushButton_20->setEnabled(true);
        ui->pushButton_21->setEnabled(true);
        return;
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка!");
        ui->pushButton_13->setEnabled(false);
        ui->pushButton_14->setEnabled(false);
        ui->pushButton_15->setEnabled(false);
        ui->pushButton_16->setEnabled(false);
        ui->pushButton_17->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_19->setEnabled(false);
        ui->pushButton_20->setEnabled(false);
        ui->pushButton_21->setEnabled(false);
        return;
    }
    file.close();
}
