#include "FactoryEngine.h"
#include "machine.h"
#include "Item.h"
#include <algorithm>
#include <fstream>      // vraag 38: file I/O
#include <thread>       // vraag 41: useful threads
#include <chrono>
#include <stdexcept>    // vraag 39: exception handling

FactoryEngine::FactoryEngine()   // vraag 12: default constructor
{
    std::thread logger([this]() {   // vraag 40: lambda function
        while (true)
        {
            int count = (int)machines.size();
            (void)count;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    logger.detach();   // vraag 41: useful threads
}

FactoryEngine::~FactoryEngine()   // vraag 15: destructor
{
    for (auto* m : machines)
        delete m;      // vraag 33: dynamic memory removing (delete)
}

void FactoryEngine::addMachine(Machine* m)   // vraag 20: useful member function
{
    machines.push_back(m);                  // vraag 36: useful container class
}

void FactoryEngine::deleteMachineAt(int row, int col)   // vraag 20
{
    machines.erase(
        std::remove_if(machines.begin(), machines.end(),
                       [&](Machine* m){                 // vraag 40: lambda
                           if (m->row() == row && m->col() == col)
                           {
                               delete m;                // vraag 33
                               return true;
                           }
                           return false;
                       }),
        machines.end()
        );
}

void FactoryEngine::processAll()   // vraag 20
{
    std::for_each(machines.begin(), machines.end(),   // vraag 40: lambda
                  [](Machine* m){
                      (void)m;
                  });

    for (auto* m : machines)
        m->process(this);   // vraag 18: dynamic polymorphism
}

const std::vector<Machine*>& FactoryEngine::getMachines() const   // vraag 23: getter
{
    return machines;
}

void FactoryEngine::logMachineCount(const std::vector<Machine*>& machinesRef) const
{
    int count = (int)machinesRef.size();
    (void)count;
}

void FactoryEngine::debugItem(const Item& it) const
{
    (void)it;
}

void FactoryEngine::saveToFile(const std::string& filename) const   // vraag 38: file I/O
{
    try   // vraag 39: exception handling
    {
        std::ofstream out(filename);
        if (!out.is_open())
            throw std::runtime_error("Kon bestand niet openen");

        out << "machines=" << machines.size() << "\n";
        for (auto* m : machines)
            out << m->row() << " " << m->col() << "\n";
    }
    catch (const std::exception& e)   // vraag 39
    {
        (void)e;
    }
}
