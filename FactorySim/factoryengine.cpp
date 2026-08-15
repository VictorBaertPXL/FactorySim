#include "FactoryEngine.h"
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
        Conveyor* c = dynamic_cast<Conveyor*>(m);
        if (c)
        {
            c->process(this);   // vraag 20
        }
    }
}
