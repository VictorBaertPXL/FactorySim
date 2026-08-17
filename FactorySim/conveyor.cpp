#include "Conveyor.h"
#include "FactoryEngine.h"

Conveyor::Conveyor(int r, int c, Direction d)
    : Machine(r, c), dir(d)
{
}

void Conveyor::acceptItem(Item* it)
{
    buffer.push_back(it);
}

void Conveyor::draw(QPainter& p) const
{
    int cellSize = 30;
    int x = col() * cellSize;
    int y = row() * cellSize;

    p.setBrush(Qt::yellow);
    p.drawRect(x, y, cellSize, cellSize);

    p.setBrush(Qt::black);

    if (dir == Direction::Right)
        p.drawPolygon(QPolygon({ QPoint(x+5,y+5), QPoint(x+25,y+15), QPoint(x+5,y+25) }));
    else if (dir == Direction::Left)
        p.drawPolygon(QPolygon({ QPoint(x+25,y+5), QPoint(x+5,y+15), QPoint(x+25,y+25) }));
    else if (dir == Direction::Up)
        p.drawPolygon(QPolygon({ QPoint(x+15,y+5), QPoint(x+25,y+25), QPoint(x+5,y+25) }));
    else if (dir == Direction::Down)
        p.drawPolygon(QPolygon({ QPoint(x+5,y+5), QPoint(x+25,y+5), QPoint(x+15,y+25) }));
}

void Conveyor::process(FactoryEngine* engine)
{
    if (buffer.empty())
        return;

    Item* it = buffer.front();

    int r = row();
    int c = col();

    if (dir == Direction::Right) c++;
    else if (dir == Direction::Left) c--;
    else if (dir == Direction::Up) r--;
    else if (dir == Direction::Down) r++;

    it->setPos(r, c);

    for (auto* m : engine->getMachines())          // vraag 18
    {
        if (m->row() == r && m->col() == c)
        {
            if (auto* next = dynamic_cast<Conveyor*>(m))
            {
                next->acceptItem(it);
                buffer.erase(buffer.begin());
            }
            return;
        }
    }
}
