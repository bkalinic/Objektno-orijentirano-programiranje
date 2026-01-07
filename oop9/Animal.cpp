#include "Animal.h"

Animal::Animal(std::string n, int g, int t) : name(n), age(g), weight(t) {
	if (name.empty()) {
		throw std::invalid_argument("Ime je prazno");
	}
	if (age < 0) {
		throw std::invalid_argument("Pogreska u godinama");
	}
	if (weight <= 0) {
		throw std::invalid_argument("Pogreska u tezini");
	}
}

std::string Animal::getName() const {
	return name;
}

int Animal::getAge() const {
	return age;
}

double Animal::getWeight() const {
	return weight;
}
