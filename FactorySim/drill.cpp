#include "Drill.h"
#include "FactoryEngine.h"
#include "Conveyor.h"

Drill::Drill(int r, int c)
    : Machine(r, c)   // vraag 16: member initialization list
{
}

Drill::~Drill()   // vraag 15: destructor
{
}

void Drill::draw(QPainter& p) const
{
    int cellSize = 30;
    int x = gridX();
    int y = gridY();

    p.setBrush(Qt::gray);
    p.drawRect(x, y, cellSize, cellSize);

    p.setPen(Qt::black);
    p.drawText(x + 10, y + 20, "D");
}

void Drill::process(FactoryEngine* engine)   // vraag 20: useful member function
{
    const int productionDelay = 10;

    if (productionTimer < productionDelay)
    {
        productionTimer++;
        return;
    }

    productionTimer = 0;

    Item* it = new Item(row(), col());   // vraag 32: dynamic memory allocation (new)
    it->px = gridX();
    it->py = gridY();
    it->type = ItemType::Ball;

    int outRow = row();
    int outCol = col() + 1;

    Conveyor* rightConv = nullptr;

    for (auto* m : engine->getMachines())   // vraag 18: dynamic polymorphism
    {
        if (m->row() == outRow && m->col() == outCol)
        {
            rightConv = dynamic_cast<Conveyor*>(m);   // vraag 18
            break;
        }
    }

    if (rightConv)
    {
        rightConv->acceptItem(it);
    }
    else
    {
        buffer.push_back(it);   // vraag 36: useful container class
    }
}

std::vector<Item*>& Drill::getBuffer()   // vraag 23: useful getter
{
    return buffer;
}
