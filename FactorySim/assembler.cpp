#include "Assembler.h"
#include "FactoryEngine.h"
#include "Conveyor.h"

Assembler::Assembler(int r, int c)
    : Machine(r, c)   // vraag 16: member initialization list
{
}

Assembler::~Assembler()   // vraag 15: destructor
{
}

void Assembler::draw(QPainter& p) const
{
    int cellSize = 30;
    int x = gridX();
    int y = gridY();

    p.setBrush(Qt::green);
    p.drawRect(x, y, cellSize, cellSize);

    p.setPen(Qt::black);
    p.drawText(x + 10, y + 20, "A");
}

void Assembler::acceptItem(Item* it)   // vraag 23: useful setter
{
    it->px = gridX();
    it->py = gridY();
    inputBuffer.push_back(it);         // vraag 36: useful container class
}

void Assembler::process(FactoryEngine* engine)   // vraag 20: useful member function
{
    if (inputBuffer.empty())
        return;

    Item* it = inputBuffer.front();
    if (!it)
        return;

    it->type = ItemType::Block;
    it->setPos(row(), col());

    int outRow = row();
    int outCol = col() + 1;

    for (auto* m : engine->getMachines())   // vraag 18: dynamic polymorphism
    {
        if (m->row() == outRow && m->col() == outCol)
        {
            if (auto* conv = dynamic_cast<Conveyor*>(m))   // vraag 18: dynamic polymorphism
            {
                conv->acceptItem(it);
                inputBuffer.erase(inputBuffer.begin());    // vraag 36: useful container class
            }
            return;
        }
    }
}
