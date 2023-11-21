#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <list.h>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(List _arr, int _size, QString _a, QWidget *parent = nullptr);
    ~SecondWindow();

private:
    List arr;
    int size;
    QString a;
    Ui::SecondWindow *ui;

};

#endif // SECONDWINDOW_H
