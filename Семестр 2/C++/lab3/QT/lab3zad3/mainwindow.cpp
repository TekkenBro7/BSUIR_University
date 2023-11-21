#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <statlib.h>
#include <QString>
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

Vector<int> Median(Vector<int> a)
{
    Vector<int> b;
    for (int i = 0; i < a.size(); i += 3)
    {
        if (i + 2 < a.size())
        {
            Vector<int> arr; //{ a[i], a[i + 1], a[i + 2] };
            arr.push_back(a[i]);
            arr.push_back(a[i + 1]);
            arr.push_back(a[i + 2]);
            arr.sort();
            int f = arr[1];
            b.push_back(arr[1]);
        }
        else
        {
            int sum = 0;
            for (int j = i; j < a.size(); j++) {
                sum += a[j];
            }
            b.push_back(sum / (a.size() - i));
        }
    }
    return b;
}

void MainWindow::on_pushButton_clicked()
{
    QString ot = ui->lineEdit->text();
    QString q = "";
    int count = 0;
    Vector<int> a;
    for (int i = 0; i < ot.size(); i++)
    {
        QString df = ot[i];
        if (((ot[i] > '9' || ot[i] < '0') && ot[i] != ' ') || count == 2)
        {
            QMessageBox::critical(this, "GG", "Ошибка в воде");
            return;
        }
        if (ot[i] == ' ')
        {
            count++;
            a.push_back(q.toInt());
            q = "";
            continue;
        }
        else
        {
            count = 0;
            q += ot[i];
            if (i == ot.size() - 1)
            {
                a.push_back(q.toInt());
            }
        }
    }
    Vector<int> b;
    b = Median(a);
    QString otvet;

    for (int i = 0; i < b.size(); i++)
    {
        otvet += QString::number(b[i]);
        otvet += " ";
    }

    ui->textBrowser->setText(otvet);
}

