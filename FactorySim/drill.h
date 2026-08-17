// vraag 7: useful and correct polymorphism
// vraag 11: virtual function
// vraag 36: useful container class

#ifndef DRILL_H
#define DRILL_H

#include "Machine.h"
#include "Item.h"
#include <QPainter>
#include <vector>

class FactoryEngine;

class Drill : public Machine
{
public:
    Drill(int r, int c);

    void draw(QPainter& p) const override;          // vraag 11
    void process(FactoryEngine* engine);            // vraag 20

    const std::vector<Item*>& getBuffer() const     // vraag 36
    {
        return buffer;
    }

private:
    std::vector<Item*> buffer;                      // vraag 36
};

#endif
