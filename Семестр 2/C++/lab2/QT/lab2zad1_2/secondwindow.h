#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <vector.h>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(Vector _arr, int _size, QString _a, QWidget *parent = nullptr);
    ~secondwindow();

private:
    Ui::secondwindow *ui;
    Vector arr;
    int size;
    QString a;
};

#endif // SECONDWINDOW_H
