#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <stdexcept>

class Animal {
protected:
	std::string ime;
	int godine;
	int tezina;
public:
	Animal(std::string i, int g, int t);
	virtual ~Animal();

	virtual std::string getSpecies() const = 0;
	virtual double getDailyFood() const = 0;
	virtual std::string getName() const = 0;
};

#endif