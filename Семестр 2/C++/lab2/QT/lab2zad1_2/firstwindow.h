#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QDialog>
#include <vector.h>
#include <mainwindow.h>

namespace Ui {
class firstwindow;
}

class firstwindow : public QDialog
{
    Q_OBJECT

public:
    explicit firstwindow(Vector _arr, int _size, QWidget *parent = nullptr);
    ~firstwindow();

private:
    Ui::firstwindow *ui;
    Vector arr;
    int size;
};

#endif // FIRSTWINDOW_H
