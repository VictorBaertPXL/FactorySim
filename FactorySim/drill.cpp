#include "Drill.h"
#include "FactoryEngine.h"
#include "Conveyor.h"

Drill::Drill(int r, int c)
    : Machine(r, c)
{
}

void Drill::draw(QPainter& p) const
{
    int cellSize = 30;
    int x = col() * cellSize;
    int y = row() * cellSize;

    p.setBrush(Qt::blue);
    p.drawRect(x, y, cellSize, cellSize);
}

void Drill::process(FactoryEngine* engine)
{
    buffer.push_back(new Item(row(), col()));

    int nr = row();
    int nc = col() + 1;

    for (auto* m : engine->getMachines())          // vraag 18: dynamic polymorphism
    {
        if (m->row() == nr && m->col() == nc)
        {
            if (auto* c = dynamic_cast<Conveyor*>(m))
            {
                c->acceptItem(buffer.back());
                buffer.pop_back();
            }
            return;
        }
    }
}
