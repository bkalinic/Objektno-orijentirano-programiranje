#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "mammal.h"
#include <string>

class Elephant : public Mammal {
public:
    Elephant(const std::string& name, int age, double weight);
    virtual ~Elephant() = default;

    std::string getSpecies() const override;
    double getDailyFood() const override;
};

#endif