#include "Drill.h"

Drill::Drill(int r, int c)
    : Machine(r, c)
{
}

void Drill::draw(QPainter& p) const
{
    p.setBrush(Qt::blue);
    p.drawRect(col() * 30, row() * 30, 30, 30);
}
