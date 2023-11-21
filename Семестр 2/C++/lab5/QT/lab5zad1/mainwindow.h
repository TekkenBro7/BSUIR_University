#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Queue.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_push_clicked();


    void on_pop_clicked();

    void on_empty_clicked();

    void on_size_clicked();

    void on_erase_clicked();

    void on_capacity_clicked();

    void on_capacity_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
