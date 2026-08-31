#include "FactoryView.h"
#include "FactoryEngine.h"
#include "ToolbarController.h"
#include "Drill.h"
#include "Conveyor.h"
#include "Assembler.h"
#include <QPainter>      // vraag 42: useful Qt class
#include <QMouseEvent>   // vraag 42
#include <QTimer>        // vraag 42

FactoryView::FactoryView(FactoryEngine* eng, ToolbarController* tb, QWidget* parent)
    : QWidget(parent), engine(eng), toolbar(tb)   // vraag 16: member initialization list
{
    QTimer* timer = new QTimer(this);   // vraag 32: dynamic memory allocation (new)
    connect(timer, &QTimer::timeout, this, &FactoryView::tick);   // vraag 43: signals/slots
    timer->start(8);
}

void FactoryView::tick()   // vraag 43: slot
{
    engine->processAll();   // vraag 18: dynamic polymorphism
    update();
}

void FactoryView::paintEvent(QPaintEvent*)
{
    QPainter p(this);   // vraag 42: useful Qt class
    int cellSize = 30;

    for (int r = 0; r < 20; ++r)
    {
        for (int c = 0; c < 20; ++c)
        {
            p.setBrush(Qt::lightGray);
            p.drawRect(c * cellSize, r * cellSize, cellSize, cellSize);
        }
    }

    for (auto* m : engine->getMachines())   // vraag 18: dynamic polymorphism
        m->draw(p);

    for (auto* m : engine->getMachines())   // vraag 18
    {
        if (auto* c = dynamic_cast<Conveyor*>(m))   // vraag 18
        {
            for (auto* it : c->getBuffer())         // vraag 36: container class
            {
                if (it->type == ItemType::Ball)
                {
                    p.setBrush(Qt::red);
                    p.drawEllipse(it->px + 10, it->py + 10, 10, 10);
                }
                else
                {
                    p.setBrush(Qt::blue);
                    p.drawRect(it->px + 8, it->py + 8, 14, 14);
                }
            }
        }

        if (auto* d = dynamic_cast<Drill*>(m))   // vraag 18
        {
            for (auto* it : d->getBuffer())      // vraag 36
            {
                if (it->type == ItemType::Ball)
                {
                    p.setBrush(Qt::red);
                    p.drawEllipse(it->px + 10, it->py + 10, 10, 10);
                }
                else
                {
                    p.setBrush(Qt::blue);
                    p.drawRect(it->px + 8, it->py + 8, 14, 14);
                }
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
        engine->addMachine(new Drill(row, col));   // vraag 32: new
        return;
    }

    if (toolbar->currentTool() == Tool::PlaceConveyor)
    {
        engine->addMachine(new Conveyor(row, col, Direction::Right));   // vraag 32
        return;
    }

    if (toolbar->currentTool() == Tool::PlaceAssembler)
    {
        engine->addMachine(new Assembler(row, col));   // vraag 32
        return;
    }

    if (toolbar->currentTool() == Tool::RotateConveyor)
    {
        for (auto* m : engine->getMachines())   // vraag 18
        {
            if (m->row() == row && m->col() == col)
            {
                if (auto* c = dynamic_cast<Conveyor*>(m))   // vraag 18
                {
                    c->rotate();   // vraag 21: default value in function
                    update();
                    return;
                }
            }
        }
    }

    if (toolbar->currentTool() == Tool::DeleteMachine)
    {
        engine->deleteMachineAt(row, col);   // vraag 20
        update();
        return;
    }
}
