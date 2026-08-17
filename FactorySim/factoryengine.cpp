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

void FactoryEngine::processAll()
{
    for (auto* m : machines)
    {
        if (auto* d = dynamic_cast<Drill*>(m))      // vraag 18
            d->process(this);

        if (auto* c = dynamic_cast<Conveyor*>(m))   // vraag 18
            c->process(this);
    }
}
