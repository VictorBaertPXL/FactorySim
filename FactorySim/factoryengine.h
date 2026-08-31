// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 6: useful and correct inheritance
// vraag 7: useful and correct polymorphism
// vraag 8: useful and correct object composition
// vraag 9: useful and correct base class
// vraag 22: useful member variable
// vraag 36: useful container class
// vraag 26: useful friend class/function

#ifndef FACTORYENGINE_H
#define FACTORYENGINE_H

#include <vector>        // vraag 36: useful container class
#include <string>

class Machine;
class Item;
class FactoryView;

class FactoryEngine
{
public:
    FactoryEngine();     // vraag 12: default constructor
    ~FactoryEngine();    // vraag 15: destructor

    void addMachine(Machine* m);                 // vraag 20: useful member function
    void deleteMachineAt(int row, int col);      // vraag 20
    void processAll();                           // vraag 20

    const std::vector<Machine*>& getMachines() const;   // vraag 23: useful getter

    void saveToFile(const std::string& filename) const;  // vraag 38: file I/O
    void logMachineCount(const std::vector<Machine*>& machinesRef) const;
    void debugItem(const Item& it) const;

    friend class FactoryView;   // vraag 26: friend class

private:
    std::vector<Machine*> machines;   // vraag 36: useful container class
};

#endif
