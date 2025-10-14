#ifndef VEKTOR_H
#define VEKTOR_H

struct Vektor {
	int* elementi;
	size_t logicalSize;
	size_t physicalSize;
};

Vektor* vector_new(size_t init = 10);

void vector_delete(Vektor* v);

void vector_push_back(Vektor* v, int value);

void vector_pop_back(Vektor* v);

int vector_front(const Vektor* v);

int vector_back(const Vektor* v);

size_t vector_size(const Vektor* v);

#endif