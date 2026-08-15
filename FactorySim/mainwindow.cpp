#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FactoryView.h"
#include "ToolbarController.h"
#include "Conveyor.h"
#include "Drill.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    engine = new FactoryEngine();
    toolbar = new ToolbarController(this);

    // Drill
    connect(ui->actionAddDrill, &QAction::triggered,
            toolbar, &ToolbarController::onAddDrillClicked);

    // Conveyor
    connect(ui->actionAddConveyor, &QAction::triggered,
            toolbar, &ToolbarController::onAddConveyorClicked);

    // Deselect
    connect(ui->actionDeselect, &QAction::triggered,
            toolbar, &ToolbarController::onDeselectClicked);

    // View
    FactoryView* view = new FactoryView(engine, toolbar, this);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete engine;
    delete toolbar;
}
