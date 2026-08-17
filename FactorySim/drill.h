#ifndef DRILL_H
#define DRILL_H

#include "Conveyor.h"
#include "Machine.h"
#include "Item.h"
#include <QPainter>
#include <vector>

class FactoryEngine;

class Drill : public Machine
{
public:
    Drill(int r, int c);

    void draw(QPainter& p) const override;
    void process(FactoryEngine* engine);

    const std::vector<Item*>& getBuffer() const { return buffer; }

private:
    std::vector<Item*> buffer;
};

#endif
