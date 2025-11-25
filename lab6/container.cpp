#include <iostream>
#include <stdexcept>
#include "container.h"

using namespace std;

container::container(size_t init) {
	elementi = new int[init];
	logicalSize = init;
	physicalSize = 0;
	cout << "Objekt kreiran!" << endl;
}
container::container(const container& other) {
	elementi = new int(*other.elementi);
	logicalSize = other.logicalSize;
	physicalSize = other.physicalSize;
	cout << "Objekt kopiran!" << endl;
}
container::container(container&& other) : 
	elementi(move(other.elementi)),
	logicalSize(move(other.logicalSize)),
	physicalSize(move(other.physicalSize)) {
	cout << "Objekt pomaknut!" << endl;
}
container::~container() {
	for (int i = 0; i < physicalSize; i++) {
		delete elementi[i];
	}
	delete[] elementi;
	cout << "Objekt izbrisan!" << endl;
}
	
void container::push_back(int value) {
	if (physicalSize >= logicalSize) {
		size_t newCapacity = logicalSize * 2;
		int* newElements = new int[newCapacity];

		for (size_t i = 0; i < physicalSize; i++) {
			newElements[i] = elementi[i];
		}

		delete elementi;
		elementi = newElements;
		logicalSize = newCapacity;
	}
	elementi[physicalSize] = value;
	physicalSize++;
}
size_t container::size() const {
	if (physicalSize == 0) {
		throw invalid_argument("Vektor je prazan");
	}
	return physicalSize;
}
size_t container::capacity() const {
	return logicalSize;
}
int container::at(int i) const {
	return elementi[i];
}
void container::clear() {
	physicalSize = 0;
}