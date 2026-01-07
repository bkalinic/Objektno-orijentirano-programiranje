#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H

#include "animal.h"
#include <iostream>

class ZooKeeper {
private:
    static size_t totalAnimalsServed;

public:
    void processAnimal(Animal* animal) {
        if (!animal) {
            throw std::invalid_argument("Ne moze se raditi s nullptr zivotinjom");
        }

        std::cout << "Vrsta: " << animal->getSpecies()
            << ", Ime: " << animal->getName()
            << ", Hrana: " << animal->getDailyFood() << "kg"
            << std::endl;

        totalAnimalsServed++;
    }

    static size_t getTotalAnimalsServed() {
        return totalAnimalsServed;
    }
};

#endif