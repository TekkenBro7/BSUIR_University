#ifndef FIFTHWINDOW_H
#define FIFTHWINDOW_H

#include <QDialog>
#include <list.h>

namespace Ui {
class fifthwindow;
}

class fifthwindow : public QDialog
{
    Q_OBJECT

public:
    explicit fifthwindow(List _arr, int _size, double _rostt, QWidget *parent = nullptr);
    ~fifthwindow();

private:
    List arr;
    int size;
    double rostt;
    Ui::fifthwindow *ui;
};

#endif // FIFTHWINDOW_H
