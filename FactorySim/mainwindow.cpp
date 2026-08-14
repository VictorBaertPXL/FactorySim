#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FactoryView.h"

// vraag 47: usage of a GUI

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // vraag 22: useful member variable
    engine = new FactoryEngine();

    FactoryView* view = new FactoryView(engine, this);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete engine;
}
