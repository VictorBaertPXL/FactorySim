/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddDrill;
    QAction *actionAddConveyor;
    QAction *actionDeselect;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        actionAddDrill = new QAction(MainWindow);
        actionAddDrill->setObjectName("actionAddDrill");
        actionAddConveyor = new QAction(MainWindow);
        actionAddConveyor->setObjectName("actionAddConveyor");
        actionDeselect = new QAction(MainWindow);
        actionDeselect->setObjectName("actionDeselect");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        MainWindow->setMenuBar(menubar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(mainToolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTools->menuAction());
        menuTools->addAction(actionAddDrill);
        menuTools->addAction(actionAddConveyor);
        menuTools->addAction(actionDeselect);
        mainToolBar->addAction(actionAddDrill);
        mainToolBar->addAction(actionAddConveyor);
        mainToolBar->addAction(actionDeselect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FactorySim", nullptr));
        actionAddDrill->setText(QCoreApplication::translate("MainWindow", "Add Drill", nullptr));
        actionAddConveyor->setText(QCoreApplication::translate("MainWindow", "Add Conveyor", nullptr));
        actionDeselect->setText(QCoreApplication::translate("MainWindow", "Deselect", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
