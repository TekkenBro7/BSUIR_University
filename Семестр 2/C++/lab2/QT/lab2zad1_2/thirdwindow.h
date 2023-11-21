#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>
#include <vector.h>

namespace Ui {
class thirdwindow;
}

class thirdwindow : public QDialog
{
    Q_OBJECT

public:
    explicit thirdwindow(Vector _arr, int _size, int _a, QWidget *parent = nullptr);
    ~thirdwindow();

private:
    Ui::thirdwindow *ui;
    Vector arr;
    int size;
    int a;




};

#endif // THIRDWINDOW_H
