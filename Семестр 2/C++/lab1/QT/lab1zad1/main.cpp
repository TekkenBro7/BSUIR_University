#include "mainwindow.h"

#include <QApplication>

#include <QTextStream>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextStream err(stderr);
    err.setLocale(QLocale::system());

    MainWindow w;
    w.show();
    return a.exec();
}
