#include "FactoryView.h"

// vraag 12: default constructor
FactoryView::FactoryView(FactoryEngine* eng, QWidget* parent)
    : QWidget(parent), engine(eng)
{
}

void FactoryView::paintEvent(QPaintEvent*)
{
    // vraag 42: useful Qt class (QPainter)
    QPainter p(this);

    FactoryGrid& grid = engine->getGrid();

    int cellSize = 30;

    // vraag 20: useful member function
    for (int r = 0; r < grid.getRows(); ++r)
    {
        for (int c = 0; c < grid.getCols(); ++c)
        {
            p.setBrush(Qt::lightGray);
            p.drawRect(c * cellSize, r * cellSize, cellSize, cellSize);
        }
    }
}
