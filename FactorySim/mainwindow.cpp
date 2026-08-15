#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FactoryView.h"
#include "ToolbarController.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    engine = new FactoryEngine();
    toolbar = new ToolbarController(this);

    connect(ui->actionAddDrill, &QAction::triggered,
            toolbar, &ToolbarController::onAddDrillClicked);

    connect(ui->actionDeselect, &QAction::triggered,
            toolbar, &ToolbarController::onDeselectClicked);

    FactoryView* view = new FactoryView(engine, toolbar, this);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete engine;
}
