#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <pair.h>
#include <QRandomGenerator>
#include <QMessageBox>
#include "statlib.h"

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

    Vector<int> sttt;
    QString main = ui->lineEdit->text();
    if(main.isEmpty())
    {
        QMessageBox::critical(this, "ГГ", "Ошибка");
        return;
    }
    for (int i = 0; i < main.size(); i++)
    {
        if (main[i] > '9' || main[i] < '0' || (i == 0 && main[i] == '0'))
        {
            QMessageBox::critical(this, "ГГ", "Ошибка");
            return;
        }
    }
    int m = main.toInt();
    QString first = ui->lineEdit_2->text();
    if(first.isEmpty())
    {
        QMessageBox::critical(this, "ГГ", "Ошибка");
        return;
    }
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] > '9' || first[i] < '0' || (i == 0 && first[i] == '0') || first.isEmpty())
        {
            QMessageBox::critical(this, "ГГ", "Ошибка");
            return;
        }
    }
    int f = first.toInt();



    QString numbers = ui->lineEdit_4->text();
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != ' ' && (numbers[i] > '9' && numbers[i] < '0'))
        {
            QMessageBox::critical(this, "ГГ", "Ошибка в воде");
            return;
        }
    }
    QStringList list = numbers.split(" ");
    for(int i = 0;i < list.size();i++)
    {
        if(!list[i].toInt())
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            return;
        }
    }
    int count = 0;
    int s = 0;
    QString q = "";
    Vector<int> a;
    for (int i = 0; i < numbers.size(); i++)
        {
            QString df = numbers[i];
            if (((numbers[i] > '9' || numbers[i] < '0') && numbers[i] != ' ') || count == 2)
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                return;
            }
            if (numbers[i] == ' ')
            {
                count++;
                a.push_back(q.toInt());
                s++;
                q = "";
                continue;
            }
            else
            {
                count = 0;
                q += numbers[i];
                if (i == numbers.size() - 1)
                {
                    a.push_back(q.toInt());
                    s++;
                }
            }
        }
    if (s != main.toInt() * first.toInt())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
        ui->lineEdit_4->clear();
        return;
    }
    s = 0;
    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vec(m);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].first = Vector<int>(f);
        for (int j = 0; j < vec[i].first.size(); j++)
        {
          //  int v;
          //  QRandomGenerator gen = QRandomGenerator::securelySeeded();
          //  v = gen.bounded(0, 100);
           // vec[i].first[j] = v;
            vec[i].first[j] = a[s];
            s++;
        }
    }
    QString answ;

    for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].first.size(); j++)
            {
              //  cout << vec[i].first[j] << "    ";
                QString a = QString::number(vec[i].first[j]);
                answ += a;
                answ += " ";
            }
            answ += '\n';
        }

    //ui->label_7->setText(answ);
    ui->textBrowser->setText(answ);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString main = ui->lineEdit->text();
    if(main.isEmpty())
    {
        QMessageBox::critical(this, "ГГ", "Ошибка");
        return;
    }
    for (int i = 0; i < main.size(); i++)
    {
        if (main[i] > '9' || main[i] < '0' || (i == 0 && main[i] == '0'))
        {
            QMessageBox::critical(this, "ГГ", "Ошибка");
            return;
        }
    }
    int m = main.toInt();
    QString second = ui->lineEdit_3->text();
    if(second.isEmpty())
    {
        QMessageBox::critical(this, "ГГ", "Ошибка");
        return;
    }
    for (int i = 0; i < second.size(); i++)
    {
        if (second[i] > '9' || second[i] < '0' || (i == 0 && second[i] == '0') || second.isEmpty())
        {
            QMessageBox::critical(this, "ГГ", "Ошибка");
            return;
        }
    } 
    QString numbers = ui->lineEdit_5->text();
    for (int i = 0; i < numbers.size(); i++)
    {
        if ((numbers[i] != ' ' && numbers[i] > '9' && numbers[i] < '0' && numbers[i] != '.') || (numbers.isEmpty()))
        {
            QMessageBox::critical(this, "ГГ", "Ошибка в воде");
            return;
        }
    }
    QStringList list = numbers.split(" ");
    for(int i = 0;i < list.size();i++)
    {
        if (i == 0 || i % 2 == 0)
        {
            if(!list[i].toInt())
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                return;
            }
        }
        else
        {
            if(!list[i].toDouble())
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                return;
            }
        }
    }
    int count = 0;
    int chka = 0;
    QString q = "";
    int sss = 0;
    int razmer = 0;
    Vector<double> a;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (((numbers[i] > '9' || numbers[i] < '0') && numbers[i] != ' ' && numbers[i] != '.') || count == 2 || chka == 2)
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            return;
        }
        if (numbers[i] == '.')
        {
            chka++;
            q += numbers[i];
            continue;
        }
        else if (numbers[i] == ' ')
        {
            count++;
            int tochka = 0;
            if (sss == 2)
            {
                sss = 0;
            }
            if (sss == 0 || sss % 2 == 0)
            {
                for (int i = 0; i < q.size(); i++)
                {
                    if (q[i] == '.')
                    {
                        tochka++;
                        break;
                    }
                }
            }
            sss++;
            if (tochka > 0)
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                ui->lineEdit_5->clear();
                return;
            }
            tochka = 0;
            a.push_back(q.toDouble());
            razmer++;
            q = "";
            continue;
        }
        else
        {
            count = 0;
            chka = 0;
            q += numbers[i];
            if (i == numbers.size() - 1)
            {
                a.push_back(q.toDouble());
                razmer++;
            }
        }
    }

    if (razmer != main.toInt() * second.toInt() * 2)
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
       // ui->lineEdit_5->clear();
        return;
    }

    int s = 0;
    int f = second.toInt();
    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vec(m);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].second = Vector<Pair<int, double>>(f);
        for (int j = 0; j < vec[i].second.size(); j++)
        {
            int one = a[s];
            s++;
            double second = a[s];
            s++;
         //   QRandomGenerator gen = QRandomGenerator::securelySeeded();
         //   one = gen.bounded(0, 100);
         //   second = gen.generateDouble();
            vec[i].second[j] = Pair<int, double>(one, second);
        }
    }
    QString answ;
    for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].second.size(); j++)
            {
                QString a = QString::number(vec[i].second[j].first);
                answ += a;
                answ += " ";
                QString b = QString::number(vec[i].second[j].second);
                answ += b;
                answ += "   ";
            }
            answ += '\n';
        }

   //ui->label_8->setText(answ);
    ui->textBrowser_2->setText(answ);
}

