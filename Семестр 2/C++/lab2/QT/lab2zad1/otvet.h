#ifndef OTVET_H
#define OTVET_H

#include <QString>
#include <QMainWindow>
#include "list.h"
#include <QFile>
#include <QTextStream>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(List _arr,QWidget *parent = nullptr);
    ~Dialog();

private:
    List arr;
    Ui::Dialog *ui1;
};

#endif // OTVET_H
