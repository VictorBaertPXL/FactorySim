// vraag 7: useful and correct polymorphism
// vraag 11: virtual function
// vraag 22: useful member variable
// vraag 36: useful container class

#ifndef CONVEYOR_H
#define CONVEYOR_H

#include "Machine.h"
#include "Direction.h"
#include "Item.h"
#include <QPainter>
#include <vector>

class FactoryEngine;

class Conveyor : public Machine
{
public:
    Conveyor(int r, int c, Direction d);

    void draw(QPainter& p) const override;          // vraag 11
    void process(FactoryEngine* engine);            // vraag 20

    void acceptItem(Item* it);
    const std::vector<Item*>& getBuffer() const     // vraag 36
    {
        return buffer;
    }

private:
    Direction dir;               // vraag 22
    std::vector<Item*> buffer;   // vraag 36
};

#endif
