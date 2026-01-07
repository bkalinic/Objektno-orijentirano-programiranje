#include "Mammal.h"
#include <iostream>

Mammal::Mammal(const std::string& name, int age, double weight, bool hasFur) :
    Animal(name, age, weight), hasFur(hasFur) {

    if (hasFur) {
        std::cout << "Stvoren sisavac s dlakom" << std::endl;
    }
    else {
        std::cout << "Stvoren sisavac s malo dlake" << std::endl;
    }
}

bool Mammal::getHasFur() const {
    return hasFur;
}