#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <stack.h>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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
    /*
    Stack b;
    Stack1 c;
    QString str = ui->lineEdit->text();
         for (int i = 0; i < str.size(); i++)
         {
             if (str[i] == '(' || str[i] == '[' || str[i] == '{')
             {
                 b.push(str[i]);
             }
             else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
             {
                 if (b.Empty() || (str[i] == ')' && b.top() != '(') || (str[i] == ']' && b.top() != '[') || (str[i] == '}' && b.top() != '{'))
                 {
                     ui->label->setText("Ошибка на индексе");

                     // МБ ИНДЕКС +1 СДЕЛАТЬ

                     QString s  = QString::number(i);
                     ui->label_2->setText(s);
                     return;
                 }
                 b.pop();
             }
         }
         while (c.size > 1)
              {
                  c.pop();
              }
         if (!b.Empty())
         {
             ui->label->setText("Ошибка на индексе");

             // МБ ИНДЕКС +1 СДЕЛАТЬ

             QString s  = QString::number(c.pop());
             ui->label_2->setText(s);
             return;
         }

         ui->label->setText("Успешно");
         */



    Stack b;
    Stack1 c;

    ui->label_2->clear();
    ui->label_4->clear();


// cтока
int j = 1;
// колонка
int col = 0;

int num = 0;

    QString str = ui->plainTextEdit->toPlainText();
    int fg = str.size();
         for (int i = 0; i < str.size(); i++)
         {
             //col = i;
             if (str[i] == '\n')
             {
                 j++;
                 col = 0;
                 continue;
             }
             else
             {
                 col++;
             }

             if ( str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']' && str[i] != '{' && str[i] != '}')
             {
                 if(str[i] == '\n')
                 {
                     col = 0;
                 }
                 else
                 {
                 num++;
                 }
             }
             if (str[i] == '(' || str[i] == '[' || str[i] == '{')
             {
                 b.push(str[i]);
             }
             else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
             {
                 if (b.Empty() || (str[i] == ')' && b.top() != '(') || (str[i] == ']' && b.top() != '[') || (str[i] == '}' && b.top() != '{'))
                 {
                     ui->label->setText("Ошибка на индексе");

                     // МБ ИНДЕКС +1 СДЕЛАТЬ

                     QString s  = QString::number(col);
                     ui->label_2->setText(s);
                     ui->label_4->setText(QString::number(j));
                     return;
                 }
                 b.pop();
             }
         }
         while (c.size > 1)
              {
                  c.pop();
              }
         if (!b.Empty())
         {
             ui->label->setText("Ошибка на индексе");


         //    if (j == 1)
         //    {
             QString s  = QString::number(c.pop() + num);
  //           QString s  = QString::number(col);
             ui->label_2->setText(s);
         //    }
         //    else
         //    {
         //        QString s  = QString::number(col);
         //        ui->label_2->setText(s);
         //    }


             ui->label_4->setText(QString::number(j));
             return;
         }

         ui->label->setText("Успешно");








}


void MainWindow::on_pushButton_2_clicked()
{
   QString str = QFileDialog::getOpenFileName(this, "Выбрать файл");
    QFile file(str);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    QString ans;
    int i = 0;
    do
    {
        ans=file.readLine();
        int t = ans.length();
        Stack b;
        Stack1 c;

        ui->label_2->clear();
        ui->label_4->clear();


    // cтока
    int j = 1;
    // колонка
    int col = 0;
    int num = 0;

            for (int i = 0; i < ans.size(); i++)
             {
                 //col = i;
                 if (str[i] == '\n')
                 {
                     j++;
                     col = 0;
                     continue;
                 }
                 else
                 {
                     col++;
                 }

                 if ( str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']' && str[i] != '{' && str[i] != '}')
                 {
                     if(str[i] == '\n')
                     {
                         col = 0;
                     }
                     else
                     {
                     num++;
                     }
                 }
                 if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                 {
                     b.push(str[i]);
                 }
                 else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
                 {
                     if (b.Empty() || (str[i] == ')' && b.top() != '(') || (str[i] == ']' && b.top() != '[') || (str[i] == '}' && b.top() != '{'))
                     {
                         ui->label->setText("Ошибка на индексе");

                         // МБ ИНДЕКС +1 СДЕЛАТЬ

                         QString s  = QString::number(col);
                         ui->label_2->setText(s);
                         ui->label_4->setText(QString::number(j));
                         return;
                     }
                     b.pop();
                 }
             }
             while (c.size > 1)
                  {
                      c.pop();
                  }
             if (!b.Empty())
             {
                 ui->label->setText("Ошибка на индексе");


             //    if (j == 1)
             //    {
                 QString s  = QString::number(c.pop() + num);
      //           QString s  = QString::number(col);
                 ui->label_2->setText(s);
             //    }
             //    else
             //    {
             //        QString s  = QString::number(col);
             //        ui->label_2->setText(s);
             //    }


                 ui->label_4->setText(QString::number(j));
                 return;
             }

             ui->label->setText("Успешно");




    }while (!file.atEnd());
}

