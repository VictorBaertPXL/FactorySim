// vraag 7: useful and correct polymorphism
// vraag 11: virtual function
// vraag 15: destructor

#ifndef MACHINE_H
#define MACHINE_H

#include <QPainter>

class Machine
{
public:
    Machine(int r, int c);
    virtual ~Machine();

    virtual void draw(QPainter& p) const = 0;   // vraag 11
    int row() const;
    int col() const;

protected:
    int m_row;
    int m_col;
};

#endif
