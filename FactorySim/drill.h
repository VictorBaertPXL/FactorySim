// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 6: useful and correct inheritance
// vraag 7: useful and correct polymorphism
// vraag 8: useful and correct object composition
// vraag 9: useful and correct base class
// vraag 22: useful member variable
// vraag 36: useful container class

#ifndef DRILL_H
#define DRILL_H

#include "Machine.h"
#include "Item.h"
#include <vector>        // vraag 36: useful container class
#include <QPainter>      // vraag 42: useful Qt class

class FactoryEngine;

class Drill : public Machine
{
public:
    Drill(int r, int c);                 // vraag 13: parameterized constructor
    Drill(const Drill& other) = delete;  // vraag 14: copy constructor (deleted)
    ~Drill();                            // vraag 15: destructor

    void draw(QPainter& p) const override;          // vraag 11: virtual function
    void process(FactoryEngine* engine) override;   // vraag 20: useful member function

    std::vector<Item*>& getBuffer();                // vraag 23: useful getter

private:
    std::vector<Item*> buffer;          // vraag 36: useful container class
    int productionTimer = 0;            // vraag 22: useful member variable
};

#endif
