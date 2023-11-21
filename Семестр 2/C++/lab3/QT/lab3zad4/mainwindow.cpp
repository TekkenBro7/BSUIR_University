#include "mainwindow.h"
#include ".\ui_mainwindow.h"
#include <QMessageBox>
#include <statlib.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->swap->setEnabled(0);
    ui->empty->setEnabled(0);
    ui->size->setEnabled(0);
    ui->capacity->setEnabled(0);
    ui->erase->setEnabled(0);
    ui->insert->setEnabled(0);
    ui->push->setEnabled(0);
    ui->pop->setEnabled(0);
    ui->clear->setEnabled(0);
    ui->resize->setEnabled(0);
    ui->assign->setEnabled(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_2_activated(int index)
{
    if(index == 0)
    {
        intVector.clear();
    }
    else if(index == 1)
    {
        doubleVector.clear();
    }
    else
    {
        stringVector.clear();
    }
    ui->swap->setEnabled(1);
    ui->empty->setEnabled(1);
    ui->size->setEnabled(1);
    ui->capacity->setEnabled(1);
    ui->erase->setEnabled(1);
    ui->insert->setEnabled(1);
    ui->push->setEnabled(1);
    ui->pop->setEnabled(1);
    ui->clear->setEnabled(1);
    ui->resize->setEnabled(1);
    ui->assign->setEnabled(1);
    ui->output_2->clear();
}

void MainWindow::on_clear_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();
    if (index == 0)
    {
        if (intVector.size() == 0)
        {
            QMessageBox::information(this, "Да", "Вектор и так пуст");
        }
        intVector.clear();
        ui->output_2->clear();
    }
    else if (index == 1)
    {
        if (doubleVector.size() == 0)
        {
            QMessageBox::information(this, "Да", "Вектор и так пуст");
        }
        intVector.clear();
        ui->output_2->clear();
    }
    else
    {
        if (stringVector.size() == 0)
        {
            QMessageBox::information(this, "Да", "Вектор и так пуст");
        }
        intVector.clear();
        ui->output_2->clear();
    }
}

void MainWindow::on_resize_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();

    QString editElement = ui->pushLine->text();
    QStringList list = editElement.split(" ");
    if (index == 0)
    {
        if (list[0].toInt() < 0)
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
            return;
        }
        for(int i = 1;i < list.size();i++)
        {
            if(!list[i].toInt())
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                ui->pushLine->clear();
                return;
            }
        }
        int count = 0;
        QString q = "";
        Vector<int> a;
        for (int i = 0; i < editElement.size(); i++)
            {
                QString df = editElement[i];
                if (((editElement[i] > '9' || editElement[i] < '0') && editElement[i] != ' ') || count == 2)
                {
                    QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                    ui->pushLine->clear();
                    return;
                }
                if (editElement[i] == ' ')
                {
                    count++;
                    a.push_back(q.toInt());
                    q = "";
                    continue;
                }
                else
                {
                    count = 0;
                    q += editElement[i];
                    if (i == editElement.size() - 1)
                    {
                        a.push_back(q.toInt());
                    }
                }
            }
        if (a.size() != 2)
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
            return;
        }

        int first = a[0];
        int second = a[1];

        intVector.resize(first, second);

        ui->output_2->clear();
        for(int i = 0;i < intVector.size();i++)
        {
            ui->output_2->append(QString::number(intVector[i]) + " ");
        }
    }
    else if (index == 1)
    {
        if (list[0].toInt() < 0)
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
            return;
        }
        for(int i = 1;i < list.size();i++)
        {
            if(!list[i].toDouble())
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                ui->pushLine->clear();
                return;
            }
        }
        int count = 0;
        int chka = 0;
        QString q = "";
        Vector<double> a;
        for (int i = 0; i < editElement.size(); i++)
            {
                if (((editElement[i] > '9' || editElement[i] < '0') && editElement[i] != ' ' && editElement[i] != '.') || count == 2 || chka == 2)
                {
                    QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                    ui->pushLine->clear();
                    return;
                }
                if (editElement[i] == '.')
                {
                    chka++;
                    q += editElement[i];
                    continue;
                }
                else if (editElement[i] == ' ')
                {
                    count++;
                    a.push_back(q.toDouble());
                    q = "";
                    continue;
                }
                else
                {
                    count = 0;
                    chka = 0;
                    q += editElement[i];
                    if (i == editElement.size() - 1)
                    {
                        a.push_back(q.toDouble());
                    }
                }
            }
        if (a.size() != 2)
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
            return;
        }
        int first = a[0];
        double second = a[1];
        doubleVector.resize(first, second);
        ui->output_2->clear();
        for(int i = 0;i < doubleVector.size();i++)
        {
            ui->output_2->append(QString::number(doubleVector[i]) + " ");
        }
    }
    else
    {
        if (list[0].toInt() < 0)
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
            return;
        }
        int count = 0;
        QString q = "";
        int first;
        Vector<QString> a;
        for (int i = 0; i < editElement.size(); i++)
            {
                if (i == 0)
                {
                    while (editElement[i] != ' ')
                    {
                        q += editElement[i];
                        i++;
                    }
                    first = q.toInt();
                    q = "";
                    continue;
                }
                QString df = editElement[i];
                if (count == 2)
                {
                    QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                    ui->pushLine->clear();
                    return;
                }
                else if (editElement[i] == ' ')
                {
                    count++;
                    a.push_back(q);
                    q = "";
                    continue;
                }
                else
                {
                    count = 0;
                    q += editElement[i];
                    if (i == editElement.size() - 1)
                    {
                        a.push_back(q);
                    }
                }
            }
        if (a.size() != 1)
        {
            QMessageBox::warning(this,"Беда","Ошибка в заполнении");
            ui->pushLine->clear();
            return;
        }
        QString second = a[0];
        stringVector.resize(first, second);
        ui->output_2->clear();
        for(int i = 0;i < stringVector.size();i++)
        {
            ui->output_2->append(stringVector[i] + " ");
        }
    }
}


