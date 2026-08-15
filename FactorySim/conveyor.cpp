#include "Conveyor.h"
#include "FactoryEngine.h"

Conveyor::Conveyor(int r, int c, Direction d)
    : Machine(r, c), dir(d)
{
}

void Conveyor::draw(QPainter& p) const
{
    int cellSize = 30;
    int x = col() * cellSize;
    int y = row() * cellSize;

    p.setBrush(Qt::yellow);
    p.drawRect(x, y, cellSize, cellSize);

    p.setBrush(Qt::black);

    switch (dir)
    {
    case Direction::Up:
        p.drawPolygon(QPolygon({ QPoint(x+15, y+5), QPoint(x+25, y+25), QPoint(x+5, y+25) }));
        break;
    case Direction::Down:
        p.drawPolygon(QPolygon({ QPoint(x+5, y+5), QPoint(x+25, y+5), QPoint(x+15, y+25) }));
        break;
    case Direction::Left:
        p.drawPolygon(QPolygon({ QPoint(x+5, y+15), QPoint(x+25, y+5), QPoint(x+25, y+25) }));
        break;
    case Direction::Right:
        p.drawPolygon(QPolygon({ QPoint(x+5, y+5), QPoint(x+25, y+15), QPoint(x+5, y+25) }));
        break;
    }
}

void Conveyor::process(FactoryEngine* engine)
{
    if (buffer.empty())
        return;

    int r = row();
    int c = col();

    int nr = r;
    int nc = c;

    if (dir == Direction::Up)    nr--;
    if (dir == Direction::Down)  nr++;
    if (dir == Direction::Left)  nc--;
    if (dir == Direction::Right) nc++;

    for (auto* m : engine->getMachines())   // vraag 18: dynamic polymorphism
    {
        if (m->row() == nr && m->col() == nc)
        {
            Conveyor* next = dynamic_cast<Conveyor*>(m);
            if (next)
            {
                next->buffer.push_back(buffer.back());
                buffer.pop_back();
            }
            return;
        }
    }
}
