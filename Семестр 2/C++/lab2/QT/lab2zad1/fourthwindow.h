#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QDialog>
#include <list.h>

namespace Ui {
class fourthwindow;
}

class fourthwindow : public QDialog
{
    Q_OBJECT

public:
    explicit fourthwindow(List _arr, int _size, int _min, QWidget *parent = nullptr);
    ~fourthwindow();

private:
    List arr;
    int size;
    int min;
    Ui::fourthwindow *ui;
};

#endif // FOURTHWINDOW_H
