#include "dolphin.h"
#include <stdexcept>

Dolphin::Dolphin(const std::string& name, int age, double weight) : 
    Animal(name, age, weight),
    Mammal(name, age, weight, true),
    Aquatic(name, age, weight, 300.0) {
}

std::string Dolphin::getSpecies() const {
    return "Dupin";
}

double Dolphin::getDailyFood() const {
    double food = weight * 0.05;
    if (food == 0) {
        throw std::logic_error("Kolicina hrane ne moze biti 0");
    }
    return food;
}