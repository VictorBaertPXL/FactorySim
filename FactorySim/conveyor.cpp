#include "Conveyor.h"
#include "FactoryEngine.h"
#include "Assembler.h"
#include "Item.h"
#include "Utils.h"

Conveyor::Conveyor(int r, int c, Direction d)
    : Machine(r, c), dir(d)   // vraag 16: member initialization list
{
}

Conveyor::~Conveyor()   // vraag 15: destructor
{
}

void Conveyor::draw(QPainter& p) const
{
    int cellSize = 30;
    int x = gridX();
    int y = gridY();

    p.setBrush(QColor(255, 220, 0));
    p.drawRect(x, y, cellSize, cellSize);

    p.setPen(Qt::black);

    switch (dir)
    {
    case Direction::Right: p.drawText(x + 10, y + 20, ">"); break;
    case Direction::Left:  p.drawText(x + 10, y + 20, "<"); break;
    case Direction::Up:    p.drawText(x + 10, y + 20, "^"); break;
    case Direction::Down:  p.drawText(x + 10, y + 20, "v"); break;
    }
}

void Conveyor::acceptItem(Item* it)   // vraag 23: useful setter
{
    buffer.push_back(it);             // vraag 36: useful container class
}

std::vector<Item*>& Conveyor::getBuffer()   // vraag 23: useful getter
{
    return buffer;
}

Direction Conveyor::getDirection() const    // vraag 23: useful getter
{
    return dir;
}

void Conveyor::rotate(int steps)            // vraag 21: default value in function
{
    int s = steps % 4;
    if (s < 0) s += 4;

    for (int i = 0; i < s; ++i)
    {
        switch (dir)
        {
        case Direction::Right: dir = Direction::Down; break;
        case Direction::Down:  dir = Direction::Left; break;
        case Direction::Left:  dir = Direction::Up; break;
        case Direction::Up:    dir = Direction::Right; break;
        }
    }
}

void Conveyor::process(FactoryEngine* engine)   // vraag 20: useful member function
{
    if (buffer.empty())
        return;

    int cellSize = 30;

    for (size_t i = 0; i < buffer.size(); ++i)
    {
        Item* it = buffer[i];
        if (!it) continue;

        int speed = clampValue<int>(2, 1, 5);   // vraag 25: template function

        switch (dir)
        {
        case Direction::Right: it->px += speed; break;
        case Direction::Left:  it->px -= speed; break;
        case Direction::Up:    it->py -= speed; break;
        case Direction::Down:  it->py += speed; break;
        }

        int targetRow = row();
        int targetCol = col();

        switch (dir)
        {
        case Direction::Right: targetCol++; break;
        case Direction::Left:  targetCol--; break;
        case Direction::Up:    targetRow--; break;
        case Direction::Down:  targetRow++; break;
        }

        int itemCol = (it->px + cellSize / 2) / cellSize;
        int itemRow = (it->py + cellSize / 2) / cellSize;

        if (itemCol == targetCol && itemRow == targetRow)
        {
            bool delivered = false;

            for (auto* m : engine->getMachines())   // vraag 18: dynamic polymorphism
            {
                if (m->row() == targetRow && m->col() == targetCol)
                {
                    if (auto* nextConv = dynamic_cast<Conveyor*>(m))   // vraag 18
                    {
                        nextConv->acceptItem(it);
                        buffer.erase(buffer.begin() + i);              // vraag 36
                        i--;
                        delivered = true;
                        break;
                    }

                    if (auto* nextAsm = dynamic_cast<Assembler*>(m))   // vraag 18
                    {
                        nextAsm->acceptItem(it);
                        buffer.erase(buffer.begin() + i);              // vraag 36
                        i--;
                        delivered = true;
                        break;
                    }
                }
            }

            if (!delivered)
            {
                it->px = targetCol * cellSize;
                it->py = targetRow * cellSize;
            }
        }
    }
}
