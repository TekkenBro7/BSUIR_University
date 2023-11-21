#include "mainwindow.h"
#include ".\ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QTime>
#include <QDate>
#include <algorithm>
#include <firma.h>
#include <QMessageBox>

QString str;
int g = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    str = QFileDialog::getOpenFileName(this, "Выбрать файл");
    QFile file(str);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int cur=0;
    QTextStream stream(&file);
    QString ans;
    int stat=0;
    QString n;
    int i=0;
    int days, mounth, year;
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
                        arr[cur].Name(n);
                        n="";
                        stat++;
                    }
                    else if (stat==1)
                    {
                        arr[cur].zad(n);
                        n="";
                        stat++;
                    }
                    else if (stat==2)
                    {
                        arr[cur].fio(n);
                        for (int i = 0; i < n.size(); i++)
                        {
                            if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                            {
                                QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                                ui->pushButton->setEnabled(false);
                                ui->pushButton_2->setEnabled(false);
                                ui->pushButton_4->setEnabled(false);
                                ui->pushButton_5->setEnabled(false);
                                ui->pushButton_6->setEnabled(false);
                                ui->pushButton_7->setEnabled(false);
                                ui->pushButton_8->setEnabled(false);
                                return;
                            }
                        }
                        n="";
                        stat++;
                    }
                    else if (stat==3)
                    {
                        arr[cur].FIO(n);
                        for (int i = 0; i < n.size(); i++)
                        {
                            if ((n[i] >= '0' && n[i] <= '9') || n[i] == '.' || n[i] == '/' || n[i] == ',' || n[i] == '<' || n[i] == '>' || n[i] == '?' || n[i] == ':' || n[i] == ';' || n[i] == ']' || n[i] == '[' || n[i] == '{' || n[i] == '}' || n[i] == '!' || n[i] == '@' || n[i] == '#' || n[i] == '$' || n[i] == '%' || n[i] == '^' || n[i] == '&' || n[i] == '*' || n[i] == '(' || n[i] == ')' || n[i] == '-' || n[i] == '_' || n[i] == '+' || n[i] == '=')
                            {
                                QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                                ui->pushButton->setEnabled(false);
                                ui->pushButton_2->setEnabled(false);
                                ui->pushButton_4->setEnabled(false);
                                ui->pushButton_5->setEnabled(false);
                                ui->pushButton_6->setEnabled(false);
                                ui->pushButton_7->setEnabled(false);
                                ui->pushButton_8->setEnabled(false);
                                return;
                            }
                        }
                        n="";
                        stat++;
                    }
                    else if (stat==4)
                    {

                        if (n.length() != 10)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[2] != '.' || n[5] != '.')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        days=n[0].digitValue()*10+n[1].digitValue();
                        mounth=n[3].digitValue()*10+n[4].digitValue();
                        year=n[6].digitValue()*1000+n[7].digitValue()*100+n[8].digitValue()*10+n[9].digitValue();
                        if (n.length() != 10 || !(QDate::isValid(year, mounth, days)))
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[0] > '9' || n[0] < '0' || n[1] > '9' || n[1] < '0' || n[3] > '9' || n[3] < '0' || n[4] > '9' || n[4] < '0' || n[6] > '9' || n[6] < '0' || n[7] > '9' || n[7] < '0' || n[8] > '9' || n[8] < '0' || n[9] > '9' || n[9] < '0')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        arr[cur].d1(n);
                        n="";
                        stat++;
                    }
                    else if (stat==5)
                    {
                        if (n.length() != 10)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[2] != '.' || n[5] != '.')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        days=n[0].digitValue()*10+n[1].digitValue();
                        mounth=n[3].digitValue()*10+n[4].digitValue();
                        year=n[6].digitValue()*1000+n[7].digitValue()*100+n[8].digitValue()*10+n[9].digitValue();
                        if (n.length() != 10 || !(QDate::isValid(year, mounth, days)))
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[0] > '9' || n[0] < '0' || n[1] > '9' || n[1] < '0' || n[3] > '9' || n[3] < '0' || n[4] > '9' || n[4] < '0' || n[6] > '9' || n[6] < '0' || n[7] > '9' || n[7] < '0' || n[8] > '9' || n[8] < '0' || n[9] > '9' || n[9] < '0')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        arr[cur].d2(n);
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

    if (file.isOpen())
    {
        QMessageBox::information(this, "Успешно", "Файл успешно открыт!");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        return;
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка!");
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        return;
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


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString answer;
    int i = 0;

    int s = g;

    if (s == 0)
    {
        ui->textBrowser->setText("Пусто");
        return;
    }
    while (true)
    {
           answer += arr[i].getDate1();
           answer += ' ';
           answer += arr[i].getDate2();
           answer += ' ';
           answer += arr[i].getDate3();
           answer += ' ';
           answer += arr[i].getDate4();
           answer += ' ';
           answer += arr[i].getDate5();
           answer += ' ';
           answer += arr[i].getDate6();
           answer += ' ';
           if (i + 1 == g)
           {
               break;
           }
           answer += '\n';
           i++;
    }

 //  ui->label->setText(answer);

   ui->textBrowser->setText(answer);

}


