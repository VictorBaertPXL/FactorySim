#include "Item.h"

Item::Item(int r_, int c_)
    : r(r_), c(c_)
{
    px = c * 30;
    py = r * 30;
}

void Item::setPos(int newR, int newC)
{
    r = newR;
    c = newC;

    px = c * 30;
    py = r * 30;
}
