#include "FactoryEngine.h"

// vraag 12: default constructor
FactoryEngine::FactoryEngine()
    : grid(20, 20) // vraag 13: parameterized constructor
{
}

FactoryGrid& FactoryEngine::getGrid()
{
    return grid;
}
