#include "vektor.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Vektor* vector_new(size_t init) {
	Vektor* v = new Vektor;
	v->elementi = new int[init];
	v->logicalSize = 0;
	v->physicalSize = init;
	return v;
}

void vector_delete(Vektor* v) {
	delete v->elementi;
	delete v;
}

void vector_push_back(Vektor* v, int value) {
	if (v->logicalSize >= v->physicalSize) {
		size_t newCapacity = v->physicalSize * 2;
		int* newElements = new int[newCapacity];

		for (size_t i = 0; i < v->logicalSize; i++) {
			newElements[i] = v->elementi[i];
		}

		delete v->elementi;
		v->elementi = newElements;
		v->physicalSize = newCapacity;
	}
	v->elementi[v->logicalSize] = value;
	v->logicalSize++;
}

void vector_pop_back(Vektor* v) {
	if (v->logicalSize == 0) {
		throw invalid_argument("Vektor je prazan");
	}
	v->logicalSize--;
}

int vector_front(const Vektor* v) {
	if (v->logicalSize == 0) {
		throw invalid_argument("Vektor je prazan");
	}
	return v->elementi[0];
}

int vector_back(const Vektor* v) {
	if (v->logicalSize == 0) {
		throw invalid_argument("Vektor je prazan");
	}
	return v->elementi[v->logicalSize-1];
}

size_t vector_size(const Vektor* v) {
	if (v->logicalSize == 0) {
		throw invalid_argument("Vektor je prazan");
	}
	return v->logicalSize;
}
