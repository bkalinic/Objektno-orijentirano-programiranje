#include "vektor.h"
#include <iostream>

using namespace std;

void main() {
	int prvi, zadnji, velicina;
	Vektor* v = vector_new(5);

	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30);
	vector_push_back(v, 40);
	vector_push_back(v, 50);

	prvi = vector_front(v);
	zadnji = vector_back(v);
	velicina = vector_size(v);
	cout << prvi << " " << zadnji << " " << velicina << endl;

	vector_pop_back(v);
	vector_pop_back(v);

	prvi = vector_front(v);
	zadnji = vector_back(v);
	velicina = vector_size(v);
	cout << prvi << " " << zadnji << " " << velicina << endl;
}