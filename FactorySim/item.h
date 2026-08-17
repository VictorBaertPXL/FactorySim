// vraag 22: useful member variable

#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
    Item(int r, int c);

    int row() const;
    int col() const;

    void setPos(int r, int c);

private:
    int m_row;   // vraag 22
    int m_col;   // vraag 22
};

#endif
