// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 6: useful and correct inheritance
// vraag 7: useful and correct polymorphism
// vraag 8: useful and correct object composition
// vraag 9: useful and correct base class

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "Machine.h"
#include "Item.h"
#include <vector>        // vraag 36: useful container class
#include <QPainter>      // vraag 42: useful Qt class

class FactoryEngine;

class Assembler : public Machine
{
public:
    Assembler(int r, int c);   // vraag 13: parameterized constructor
    ~Assembler();              // vraag 15: destructor

    void draw(QPainter& p) const override;          // vraag 11: virtual function
    void process(FactoryEngine* engine) override;   // vraag 20: useful member function
    void acceptItem(Item* it);                      // vraag 23: useful setter

private:
    std::vector<Item*> inputBuffer;                 // vraag 22: useful member variable
};

#endif
