#include "FactoryEngine.h"
#include "Drill.h"
#include "Conveyor.h"

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

void FactoryEngine::deleteMachineAt(int row, int col)
{
    for (size_t i = 0; i < machines.size(); ++i)
    {
        if (machines[i]->row() == row && machines[i]->col() == col)
        {
            delete machines[i];
            machines.erase(machines.begin() + i);
            return;
        }
    }
}

void FactoryEngine::processAll()
{
    for (auto* m : machines)
    {
        if (auto* d = dynamic_cast<Drill*>(m))
            d->process(this);

        if (auto* c = dynamic_cast<Conveyor*>(m))
            c->process(this);
    }
}
