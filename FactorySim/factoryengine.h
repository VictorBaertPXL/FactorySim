// vraag 36: useful container class

#ifndef FACTORYENGINE_H
#define FACTORYENGINE_H

#include <vector>
#include "Machine.h"

class FactoryEngine
{
public:
    FactoryEngine();

    void addMachine(Machine* m);   // vraag 20: useful member function
    const std::vector<Machine*>& getMachines() const;

private:
    std::vector<Machine*> machines;   // vraag 36
};

#endif