void MainWindow::on_empty_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();

    if(index == 0)
    {
        QMessageBox::warning(this,"ПУСТ?",intVector.empty() ? QString("Пуст"): QString("Не пуст"));
    }
    else if(index == 1)
    {
        QMessageBox::warning(this,"ПУСТ",doubleVector.empty() ? QString("Пуст"): QString("Не пуст"));
    }
    else
    {
        QMessageBox::warning(this,"ПУСТ",stringVector.empty() ? QString("Пуст"): QString("Не пуст"));
    }
}

void MainWindow::on_size_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();

    if(index == 0)
    {
        QMessageBox::warning(this,"Размер  ",QString::number(intVector.size()));
    }
    else if(index == 1)
    {
        QMessageBox::warning(this,"Размер  ",QString::number(doubleVector.size()));
    }
    else
    {
        QMessageBox::warning(this,"Размер  ",QString::number(stringVector.size()));
    }
}

void MainWindow::on_capacity_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();

    if(index == 0)
    {
        QMessageBox::warning(this,"Вместительность  ",QString::number(intVector.capacity()));
    }
    else if(index == 1)
    {
        QMessageBox::warning(this,"Вместительность  ",QString::number(doubleVector.capacity()));
    }
    else
    {
        QMessageBox::warning(this,"Вместительность  ",QString::number(stringVector.capacity()));
    }
}

void MainWindow::on_push_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();

    if(index == 0)
    {
        QString input = ui->pushLine->text();
        if (input.toInt())
        {
              intVector.push_back(input.toInt());
              ui->output_2->append(input + " ");
        }
        else
        {
              QMessageBox::warning(this,"Беда","Некорректный ввод");
        }
    }
    else if(index == 1)
    {
        QString input = ui->pushLine->text();
        if (input.toDouble())
        {
              doubleVector.push_back(input.toDouble());
              ui->output_2->append(input + " ");
        }
        else
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
        }
    }
    else
    {
        QString input = ui->pushLine->text();
        bool incorrect = 0;

        if(input.isEmpty())
        {
            QMessageBox::warning(this,"Беда","Пустой ввод");
            return;
        }
        for(int i = 0;i < input.size();i++)
        {
            if(input[i] == ' ')
            {
                incorrect = 1;
            }
        }

        if (!incorrect)
        {
              stringVector.push_back(input);
              ui->output_2->append(input + " ");
        }
        else
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
        }
    }
    ui->pushLine->clear();
}

