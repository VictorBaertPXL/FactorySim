// vraag 36: useful container class

#ifndef FACTORYGRID_H
#define FACTORYGRID_H

#include <vector>

class FactoryGrid
{
public:
    // vraag 12: default constructor
    FactoryGrid();

    // vraag 13: parameterized constructor
    FactoryGrid(int rows, int cols);

    // vraag 14: copy constructor
    FactoryGrid(const FactoryGrid& other);

    // vraag 15: destructor
    ~FactoryGrid();

    // vraag 20: useful member function
    int getRows() const;
    int getCols() const;

private:
    int rows;
    int cols;

    // vraag 36: useful container class
    std::vector<std::vector<int>> grid;
};

#endif
