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

    void draw(QPainter& p) const override;
    void process(FactoryEngine* engine);

    void acceptItem(Item* it);
    void rotate();

    const std::vector<Item*>& getBuffer() const { return buffer; }

private:
    Direction dir;
    std::vector<Item*> buffer;
};

#endif
