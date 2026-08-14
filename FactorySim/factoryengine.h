// vraag 20: useful member function
// vraag 22: useful member variabel

#ifndef FACTORYENGINE_H
#define FACTORYENGINE_H

#include "FactoryGrid.h"

class FactoryEngine
{
public:
    // vraag 12: default constructor
    FactoryEngine();

    // vraag 20: useful member function
    FactoryGrid& getGrid();

private:
    FactoryGrid grid;
};

#endif
