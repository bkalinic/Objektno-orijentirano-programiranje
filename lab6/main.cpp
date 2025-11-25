#include <iostream>
#include "container.h"

using namespace std;

void passCon(container c) {
	cout << "Velicina niza: " << c.size() << endl;
	cout << "Alocirana memorija: " << c.capacity() << endl;
}
container returnCon(container c) {
	return move(c);
}

int main() {
	container c1 = container(5);	//Zadatak 1
	c1.push_back(10);
	c1.push_back(20);
	c1.push_back(30);

	container c2 = c1;				//Zadatak 2
	container novi = move(c1);		//Zadatak 3
	passCon(c1);					//Zadatak 4
	container c3 = returnCon(c1);	//Zadatak 5

	c1.push_back(40);				//Zadatak 6
	c1.push_back(50);
	c1.push_back(60);
	cout << c1.capacity() << endl;

	//Zadatak 7
	for (int i = 0; i < c1.size(); i++) {
		cout << "Indeks " << i << ": " << c1.at(i) << endl;
	}

	return 0;
}