#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <list.h>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;

public slots:
    void slot(QString a, int size, List arr_);
};

#endif // FORM_H
