// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 6: useful and correct inheritance
// vraag 7: useful and correct polymorphism
// vraag 8: useful and correct object composition
// vraag 9: useful and correct base class
// vraag 22: useful member variable
// vraag 36: useful container class

#ifndef CONVEYOR_H
#define CONVEYOR_H

#include "Machine.h"
#include "Item.h"
#include <vector>        // vraag 36: useful container class
#include <QPainter>      // vraag 42: useful Qt class

class FactoryEngine;

enum class Direction
{
    Right,
    Left,
    Up,
    Down
}; // vraag 33: enum

class Conveyor : public Machine
{
public:
    Conveyor(int r, int c, Direction d);     // vraag 13: parameterized constructor
    Conveyor(const Conveyor& other) = delete; // vraag 14: copy constructor (deleted)
    ~Conveyor();                              // vraag 15: destructor

    void draw(QPainter& p) const override;          // vraag 11: virtual function
    void process(FactoryEngine* engine) override;   // vraag 20: useful member function

    void acceptItem(Item* it);                      // vraag 23: useful setter
    std::vector<Item*>& getBuffer();                // vraag 23: useful getter
    void rotate(int steps = 1);                     // vraag 21: default value in function

    Direction getDirection() const;                 // vraag 23: useful getter

private:
    Direction dir;               // vraag 22: useful member variable
    std::vector<Item*> buffer;   // vraag 36: useful container class
};

#endif
