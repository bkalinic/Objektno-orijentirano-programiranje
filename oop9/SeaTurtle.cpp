#include "seaturtle.h"
#include <stdexcept>

SeaTurtle::SeaTurtle(const std::string& name, int age, double weight) : 
    Animal(name, age, weight), Aquatic(name, age, weight, 200.0) {
}

std::string SeaTurtle::getSpecies() const {
    return "Morska kornjaca";
}

double SeaTurtle::getDailyFood() const {
    double food = weight * 0.03;
    if (food == 0) {
        throw std::logic_error("Kolicina hrane ne moze biti 0");
    }
    return food;
}