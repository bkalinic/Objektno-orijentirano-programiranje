#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <stdexcept>

class Animal {
protected:
	std::string name;
	int age;
	int weight;

	Animal(std::string n, int g, int t);
public:
	virtual ~Animal() = default;

	virtual std::string getSpecies() const = 0;
	virtual double getDailyFood() const = 0;
	virtual std::string getName() const;
	int getAge() const;
	double getWeight() const;
};

#endif