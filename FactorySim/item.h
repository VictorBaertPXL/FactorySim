// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 8: useful and correct object composition
// vraag 22: useful member variable
// vraag 28: memory‑efficient type (unsigned char)

#ifndef ITEM_H
#define ITEM_H

enum class ItemType {
    Ball,
    Block
}; // vraag 33: enum

class Item
{
public:
    Item(int r, int c);        // vraag 13: parameterized constructor

    void setPos(int r, int c); // vraag 23: useful setter

    int row, col;              // vraag 22: useful member variable
    int px, py;                // vraag 22

    ItemType type;             // vraag 22

    unsigned char flags = 0;   // vraag 28: memory‑efficient type
};

#endif