void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString proekt = ui->lineEdit->text();
    QString zadan = ui->lineEdit_2->text();
    QString fioispoln = ui->lineEdit_3->text();
    QString fiorukovod = ui->lineEdit_4->text();
    QString daynach = ui->lineEdit_5->text();
    QString dayen = ui->lineEdit_6->text();

    int size = 0;
    size = g;
    int check = 0;

    if (proekt.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < proekt.length(); i++)
    {
        if ((proekt[i] >= '0' && proekt[i] <= '9') || proekt[i] == '-' || proekt[i] == '+' || proekt[i] == '/' || proekt[i] == '*' || proekt[i] == '=' || proekt[i] == '^' || proekt[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
    if (zadan.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < zadan.length(); i++)
    {
        if ((zadan[i] >= '0' && zadan[i] <= '9') || zadan[i] == '-' || zadan[i] == '+' || zadan[i] == '/' || zadan[i] == '*' || zadan[i] == '=' || zadan[i] == '^' || zadan[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
    if (fioispoln.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < fioispoln.length(); i++)
    {
        if ((fioispoln[i] >= '0' && fioispoln[i] <= '9') || fioispoln[i] == '-' || fioispoln[i] == '+' || fioispoln[i] == '/' || fioispoln[i] == '*' || fioispoln[i] == '=' || fioispoln[i] == '^' || fioispoln[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
    if (fiorukovod.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < fiorukovod.length(); i++)
    {
        if ((fiorukovod[i] >= '0' && fiorukovod[i] <= '9') || fiorukovod[i] == '-' || fiorukovod[i] == '+' || fiorukovod[i] == '/' || fiorukovod[i] == '*' || fiorukovod[i] == '=' || fiorukovod[i] == '^' || fiorukovod[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
        int days, mounth, year;
        if (daynach.length() == 10)
        {
        days = daynach[0].digitValue()*10+daynach[1].digitValue();
        mounth = daynach[3].digitValue()*10+daynach[4].digitValue();
        year = daynach[6].digitValue()*1000+daynach[7].digitValue()*100+daynach[8].digitValue()*10+daynach[9].digitValue();
        }
        else
        {
            ui->textBrowser->setText("Неккоректный ввод");
            return;
        }
        if (daynach.length() != 10 || !(QDate::isValid(year, mounth, days)) || (daynach[2] != '.' && daynach[5] != '.'))
        {
            ui->textBrowser->setText("Неккоректный ввод");
            return;
        }
        if (check == 0)
        {
            ui->textBrowser->setText("Неправильная информация");
            return;
        }
        else
        {
            int ds, moth, yer;
            if (dayen.length() == 10)
            {
            ds = dayen[0].digitValue()*10+dayen[1].digitValue();
            moth = dayen[3].digitValue()*10+dayen[4].digitValue();
            yer = dayen[6].digitValue()*1000+dayen[7].digitValue()*100+dayen[8].digitValue()*10+dayen[9].digitValue();
            }
            else
            {
                ui->textBrowser->setText("Неккоректный ввод");
                return;
            }
            if (daynach.length() != 10 || !(QDate::isValid(yer, moth, ds)) || (dayen[2] != '.' && dayen[5] != '.'))
            {
                ui->textBrowser->setText("Неккоректный ввод");
                return;
            }

            tm first{}, second{};

            first.tm_mday = days;
            first.tm_mon = mounth;
            first.tm_year = year;
            first.tm_mon--;
            first.tm_year -= 1900;

            second.tm_mday = ds;
            second.tm_mon = moth;
            second.tm_year = yer;
            second.tm_mon--;
            second.tm_year -= 1900;
            int difference = difftime(mktime(&second), mktime(&first));
            if (yer - year < 20)
            {
                if (difference < 0)
                {
                    ui->textBrowser->setText("Неправильная информация");
                    return;
                }
            }

                            if (yer < year)
                            {
                                ui->textBrowser->setText("Неправильная информация");
                                return;
                            }




            if (check == 0)
            {
                ui->textBrowser->setText("Неправильная информация");
                return;
            }
            else
            {
                arr[size].Name(proekt);
                arr[size].zad(zadan);
                arr[size].fio(fioispoln);
                arr[size].FIO(fiorukovod);
                arr[size].d1(daynach);
                arr[size].d2(dayen);
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
              //  stream << '\n';
                stream << proekt;
                stream << ' ';
                stream << zadan;
                stream << ' ';
                stream << fioispoln;
                stream << ' ';
                stream << fiorukovod;
                stream << ' ';
                stream << daynach;
                stream << ' ';
                stream << dayen;
                stream << '\n';
                g++;

                file.close();
                ui->textBrowser->setText("Дата добавлена");
                }
            }
        }
    }
  }
 }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString f = ui->lineEdit_7->text();
    QString s = ui->lineEdit_8->text();
    QString answer;
    int check = 0;
    if (f.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < f.length(); i++)
    {
        if ((f[i] >= '0' && f[i] <= '9') || f[i] == '-' || f[i] == '+' || f[i] == '/' || f[i] == '*' || f[i] == '=' || f[i] == '^' || f[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    if (s.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+' || s[i] == '/' || s[i] == '*' || s[i] == '=' || s[i] == '^' || s[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }

    QFile file(str);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int cur = 0;
    QTextStream stream(&file);
    QString ans;
    int stat = 0;
    QString n;
    int i = 0;
    int uj = 0;
    int count = 0;
    int ty = 0;

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
                arr[cur].Name(n);

                if (n == f)
                {
                    count++;
                }

                n="";
                stat++;
            }
            else if (stat==1)
            {
                arr[cur].zad(n);
                n="";
                stat++;
            }
            else if (stat==2)
            {
                arr[cur].fio(n);

                if (n == s)
                {
                    count++;
                }

                n="";
                stat++;
            }
            else if (stat==3)
            {
                arr[cur].FIO(n);
                n="";
                stat++;
            }
            else if (stat==4)
            {
                arr[cur].d1(n);
                n="";
                stat++;
            }
            else if (stat==5)
            {
                arr[cur].d2(n);
                n="";
                stat++;
            }
            i++;
    }
        if (count == 2)
        {
                   answer += arr[ty].getDate1();
                   answer += ' ';
                   answer += arr[ty].getDate2();
                   answer += ' ';
                   answer += arr[ty].getDate3();
                   answer += ' ';
                   answer += arr[ty].getDate4();
                   answer += ' ';
                   answer += arr[ty].getDate5();
                   answer += ' ';
                   answer += arr[ty].getDate6();
                   answer += ' ';
                   answer += '\n';
                   if (count == 2)
                   {
                       uj = 2;
                   }
        }

        ty++;
    count = 0;
    ans="";
    i=0;
    n="";
    cur++;
    stat=0;

} while (!file.atEnd());

    ui->textBrowser->setText(answer);

    if (uj != 2)
    {
        ui->textBrowser->setText("Не нашлось совпадений");
    }

file.close();

}


void MainWindow::on_pushButton_5_clicked()
{
    QFile file(str);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int cur = 0;
    QTextStream stream(&file);
    QString ans;
    int stat = 0;
    QString n;
    int i = 0;
    int uj = 0;
    int ty = 0;
    QString f1, s1, answer;

    do
    {
        ans=file.readLine();

        if (!(ans == '\n'))
        {

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
                arr[cur].Name(n);
                n="";
                stat++;
            }
            else if (stat==1)
            {
                arr[cur].zad(n);
                n="";
                stat++;
            }
            else if (stat==2)
            {
                arr[cur].fio(n);
                n="";
                stat++;
            }
            else if (stat==3)
            {
                arr[cur].FIO(n);
                n="";
                stat++;
            }
            else if (stat==4)
            {
                arr[cur].d1(n);
                f1 = n;
                n="";
                stat++;
            }
            else if (stat==5)
            {
                arr[cur].d2(n);
                s1 = n;
                n="";
                stat++;
            }
            i++;
    }

        tm first{}, second{};

        int year = f1[6].digitValue()*1000+f1[7].digitValue()*100+f1[8].digitValue()*10+f1[9].digitValue();
        int days = f1[0].digitValue()*10+f1[1].digitValue();
        int mounth = f1[3].digitValue()*10+f1[4].digitValue();

        first.tm_mday = days;
        first.tm_mon = mounth;
        first.tm_year = year;
        first.tm_mon--;
        first.tm_year -= 1900;

        int year2 = s1[6].digitValue()*1000+s1[7].digitValue()*100+s1[8].digitValue()*10+s1[9].digitValue();
        int days2 = s1[0].digitValue()*10+s1[1].digitValue();
        int mounth2 = s1[3].digitValue()*10+s1[4].digitValue();

        second.tm_mday = days2;
        second.tm_mon = mounth2;
        second.tm_year = year2;
        second.tm_mon--;
        second.tm_year -= 1900;

        int difference = difftime(mktime(&second), mktime(&first));

        int da = difference / (60 * 60 * 24);

        if (da <= 30 && da >= 0 && (year + 1 >= year2))
        {
            answer += arr[ty].getDate2();
            answer += '\n';
            uj = 2;
        }
        }
    ty++;
    ans="";
    i=0;
    n="";
    cur++;
    stat=0;

} while (!file.atEnd());

    ui->textBrowser->setText(answer);

    if (uj != 2)
    {
        ui->textBrowser->setText("Не нашлось совпадений");
    }

file.close();

}


void MainWindow::on_pushButton_6_clicked()
{
    QString proekt = ui->lineEdit->text();
    QString zadan = ui->lineEdit_2->text();
    QString fioispoln = ui->lineEdit_3->text();
    QString fiorukovod = ui->lineEdit_4->text();
    QString daynach = ui->lineEdit_5->text();
    QString dayen = ui->lineEdit_6->text();
    QString nom = ui->lineEdit_9->text();

    int s = g;
    int num = nom.toInt();

    if (s < nom.toInt() || nom.toInt() < 1)
    {
        ui->textBrowser->setText("Ошибка");
        return;
    }
    int check = 0;

    if (proekt.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < proekt.length(); i++)
    {
        if ((proekt[i] >= '0' && proekt[i] <= '9') || proekt[i] == '-' || proekt[i] == '+' || proekt[i] == '/' || proekt[i] == '*' || proekt[i] == '=' || proekt[i] == '^' || proekt[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
    if (zadan.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < zadan.length(); i++)
    {
        if ((zadan[i] >= '0' && zadan[i] <= '9') || zadan[i] == '-' || zadan[i] == '+' || zadan[i] == '/' || zadan[i] == '*' || zadan[i] == '=' || zadan[i] == '^' || zadan[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
    if (fioispoln.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < fioispoln.length(); i++)
    {
        if ((fioispoln[i] >= '0' && fioispoln[i] <= '9') || fioispoln[i] == '-' || fioispoln[i] == '+' || fioispoln[i] == '/' || fioispoln[i] == '*' || fioispoln[i] == '=' || fioispoln[i] == '^' || fioispoln[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
    if (fiorukovod.isEmpty())
    {
        check = 0;
    }
    for (int i = 0; i < fiorukovod.length(); i++)
    {
        if ((fiorukovod[i] >= '0' && fiorukovod[i] <= '9') || fiorukovod[i] == '-' || fiorukovod[i] == '+' || fiorukovod[i] == '/' || fiorukovod[i] == '*' || fiorukovod[i] == '=' || fiorukovod[i] == '^' || fiorukovod[i] == '%')
        {
            check = 0;
            break;
        }
        else
        {
            check = 1;
        }
    }
    if (check == 0)
    {
        ui->textBrowser->setText("Неправильная информация");
        return;
    }
    else
    {
        int days, mounth, year;
        if (daynach.length() == 10)
        {
        days = daynach[0].digitValue()*10+daynach[1].digitValue();
        mounth = daynach[3].digitValue()*10+daynach[4].digitValue();
        year = daynach[6].digitValue()*1000+daynach[7].digitValue()*100+daynach[8].digitValue()*10+daynach[9].digitValue();
        }
        else
        {
            ui->textBrowser->setText("Неккоректный ввод");
            return;
        }
        if (daynach.length() != 10 || !(QDate::isValid(year, mounth, days)) || (daynach[2] != '.' && daynach[5] != '.'))
        {
            ui->textBrowser->setText("Неккоректный ввод");
            return;
        }
        for (int i = 0; i < daynach.length(); i++)
        {
            if (daynach[i] > '9' && daynach[i] < '0' && i != 2 && i != 5)
            {
                ui->textBrowser->setText("Неправильная информация");
                return;
            }
        }
        if (check == 0)
        {
            ui->textBrowser->setText("Неправильная информация");
            return;
        }
        else
        {
            int ds, moth, yer;
            if (dayen.length() == 10)
            {
            ds = dayen[0].digitValue()*10+dayen[1].digitValue();
            moth = dayen[3].digitValue()*10+dayen[4].digitValue();
            yer = dayen[6].digitValue()*1000+dayen[7].digitValue()*100+dayen[8].digitValue()*10+dayen[9].digitValue();
            }
            else
            {
                ui->textBrowser->setText("Неккоректный ввод");
                return;
            }
            if (dayen.length() != 10 || !(QDate::isValid(yer, moth, ds)) || (dayen[2] != '.' && dayen[5] != '.'))
            {
                ui->textBrowser->setText("Неккоректный ввод");
                return;
            }
            for (int i = 0; i < dayen.length(); i++)
            {
                if (dayen[i] > '9' && dayen[i] < '0' && i != 2 && i != 5)
                {
                    ui->textBrowser->setText("Неправильная информация");
                    return;
                }
            }
            tm first{}, second{};

            first.tm_mday = days;
            first.tm_mon = mounth;
            first.tm_year = year;
            first.tm_mon--;
            first.tm_year -= 1900;

            second.tm_mday = ds;
            second.tm_mon = moth;
            second.tm_year = yer;
            second.tm_mon--;
            second.tm_year -= 1900;
            int difference = difftime(mktime(&second), mktime(&first));
            if (yer - year < 20)
            {
                if (difference < 0)
                {
                    ui->textBrowser->setText("Неправильная информация");
                    return;
                }
            }
                            if (yer < year)
                            {
                                ui->textBrowser->setText("Неправильная информация");
                                return;
                            }


    QFile file(str);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream stream(&file);

    arr[num - 1].Name(proekt);
    arr[num - 1].zad(zadan);
    arr[num - 1].fio(fioispoln);
    arr[num - 1].FIO(fiorukovod);
    arr[num - 1].d1(daynach);
    arr[num - 1].d2(dayen);

    int i = 0;
    while (true)
    {
           stream << arr[i].getDate1();
           stream << ' ';
           stream << arr[i].getDate2();
           stream << ' ';
           stream << arr[i].getDate3();
           stream << ' ';
           stream << arr[i].getDate4();
           stream << ' ';
           stream << arr[i].getDate5();
           stream << ' ';
           stream << arr[i].getDate6();
           stream << ' ';
           if (i + 1 == g)
           {
               break;
           }
           stream << '\n';
           i++;
     }
    file.close();
    }
   }
  }
 }
}
    ui->textBrowser->setText("Изменено успешно!");
}

void MainWindow::on_pushButton_7_clicked()
{
    QString nom = ui->lineEdit_9->text();
    int s = g;
    int h = 0;
    int num = nom.toInt();
    QString proekt;
    QString zadan;
    QString fioispoln;
    QString fiorukovod;
    QString daynach;
    QString dayen;


    if (g == 0)
    {
        ui->textBrowser->setText("В файле нет информации");
        return;
    }
    if (s < nom.toInt() || nom.toInt() < 1)
    {
        ui->textBrowser->setText("Ошибка");
        return;
    }

    QFile file(str);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file);

    for (int i = 0; i < s; i++)
    {
        if (i == num - 1 || h > 0)
        {
            if (num == 1 && g == 1)
            {
                proekt = "";
                zadan = "";
                fioispoln = "";
                fiorukovod = "";
                daynach = "";
                dayen = "";

                arr[i].Name(proekt);
                arr[i].zad(zadan);
                arr[i].fio(fioispoln);
                arr[i].FIO(fiorukovod);
                arr[i].d1(daynach);
                arr[i].d2(dayen);

            }
            else
            {
                proekt = arr[i + 1].getDate1();
                zadan = arr[i + 1].getDate2();
                fioispoln = arr[i + 1].getDate3();
                fiorukovod = arr[i + 1].getDate4();
                daynach = arr[i + 1].getDate5();
                dayen = arr[i + 1].getDate6();

                arr[i].Name(proekt);
                arr[i].zad(zadan);
                arr[i].fio(fioispoln);
                arr[i].FIO(fiorukovod);
                arr[i].d1(daynach);
                arr[i].d2(dayen);

                proekt = "";
                zadan = "";
                fioispoln = "";
                fiorukovod = "";
                daynach = "";
                dayen = "";

                h++;

            }
        }
    }
    g--;


    int i = 0;
    while (true)
    {
        if (g == 0)
        {
            break;
        }
           stream << arr[i].getDate1();
           stream << ' ';
           stream << arr[i].getDate2();
           stream << ' ';
           stream << arr[i].getDate3();
           stream << ' ';
           stream << arr[i].getDate4();
           stream << ' ';
           stream << arr[i].getDate5();
           stream << ' ';
           stream << arr[i].getDate6();
           stream << ' ';
           if (i + 1 == g)
           {
               break;
           }
           stream << '\n';
           i++;
     }
    if (g == 1)
    {
        ui->textBrowser->setText("Файл изменен");
        return;
    }
    file.close();
    ui->textBrowser->setText("Файл изменен");
}


firma SortByStaj(firma* b, int position, int t)
{
    for (int i = 0; i < t; i++)
    {
        int curretly = -1;
        QString str = b[i].getDate5();
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
          QString str1 = b[q].getDate5();
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
          std::swap(b[i], b[curretly]);
        }
    }
    return *b;
}

firma SortByStaj1(firma* b, int position, int t)
{
    for (int i = 0; i < t; i++)
    {
        int curretly = -1;
        QString str = b[i].getDate6();
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
          QString str1 = b[q].getDate6();
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
          std::swap(b[i], b[curretly]);
        }
    }
    return *b;
}

void MainWindow::on_pushButton_8_clicked()
{
    int pro = ui->radioButton->isChecked();
    int zad = ui->radioButton_2->isChecked();
    int fioisp = ui->radioButton_3->isChecked();
    int fioruk = ui->radioButton_4->isChecked();
    int dayn = ui->radioButton_5->isChecked();
    int daye = ui->radioButton_6->isChecked();

    if (pro == 1)
    {
        int size=0;
        size = g;
        for(int i = 1; i < size; i++)
        {
         for(int j = i; j > 0 && stt(arr[j-1].getDate1(), arr[j].getDate1()); j--)
          {
            firma tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]=tmp;
          }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
               stream << arr[i].getDate1();
               stream << ' ';
               stream << arr[i].getDate2();
               stream << ' ';
               stream << arr[i].getDate3();
               stream << ' ';
               stream << arr[i].getDate4();
               stream << ' ';
               stream << arr[i].getDate5();
               stream << ' ';
               stream << arr[i].getDate6();
               stream << ' ';
               if (i + 1 == g)
               {
                   break;
               }
               stream << '\n';
               i++;
         }
        file.close();
        ui->textBrowser->setText("Отсортировано успешно");
        return;
    }
    else if (zad == 1)
    {
        int size=0;
        size = g;
        for(int i = 1; i < size; i++)
        {
         for(int j = i; j > 0 && stt(arr[j-1].getDate2(), arr[j].getDate2()); j--)
          {
            firma tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]=tmp;
          }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
               stream << arr[i].getDate1();
               stream << ' ';
               stream << arr[i].getDate2();
               stream << ' ';
               stream << arr[i].getDate3();
               stream << ' ';
               stream << arr[i].getDate4();
               stream << ' ';
               stream << arr[i].getDate5();
               stream << ' ';
               stream << arr[i].getDate6();
               stream << ' ';
               if (i + 1 == g)
               {
                   break;
               }
               stream << '\n';
               i++;
         }
        file.close();
        ui->textBrowser->setText("Отсортировано успешно");
        return;
    }
    else if (fioisp == 1)
    {
        int size=0;
        size = g;
        for(int i = 1; i < size; i++)
        {
         for(int j = i; j > 0 && stt(arr[j-1].getDate3(), arr[j].getDate3()); j--)
          {
            firma tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]=tmp;
          }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
               stream << arr[i].getDate1();
               stream << ' ';
               stream << arr[i].getDate2();
               stream << ' ';
               stream << arr[i].getDate3();
               stream << ' ';
               stream << arr[i].getDate4();
               stream << ' ';
               stream << arr[i].getDate5();
               stream << ' ';
               stream << arr[i].getDate6();
               stream << ' ';
               if (i + 1 == g)
               {
                   break;
               }
               stream << '\n';
               i++;
         }
        file.close();
        ui->textBrowser->setText("Отсортировано успешно");
        return;
    }
    else if (fioruk == 1)
    {
        int size=0;
        size = g;
        for(int i = 1; i < size; i++)
        {
         for(int j = i; j > 0 && stt(arr[j-1].getDate4(), arr[j].getDate4()); j--)
          {
            firma tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]=tmp;
          }
        }

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);

        int i = 0;
        while (true)
        {
               stream << arr[i].getDate1();
               stream << ' ';
               stream << arr[i].getDate2();
               stream << ' ';
               stream << arr[i].getDate3();
               stream << ' ';
               stream << arr[i].getDate4();
               stream << ' ';
               stream << arr[i].getDate5();
               stream << ' ';
               stream << arr[i].getDate6();
               stream << ' ';
               if (i + 1 == g)
               {
                   break;
               }
               stream << '\n';
               i++;
         }
        file.close();
        ui->textBrowser->setText("Отсортировано успешно");
        return;
    }
    else if (dayn == 1)
    {
        int size = g;
        for(int i = 0; i < 7; i ++)
        *arr = SortByStaj(arr, 1, size);

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
               stream << arr[i].getDate1();
               stream << ' ';
               stream << arr[i].getDate2();
               stream << ' ';
               stream << arr[i].getDate3();
               stream << ' ';
               stream << arr[i].getDate4();
               stream << ' ';
               stream << arr[i].getDate5();
               stream << ' ';
               stream << arr[i].getDate6();
               stream << ' ';
               if (i + 1 == g)
               {
                   break;
               }
               stream << '\n';
               i++;
         }
        file.close();
        ui->textBrowser->setText("Отсортировано успешно");
        return;
    }
    else if (daye == 1)
    {
        int size = g;
        for(int i = 0; i < 7; i ++)
        *arr = SortByStaj1(arr, 1, size);

        QFile file(str);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream stream(&file);
        int i = 0;
        while (true)
        {
               stream << arr[i].getDate1();
               stream << ' ';
               stream << arr[i].getDate2();
               stream << ' ';
               stream << arr[i].getDate3();
               stream << ' ';
               stream << arr[i].getDate4();
               stream << ' ';
               stream << arr[i].getDate5();
               stream << ' ';
               stream << arr[i].getDate6();
               stream << ' ';
               if (i + 1 == g)
               {
                   break;
               }
               stream << '\n';
               i++;
         }
        file.close();
        ui->textBrowser->setText("Отсортировано успешно");
        return;
    }
    else
    {
        ui->textBrowser->setText("Ничего не нажато");
        return;
    }

}

void MainWindow::on_pushButton_9_clicked()
{
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
    int days, mounth, year;
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
                        arr[cur].Name(n);
                        n="";
                        stat++;
                    }
                    else if (stat==1)
                    {
                        arr[cur].zad(n);
                        n="";
                        stat++;
                    }
                    else if (stat==2)
                    {
                        arr[cur].fio(n);
                        n="";
                        stat++;
                    }
                    else if (stat==3)
                    {
                        arr[cur].FIO(n);
                        n="";
                        stat++;
                    }
                    else if (stat==4)
                    {

                        if (n.length() != 10)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[2] != '.' || n[5] != '.')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        days=n[0].digitValue()*10+n[1].digitValue();
                        mounth=n[3].digitValue()*10+n[4].digitValue();
                        year=n[6].digitValue()*1000+n[7].digitValue()*100+n[8].digitValue()*10+n[9].digitValue();
                        if (n.length() != 10 || !(QDate::isValid(year, mounth, days)))
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[0] > '9' || n[0] < '0' || n[1] > '9' || n[1] < '0' || n[3] > '9' || n[3] < '0' || n[4] > '9' || n[4] < '0' || n[6] > '9' || n[6] < '0' || n[7] > '9' || n[7] < '0' || n[8] > '9' || n[8] < '0' || n[9] > '9' || n[9] < '0')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        arr[cur].d1(n);
                        n="";
                        stat++;
                    }
                    else if (stat==5)
                    {
                        if (n.length() != 10)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[2] != '.' || n[5] != '.')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка в файле");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        days=n[0].digitValue()*10+n[1].digitValue();
                        mounth=n[3].digitValue()*10+n[4].digitValue();
                        year=n[6].digitValue()*1000+n[7].digitValue()*100+n[8].digitValue()*10+n[9].digitValue();
                        if (n.length() != 10 || !(QDate::isValid(year, mounth, days)))
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[0] > '9' || n[0] < '0' || n[1] > '9' || n[1] < '0' || n[3] > '9' || n[3] < '0' || n[4] > '9' || n[4] < '0' || n[6] > '9' || n[6] < '0' || n[7] > '9' || n[7] < '0' || n[8] > '9' || n[8] < '0' || n[9] > '9' || n[9] < '0')
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        if (n[6] == 0 && n[7] == 0 && n[8] == 0 && n[9] == 0)
                        {
                            QMessageBox::critical(this, "Ошибка", "Ошибка!");
                            ui->pushButton->setEnabled(false);
                            ui->pushButton_2->setEnabled(false);
                            ui->pushButton_4->setEnabled(false);
                            ui->pushButton_5->setEnabled(false);
                            ui->pushButton_6->setEnabled(false);
                            ui->pushButton_7->setEnabled(false);
                            ui->pushButton_8->setEnabled(false);
                            return;
                        }
                        arr[cur].d2(n);
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

    if (file.isOpen())
    {
        QMessageBox::information(this, "Успешно", "Файл успешно открыт!");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        return;
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка!");
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        return;
    }
        file.close();
    }

