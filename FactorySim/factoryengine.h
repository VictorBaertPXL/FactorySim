#ifndef FACTORYENGINE_H
#define FACTORYENGINE_H

#include <vector>
#include "Machine.h"

class FactoryEngine
{
public:
    FactoryEngine();

    void addMachine(Machine* m);
    void deleteMachineAt(int row, int col);

    const std::vector<Machine*>& getMachines() const;

    void processAll();

private:
    std::vector<Machine*> machines;
};

#endif
