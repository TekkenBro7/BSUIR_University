#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class thirdwindow;
}

class thirdwindow : public QDialog
{
    Q_OBJECT

public:
    explicit thirdwindow(List _arr, int _size, QString _a, QString _b,QWidget *parent = nullptr);
    ~thirdwindow();

private:
    List arr;
    int size;
    QString a;
    QString b;
    Ui::thirdwindow *ui;
};

#endif // THIRDWINDOW_H
