#include "FactoryView.h"
#include "FactoryEngine.h"
#include "ToolbarController.h"
#include "Drill.h"
#include "Conveyor.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>

FactoryView::FactoryView(FactoryEngine* eng, ToolbarController* tb, QWidget* parent)
    : QWidget(parent), engine(eng), toolbar(tb)
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FactoryView::tick);
    timer->start(200); //200ms
}

void FactoryView::tick()
{
    engine->processAll();
    update();
}

void FactoryView::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    int cellSize = 30;

    // Grid tekenen
    for (int r = 0; r < 20; ++r)
    {
        for (int c = 0; c < 20; ++c)
        {
            p.setBrush(Qt::lightGray);
            p.drawRect(c * cellSize, r * cellSize, cellSize, cellSize);
        }
    }

    // Machines tekenen
    for (auto* m : engine->getMachines())
    {
        m->draw(p);
    }

    // Items tekenen
    for (auto* m : engine->getMachines())
    {
        if (auto* c = dynamic_cast<Conveyor*>(m))
        {
            for (auto* it : c->getBuffer())
            {
                p.setBrush(Qt::red);
                p.drawEllipse(it->col() * cellSize + 10,
                              it->row() * cellSize + 10,
                              10, 10);
            }
        }

        if (auto* d = dynamic_cast<Drill*>(m))
        {
            for (auto* it : d->getBuffer())
            {
                p.setBrush(Qt::red);
                p.drawEllipse(it->col() * cellSize + 10,
                              it->row() * cellSize + 10,
                              10, 10);
            }
        }
    }
}

void FactoryView::mousePressEvent(QMouseEvent* event)
{
    int cellSize = 30;

    int col = event->position().x() / cellSize;
    int row = event->position().y() / cellSize;

    if (toolbar->currentTool() == Tool::PlaceDrill)
    {
        engine->addMachine(new Drill(row, col));
        return;
    }

    if (toolbar->currentTool() == Tool::PlaceConveyor)
    {
        engine->addMachine(new Conveyor(row, col, Direction::Right));
        return;
    }
}
