#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <statlib.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Vector<int> intVector;
    Vector<double> doubleVector;
    Vector<QString> stringVector;

private slots:
    void on_comboBox_2_activated(int index);

    void on_empty_clicked();

    void on_size_clicked();

    void on_capacity_clicked();

    void on_push_clicked();

    void on_swap_clicked();

    void on_pop_clicked();

    void on_erase_clicked();

    void on_insert_clicked();

    void on_resize_clicked();

    void on_clear_clicked();

    void on_assign_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
