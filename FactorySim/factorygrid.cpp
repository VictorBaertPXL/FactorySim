#include "FactoryGrid.h"

// vraag 16: member initialization list
FactoryGrid::FactoryGrid()
    : rows(10), cols(10), grid(rows, std::vector<int>(cols, 0))
{
}

// vraag 16: member initialization list
FactoryGrid::FactoryGrid(int r, int c)
    : rows(r), cols(c), grid(r, std::vector<int>(c, 0))
{
}

// vraag 14: copy constructor
FactoryGrid::FactoryGrid(const FactoryGrid& other)
    : rows(other.rows), cols(other.cols), grid(other.grid)
{
}

// vraag 15: destructor
FactoryGrid::~FactoryGrid()
{
}

int FactoryGrid::getRows() const { return rows; }
int FactoryGrid::getCols() const { return cols; }
