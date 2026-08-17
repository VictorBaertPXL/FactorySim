#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
    Item(int r, int c);

    int row() const { return r; }
    int col() const { return c; }

    void setPos(int newR, int newC);

    int px; // pixel X
    int py; // pixel Y

private:
    int r;
    int c;
};

#endif
