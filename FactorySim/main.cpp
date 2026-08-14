// vraag 1: clean main
// vraag 2: no globals

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   // vraag 42: useful Qt class
    MainWindow w;                 // vraag 47: usage of a GUI
    w.show();
    return a.exec();
}
