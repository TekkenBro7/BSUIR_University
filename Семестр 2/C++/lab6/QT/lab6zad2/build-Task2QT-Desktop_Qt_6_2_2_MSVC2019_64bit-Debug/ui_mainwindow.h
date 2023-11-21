/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customplot;
    QPushButton *kolizii;
    QPushButton *search;
    QComboBox *comboBox;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(817, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        customplot = new QCustomPlot(centralwidget);
        customplot->setObjectName(QString::fromUtf8("customplot"));

        verticalLayout->addWidget(customplot);

        kolizii = new QPushButton(centralwidget);
        kolizii->setObjectName(QString::fromUtf8("kolizii"));
        kolizii->setStyleSheet(QString::fromUtf8("float: rigth;\n"
"margin-right: 3%;\n"
"margin-top: 5px;\n"
"border-radius: 5px;\n"
"-moz-border-radius: 5px;\n"
"-webkit-border-radius: 5px;\n"
"padding: 5px 9px;\n"
"font-size: 1.2em;\n"
"background-color: rgba(236, 101, 80, 1);\n"
"text-shadow: #4545545 0 0 2px;\n"
"border-bottom: 4px solid rgba(217, 91, 72, 1);\n"
"color: white;\n"
"font-family: 'Roboto Slab', serif;\n"
""));

        verticalLayout->addWidget(kolizii);

        search = new QPushButton(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setStyleSheet(QString::fromUtf8("float: rigth;\n"
"margin-right: 3%;\n"
"margin-top: 5px;\n"
"border-radius: 5px;\n"
"-moz-border-radius: 5px;\n"
"-webkit-border-radius: 5px;\n"
"padding: 5px 9px;\n"
"font-size: 1.2em;\n"
"background-color: rgba(236, 101, 80, 1);\n"
"text-shadow: #4545545 0 0 2px;\n"
"border-bottom: 4px solid rgba(217, 91, 72, 1);\n"
"color: white;\n"
"font-family: 'Roboto Slab', serif;"));

        verticalLayout->addWidget(search);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 817, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        kolizii->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\273\320\270\320\267\320\270\320\270", nullptr));
        search->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "16", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "64", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "128", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "2048", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