void MainWindow::on_swap_clicked()
{
    QString swp = ui->swapLine->text();
    QStringList list = swp.split(" ");
    int index = ui->comboBox_2->currentIndex();
    if(index == 0)
    {
        for(int i = 0;i < list.size();i++)
        {
            if (!list[i].toInt())
             {
                QMessageBox::warning(this,"Беда","Некорректный ввод");
                ui->swapLine->clear();
                return;
             }
        }
        Vector<int> intHelper;
        for(int i = 0;i<list.size();i++)
        {
           intHelper.push_back(list[i].toInt());
        }
        intVector.swap(intHelper);
        int size = intVector.size() > intHelper.size() ? intVector.size() : intHelper.size();

        ui->output_2->clear();
        ui->swapLine->clear();

        for(int i = 0;i < size;i++)
        {
            if(i < intVector.size())
            {
                ui->output_2->append(QString::number(intVector[i]) + " ");
            }
            if(i < intHelper.size())
            {
                ui->swapLine->insert(QString::number(intHelper[i]) + " ");
            }
        }
    }
    else if(index == 1)
    {
        QString swp = ui->swapLine->text();
        QStringList list = swp.split(" ");

            for(int i = 0;i < list.size();i++)
            {
                if (!list[i].toDouble())
                 {
                    QMessageBox::warning(this,"Беда","Некорректный ввод");
                    ui->swapLine->clear();
                    return;
                 }
            }
            Vector<double> doubleHelper;
            for(int i = 0;i<list.size();i++)
            {
               doubleHelper.push_back(list[i].toDouble());
            }

            doubleVector.swap(doubleHelper);
            int size = intVector.size() > doubleHelper.size() ? doubleVector.size() : doubleHelper.size();
            ui->output_2->clear();
            ui->swapLine->clear();

            for(int i = 0;i < size;i++)
            {
                if(i < doubleVector.size())
                {
                    ui->output_2->append(QString::number(doubleVector[i]) + " ");
                }
                if(i < doubleHelper.size())
                {
                    ui->swapLine->insert(QString::number(doubleHelper[i]) + " ");
                }
            }
    }
    else
    {
        QString swp = ui->swapLine->text();
        QStringList list = swp.split(" ");
        Vector<QString> stringHelper;
        for(int i = 0;i<list.size();i++)
        {
           stringHelper.push_back(list[i]);
        }
        stringVector.swap(stringHelper);
        int size = stringVector.size() > stringHelper.size() ? stringVector.size() : stringHelper.size();
        ui->output_2->clear();
        ui->swapLine->clear();
        for(int i = 0;i < size;i++)
        {
            if(i < stringVector.size())
            {
                ui->output_2->append(stringVector[i] + " ");
            }
            if(i < stringHelper.size())
            {
                ui->swapLine->insert(stringHelper[i] + " ");

            }
        }
    }

}

void MainWindow::on_pop_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();
    if(index == 0)
    {
        if(intVector.empty())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            return;
        }
        intVector.pop_back();
        ui->output_2->clear();
        for(int i = 0;i < intVector.size();i++)
        {
            ui->output_2->append(QString::number(intVector[i]) + " ");
        }
    }
    else if(index == 1)
    {
        if(doubleVector.empty())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            return;
        }

        doubleVector.pop_back();
        ui->output_2->clear();

        for(int i = 0;i < doubleVector.size();i++)
        {
            ui->output_2->append(QString::number(doubleVector[i]) + " ");
        }
    }
    else
    {
        if(stringVector.empty())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            return;
        }
        stringVector.pop_back();
        ui->output_2->clear();
        for(int i = 0;i < stringVector.size();i++)
        {
            ui->output_2->append(stringVector[i] + " ");
        }
    }
}

void MainWindow::on_erase_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();
    QString editElement = ui->pushLine->text();
    QStringList list = editElement.split(" ");
    if(index == 0)
    {
        if (list[0].toInt() < 0 || list[0].toInt() > intVector.size() || list[1].toInt() < 0 || list[1].toInt() > intVector.size() - list[0].toInt())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }

        intVector.erase(list[0].toInt(),list[1].toInt());
        ui->output_2->clear();

        for(int i = 0;i < intVector.size();i++)
        {
            ui->output_2->append(QString::number(intVector[i]) + " ");
        }
    }
    else if(index == 1)
    {
        if(!list[0].toInt() || list[0].toInt() > doubleVector.size() || list[0].toInt() <= 0 || list[1].toInt() < 0 || list[1].toInt() > intVector.size() - list[0].toInt())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }
        else if(!list[1].toDouble() || list.size() > 2)
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }
        doubleVector.erase(list[0].toInt() - 1,list[1].toInt());
        ui->output_2->clear();
        for(int i = 0;i < intVector.size();i++)
        {
            ui->output_2->append(QString::number(doubleVector[i]) + " ");
        }
    }
    else
    {
        if(list[0].toInt() > stringVector.size() || list[0].toInt() <= 0 || list[1].toInt() > stringVector.size() || list[1].toInt() <= 0)
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }
        else if(list.size() > 2)
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }
        stringVector.erase(list[0].toInt(),list[1].toInt());
        ui->output_2->clear();
        for(int i = 0;i < stringVector.size();i++)
        {
            ui->output_2->append(stringVector[i] + " ");
        }
    }
    ui->pushLine->clear();
}

