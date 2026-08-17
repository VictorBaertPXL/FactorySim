#include "Item.h"

Item::Item(int r, int c)
    : m_row(r), m_col(c)
{
}

int Item::row() const
{
    return m_row;
}

int Item::col() const
{
    return m_col;
}

void Item::setPos(int r, int c)
{
    m_row = r;
    m_col = c;
}
