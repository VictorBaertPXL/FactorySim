// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 6: useful and correct inheritance
// vraag 7: useful and correct polymorphism
// vraag 9: useful and correct base class
// vraag 11: useful and correct virtual function
// vraag 22: useful member variable

#ifndef MACHINE_H
#define MACHINE_H

#include <QPainter>   // vraag 42: useful Qt class

class FactoryEngine;

class Machine
{
public:
    Machine(int r, int c) : m_row(r), m_col(c) {}   // vraag 13: parameterized constructor
    virtual ~Machine() {}                           // vraag 15: destructor

    virtual void draw(QPainter& p) const = 0;       // vraag 11: virtual function
    virtual void process(FactoryEngine* engine) = 0; // vraag 11

    int row() const { return m_row; }               // vraag 23: useful getter
    int col() const { return m_col; }               // vraag 23

    inline int gridX() const { return m_col * 30; } // vraag 24: inline function
    inline int gridY() const { return m_row * 30; } // vraag 24

protected:
    int m_row;   // vraag 22: useful member variable
    int m_col;   // vraag 22
};

#endif