void MainWindow::on_insert_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();

    QString editElement = ui->pushLine->text();
    QStringList list = editElement.split(" ");

    if(index == 0)
    {
        if (list[0].toInt() < 0 || list[0].toInt() > intVector.size())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }
        for(int i = 1;i < list.size();i++)
        {
            if(!list[i].toInt())
            {
                QMessageBox::warning(this,"Беда","Некорректный ввод");
                ui->pushLine->clear();
                return;
            }
        }
        for(int i = 1;i < list.size();i++)
        {
            int num = list[list.size() - i].toInt();
            int pos = list[0].toInt();
            intVector.Insert(pos,{num});
        }
        ui->output_2->clear();
        for(int i = 0;i < intVector.size();i++)
        {
            ui->output_2->append(QString::number(intVector[i]) + " ");
        }
    }
    else if(index == 1)
    {
        if (list[0].toInt() < 0 || list[0].toInt() > doubleVector.size())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }
        for(int i = 1; i < list.size();i++)
        {
            if(!list[i].toDouble())
            {
                QMessageBox::warning(this,"Oh...","Invalid value!");
                ui->pushLine->clear();
                return;
            }
        }
        for(int i = 1;i < list.size();i++)
        {
            double num = list[list.size() - i].toDouble();
            int pos = list[0].toInt();
            doubleVector.Insert(pos,{num});
        }
        ui->output_2->clear();
        for(int i = 0;i < doubleVector.size();i++)
        {
            ui->output_2->append(QString::number(doubleVector[i]) + " ");
        }
    }
    else
    {
        if (list[0].toInt() <= 0 || list[0].toInt() > stringVector.size() || !list[0].toInt())
        {
            QMessageBox::warning(this,"Беда","Некорректный ввод");
            ui->pushLine->clear();
            return;
        }
        for(int i = 1;i < list.size();i++)
        {
            int pos = list[0].toInt();
            stringVector.Insert(pos,{list[list.size() - i]});
        }
        ui->output_2->clear();
        for(int i = 0;i < stringVector.size();i++)
        {
            ui->output_2->append(stringVector[i] + " ");
        }
    }
}

void MainWindow::on_assign_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    ui->swapLine->clear();
    QString editElement = ui->pushLine->text();
    QStringList list = editElement.split(" ");

    if (index == 0)
    {
        for(int i = 0;i < list.size();i++)
        {
            if(!list[i].toInt())
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                ui->pushLine->clear();
                return;
            }
        }
        int count = 0;
        QString q = "";
        Vector<int> a;
        for (int i = 0; i < editElement.size(); i++)
            {
                QString df = editElement[i];
                if (((editElement[i] > '9' || editElement[i] < '0') && editElement[i] != ' ') || count == 2)
                {
                    QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                    ui->pushLine->clear();
                    return;
                }
                if (editElement[i] == ' ')
                {
                    count++;
                    a.push_back(q.toInt());
                    q = "";
                    continue;
                }
                else
                {
                    count = 0;
                    q += editElement[i];
                    if (i == editElement.size() - 1)
                    {
                        a.push_back(q.toInt());
                    }
                }
            }
            intVector.assign(a);
            ui->output_2->clear();
            for(int i = 0;i < intVector.size();i++)
            {
                ui->output_2->append(QString::number(intVector[i]) + " ");
            }
    }
    else if (index == 1)
    {
        for(int i = 1;i < list.size();i++)
        {
            if(!list[i].toDouble())
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                ui->pushLine->clear();
                return;
            }
        }
        int count = 0;
        int chka = 0;
        int sss = 0;
        QString q = "";
        Vector<double> a;
        for (int i = 0; i < editElement.size(); i++)
        {
            if (((editElement[i] > '9' || editElement[i] < '0') && editElement[i] != ' ' && editElement[i] != '.') || count == 2 || chka == 2)
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                ui->pushLine->clear();
                return;
            }
            if (editElement[i] == '.')
            {
                chka++;
                q += editElement[i];
                continue;
            }
            else if (editElement[i] == ' ')
            {
                count++;
                a.push_back(q.toDouble());
                q = "";
                continue;
            }
            else
            {
                count = 0;
                chka = 0;
                q += editElement[i];
                if (i == editElement.size() - 1)
                {
                    a.push_back(q.toDouble());
                }
            }
        }
        doubleVector.assign(a);
        ui->output_2->clear();
        for(int i = 0;i < doubleVector.size();i++)
        {
            ui->output_2->append(QString::number(doubleVector[i]) + " ");
        }
    }
    else
    {
        int count = 0;
        QString q = "";
        int first;
        Vector<QString> a;
        for (int i = 0; i < editElement.size(); i++)
        {
            if (count == 2)
            {
                QMessageBox::warning(this,"Беда","Ошибка в заполнении");
                ui->pushLine->clear();
                return;
            }
            else if (editElement[i] == ' ')
            {
                count++;
                a.push_back(q);
                q = "";
                continue;
            }
            else
            {
                count = 0;
                q += editElement[i];
                if (i == editElement.size() - 1)
                {
                    a.push_back(q);
                }
            }
        }
        stringVector.assign(a);
        ui->output_2->clear();
        for(int i = 0;i < stringVector.size();i++)
        {
            ui->output_2->append(stringVector[i] + " ");
        }
    }
}
