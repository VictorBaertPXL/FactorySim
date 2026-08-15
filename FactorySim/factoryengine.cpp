#include "FactoryEngine.h"

FactoryEngine::FactoryEngine()
{
}

void FactoryEngine::addMachine(Machine* m)
{
    machines.push_back(m);
}

const std::vector<Machine*>& FactoryEngine::getMachines() const
{
    return machines;
}
