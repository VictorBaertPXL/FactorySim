#include "Drill.h"
#include "FactoryEngine.h"

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
    // Produce item every tick
    Item* it = new Item(row(), col());

    // Pixel position
    it->px = col() * 30;
    it->py = row() * 30;

    buffer.push_back(it);

    // Try to push item to conveyor
    int r = row();
    int c = col() + 1; // drill outputs to the right

    for (auto* m : engine->getMachines())
    {
        if (m->row() == r && m->col() == c)
        {
            if (auto* conv = dynamic_cast<Conveyor*>(m))
            {
                conv->acceptItem(it);
                buffer.erase(buffer.begin());
            }
            return;
        }
    }
}
