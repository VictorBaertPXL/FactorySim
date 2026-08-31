// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 8: useful and correct object composition
// vraag 42: useful Qt class
// vraag 47: usage of a GUI
// vraag 22: useful member variable

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>   // vraag 42: useful Qt class

class FactoryEngine;
class FactoryView;
class ToolbarController;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);   // vraag 12: default constructor
    ~MainWindow();                                     // vraag 15: destructor

private:
    Ui::MainWindow *ui;            // vraag 22: useful member variable

    FactoryEngine* engine;         // vraag 22
    ToolbarController* toolbar;    // vraag 22
    FactoryView* view;             // vraag 22
};

#endif
