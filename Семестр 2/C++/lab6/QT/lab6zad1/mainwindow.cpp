#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <binaryTree.h>
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


void MainWindow::on_empty_clicked()
{
    QString fam = ui->pushLine->text();
    QString pas = ui->pushLine_3->text();
    if (fam.isEmpty())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
        ui->pushLine->clear();
        ui->pushLine_3->clear();
        return;
    }
    for (int i = 0; i < fam.size(); i++)
    {
        if ((fam[i] >= '0' && fam[i] <= '9') || fam[i] == '=' || fam[i] == ']' || fam[i] == '[' || fam[i] == '{' || fam[i] == '}' || fam[i] == '"' || fam[i] == ';' || fam[i] == ':' || fam[i] == '/' || fam[i] == '?' || fam[i] == '.' || fam[i] == '>' || fam[i] == '<' || fam[i] == ',' || fam[i] == '!' || fam[i] == '@' || fam[i] == '#' || fam[i] == '$' || fam[i] == '%' || fam[i] == '^' || fam[i] == '&' || fam[i] == '*' || fam[i] == '(' || fam[i] == ')' || fam[i] == '_' || fam[i] == '-' || fam[i] == '+')
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
    //      ui->pushLine_3->clear();
            return;
        }
    }
    if (pas.toInt())
    {
        a.insert(fam, pas.toInt());
        QMessageBox::information(this,"Ура","Успешно");
    }
    else
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
    //    ui->pushLine->clear();
        ui->pushLine_3->clear();
        return;
    }
}


void MainWindow::on_insert_5_clicked()
{
    QMessageBox::warning(this,"ПУСТ?", a.empty() ? QString("Пуст"): QString("Не пуст"));
}


void MainWindow::on_insert_3_clicked()
{
    QString str = " ";
    a.print(str);
    ui->output_2->setText(str);
    return;
}


void MainWindow::on_push_clicked()
{
    QString fam = ui->pushLine->text();
    QString pas = ui->pushLine_3->text();
    if (fam.isEmpty())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
        ui->pushLine->clear();
        ui->pushLine_3->clear();
        return;
    }
    QStringList list = fam.split(" ");
    QStringList list2 = pas.split(" ");
    if (list.count() != list2.count())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
        ui->pushLine->clear();
        ui->pushLine_3->clear();
        return;
    }
    for (int i = 0; i < fam.size(); i++)
    {
        if ((fam[i] >= '0' && fam[i] <= '9') || fam[i] == '=' || fam[i] == ']' || fam[i] == '[' || fam[i] == '{' || fam[i] == '}' || fam[i] == '"' || fam[i] == ';' || fam[i] == ':' || fam[i] == '/' || fam[i] == '?' || fam[i] == '.' || fam[i] == '>' || fam[i] == '<' || fam[i] == ',' || fam[i] == '!' || fam[i] == '@' || fam[i] == '#' || fam[i] == '$' || fam[i] == '%' || fam[i] == '^' || fam[i] == '&' || fam[i] == '*' || fam[i] == '(' || fam[i] == ')' || fam[i] == '_' || fam[i] == '-' || fam[i] == '+')
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
        //    ui->pushLine_3->clear();
            return;
        }
    }
    for (int i = 0; i < list.count(); i++)
    {
        if (list2[i].toInt())
        {
            a.insert(list[i], list2[i].toInt());
        }
    }
    ui->pushLine->clear();
    ui->pushLine_3->clear();
    QMessageBox::information(this,"Ура","Успешно");
    return;
}


void MainWindow::on_insert_4_clicked()
{
    if (a.empty())
    {
        QMessageBox::information(this,"Мда","Дерево пусто");
        return;
    }
    int depth = a.maxDepth(a.root);
    QMessageBox::information(this,"maxDepth", QString::number(depth));
    return;
}


void MainWindow::on_erase_clicked()
{
    QString str = " ";
    a.print_prefix(str);
    ui->output_2->setText(str);
    return;
}


void MainWindow::on_clear_clicked()
{
    QString str = " ";
    a.print_postfix(str);
    ui->output_2->setText(str);
    return;
}


void MainWindow::on_insert_clicked()
{
    QString str = " ";
    a.print_infix(str);
    ui->output_2->setText(str);
    return;
}


void MainWindow::on_capacity_clicked()
{
    QString pas = ui->pushLine_3->text();
    if (!pas.toInt())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
    //    ui->pushLine->clear();
        ui->pushLine_3->clear();
        return;
    }
    int x = pas.toInt();
    a.deleteNode(a.root, x);
    ui->pushLine_3->clear();
    QMessageBox::information(this,"Ура","Успешно");
    return;
}


void MainWindow::on_pop_clicked()
{
    if (a.empty())
    {
        QMessageBox::information(this,"Мда","Дерево пусто");
        return;
    }
    a.balanceTree();
    QMessageBox::information(this,"Ура","Успешно");
    return;
}


void MainWindow::on_size_clicked()
{
    QString pas = ui->pushLine_3->text();
    if (!pas.toInt())
    {
        QMessageBox::warning(this,"Беда","Ошибка в заполнении");
    //    ui->pushLine->clear();
        ui->pushLine_3->clear();
        return;
    }
    int x = pas.toInt();
    QString str = a.search(x);
    if (str != "")
    {
        QMessageBox::information(this,"Найдено",str);
    }
    else
    {
        QMessageBox::information(this,"Пусто","Не найдено");
    }
    ui->pushLine_3->clear();
    return;
}
