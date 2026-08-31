// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 8: useful and correct object composition
// vraag 22: useful member variable
// vraag 36: useful container class

#ifndef FACTORYGRID_H
#define FACTORYGRID_H

#include <vector>   // vraag 36: useful container class

class FactoryGrid
{
public:
    FactoryGrid();                 // vraag 12: default constructor
    FactoryGrid(int rows, int cols); // vraag 13: parameterized constructor
    FactoryGrid(const FactoryGrid& other); // vraag 14: copy constructor
    ~FactoryGrid();                // vraag 15: destructor

    int getRows() const;           // vraag 20: useful member function
    int getCols() const;           // vraag 20

private:
    int rows;                      // vraag 22: useful member variable
    int cols;                      // vraag 22

    std::vector<std::vector<int>> grid;   // vraag 36: useful container class
};

#endif
