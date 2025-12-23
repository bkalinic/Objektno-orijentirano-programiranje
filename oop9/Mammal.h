#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
class Mammal : public Animal {
protected:
	bool hasFur;
public:
	Mammal();
	~Mammal();
};

#endif