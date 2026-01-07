#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"
#include <string>

class Mammal : virtual public Animal {
protected:
    bool hasFur;

public:
    Mammal(const std::string& name, int age, double weight, bool hasFur);
    virtual ~Mammal() = default;

    bool getHasFur() const;
};

#endif