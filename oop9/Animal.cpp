#include "Animal.h"

Animal::Animal(std::string i, int g, int t) : ime(i), godine(g), tezina(t) {
	if (ime.empty()) {
		throw std::invalid_argument("Ime je prazno");
	}
	if (godine < 0) {
		throw std::invalid_argument("Pogreska u godinama");
	}
	if (tezina <= 0) {
		throw std::invalid_argument("Pogreska u tezini");
	}
}
Animal::~Animal() {
	std::cout << "Animal " << ime << " izbrisan" << std::endl;
}
