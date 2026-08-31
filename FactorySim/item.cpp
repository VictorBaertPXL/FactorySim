#include "Item.h"

Item::Item(int r, int c)
    : row(r), col(c), px(c * 30), py(r * 30), type(ItemType::Ball)   // vraag 16: member initialization list
{
}

void Item::setPos(int r, int c)   // vraag 23: useful setter
{
    row = r;
    col = c;
    px = c * 30;
    py = r * 30;
}
