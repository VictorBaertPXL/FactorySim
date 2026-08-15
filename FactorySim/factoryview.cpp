#include "FactoryView.h"
#include "Drill.h"


FactoryView::FactoryView(FactoryEngine* eng, ToolbarController* tb, QWidget* parent)
    : QWidget(parent), engine(eng), toolbar(tb)
{
}

void FactoryView::paintEvent(QPaintEvent*)
{
    QPainter p(this);

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
    {
        m->draw(p);
    }
}

void FactoryView::mousePressEvent(QMouseEvent* event)
{
    int cellSize = 30;

    int col = event->position().x() / cellSize;
    int row = event->position().y() / cellSize;

    if (toolbar->currentTool() == Tool::PlaceDrill)
    {
        engine->addMachine(new Drill(row, col));   // vraag 18
        update();
    }
}
