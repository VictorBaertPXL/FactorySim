// vraag 1: clean main
// vraag 2: no globals
// vraag 42: useful Qt class
// vraag 47: usage of a GUI

#include "mainwindow.h"
#include <QApplication>   // vraag 42

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   // vraag 42: useful Qt class
    MainWindow w;                 // vraag 47: usage of a GUI
    w.show();
    return a.exec();
}
