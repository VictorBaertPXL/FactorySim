#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "FactoryEngine.h"
#include "FactoryView.h"
#include "ToolbarController.h"
#include <thread>       // vraag 41: useful threads
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)   // vraag 16: member initialization list
{
    ui->setupUi(this);

    engine = new FactoryEngine();                 // vraag 32: dynamic memory allocation (new)
    toolbar = new ToolbarController(this);        // vraag 32
    view = new FactoryView(engine, toolbar, this); // vraag 32
    setCentralWidget(view);

    std::thread autosaveThread([this]() {         // vraag 40: lambda function
        while (true)
        {
            engine->saveToFile("save.txt");       // vraag 38: file I/O
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
    });
    autosaveThread.detach();                      // vraag 41: useful threads

    connect(ui->actionAddDrill, &QAction::triggered,
            toolbar, &ToolbarController::onPlaceDrillClicked);     // vraag 43: signals/slots

    connect(ui->actionAddConveyor, &QAction::triggered,
            toolbar, &ToolbarController::onPlaceConveyorClicked);  // vraag 43

    connect(ui->actionAddAssembler, &QAction::triggered,
            toolbar, &ToolbarController::onPlaceAssemblerClicked); // vraag 43

    connect(ui->actionRotateConveyor, &QAction::triggered,
            toolbar, &ToolbarController::onRotateConveyorClicked); // vraag 43

    connect(ui->actionDeleteMachine, &QAction::triggered,
            toolbar, &ToolbarController::onDeleteMachineClicked);  // vraag 43

    connect(ui->actionDeselect, &QAction::triggered,
            toolbar, &ToolbarController::onDeselectClicked);       // vraag 43
}

MainWindow::~MainWindow()   // vraag 15: destructor
{
    delete ui;
    delete engine;   // vraag 33: dynamic memory removing (delete)
}
