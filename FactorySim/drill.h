// vraag 7: useful and correct polymorphism
// vraag 11: virtual function override

#ifndef DRILL_H
#define DRILL_H

#include "Machine.h"

class Drill : public Machine
{
public:
    Drill(int r, int c);
    void draw(QPainter& p) const override;   // vraag 11
};

#endif
