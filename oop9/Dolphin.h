#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "mammal.h"
#include "aquatic.h"
#include <string>

class Dolphin : public Mammal, public Aquatic {
public:
    Dolphin(const std::string& name, int age, double weight);
    virtual ~Dolphin() = default;

    std::string getSpecies() const override;
    double getDailyFood() const override;
};

#endif