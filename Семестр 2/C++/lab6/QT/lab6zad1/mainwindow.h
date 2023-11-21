#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <binaryTree.h>

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
    void on_empty_clicked();

    void on_insert_5_clicked();

    void on_insert_3_clicked();

    void on_push_clicked();

    void on_insert_4_clicked();

    void on_erase_clicked();

    void on_clear_clicked();

    void on_insert_clicked();

    void on_capacity_clicked();

    void on_pop_clicked();

    void on_size_clicked();

private:
    Ui::MainWindow *ui;
    TreeTask a;
};
#endif // MAINWINDOW_H
