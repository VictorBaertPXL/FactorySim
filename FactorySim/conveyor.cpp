#include "Conveyor.h"
#include "FactoryEngine.h"
#include <cmath>

Conveyor::Conveyor(int r, int c, Direction d)
    : Machine(r, c), dir(d)
{
}

void Conveyor::acceptItem(Item* it)
{
    // Reset pixel position to conveyor tile
    it->px = col() * 30;
    it->py = row() * 30;

    buffer.push_back(it);
}

void Conveyor::rotate()
{
    if (dir == Direction::Right) dir = Direction::Down;
    else if (dir == Direction::Down) dir = Direction::Left;
    else if (dir == Direction::Left) dir = Direction::Up;
    else if (dir == Direction::Up) dir = Direction::Right;
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

    const int speed = 6; // pixels per tick

    // Smooth pixel movement
    if (dir == Direction::Right) it->px += speed;
    if (dir == Direction::Left)  it->px -= speed;
    if (dir == Direction::Up)    it->py -= speed;
    if (dir == Direction::Down)  it->py += speed;

    // Target tile
    int targetRow = row();
    int targetCol = col();

    if (dir == Direction::Right) targetCol++;
    if (dir == Direction::Left)  targetCol--;
    if (dir == Direction::Up)    targetRow--;
    if (dir == Direction::Down)  targetRow++;

    // Out of bounds protection
    if (targetRow < 0 || targetRow >= 20 ||
        targetCol < 0 || targetCol >= 20)
    {
        buffer.erase(buffer.begin());
        delete it;
        return;
    }

    int targetPx = targetCol * 30;
    int targetPy = targetRow * 30;

    // Reached next tile?
    if (std::abs(it->px - targetPx) <= speed &&
        std::abs(it->py - targetPy) <= speed)
    {
        it->px = targetPx;
        it->py = targetPy;
        it->setPos(targetRow, targetCol);

        // Pass item to next machine
        for (auto* m : engine->getMachines())
        {
            if (m->row() == targetRow && m->col() == targetCol)
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
}
