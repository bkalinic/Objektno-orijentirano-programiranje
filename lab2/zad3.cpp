#include <iostream>
#include "matrica.h"

using namespace std;

int main() {
	int redA, stupacA;
	double** matricaA = unos(redA, stupacA);
	ispis(matricaA, redA, stupacA);
	cout << endl;

	int redB, stupacB;
	double** matricaB = unos(redB, stupacB);
	ispis(matricaB, redB, stupacB);
	cout << endl;

	int a, b;
	int redG, stupacG;
	cout << "Odredi granice za generiranje matrice: " << endl;
	cin >> a;
	cin >> b;
	double** matricaG = generiraj(redG, stupacG, a, b);
	cout << "Generirana matrica: " << endl;
	ispis(matricaG, redG, stupacG);
	cout << endl;

	if (redA != redB && stupacA != stupacB) {
		cout << "Matrice se ne mogu zbrojiti jer im se dimenzije ne poklapaju!" << endl;
	}
	else {
		double** zbroj = zbroji(matricaA, matricaB, redA, stupacA);
		double** razlika = oduzmi(matricaA, matricaB, redA, stupacA);
		cout << "Zbroj matrica: " << endl;
		ispis(zbroj, redA, stupacA);
		cout << endl << "Razlika matrica: " << endl;
		ispis(razlika, redA, stupacA);
		cout << endl;
	}

	if (stupacA != redB) {
		cout << "Matrice se ne mogu pomnoziti jer broj stupaca prve matrice ne odgovara broju redaka druge matrice" << endl;
	}
	else {
		double** umnozak = pomnozi(matricaA, matricaB, redA, stupacA, stupacB);
		cout << "Umnozak matrica: " << endl;
		ispis(umnozak, redB, stupacA);
		cout << endl;
	}

	double** tA = transponiraj(matricaA, redA, stupacA);
	cout << "Transponirana matrica A: " << endl;
	ispis(tA, redA, stupacA);
	cout << endl << "Transponirana matrica B: " << endl;;
	double** tB = transponiraj(matricaB, redB, stupacB);
	ispis(tB, redB, stupacB);
	cout << endl;

	dealociraj(matricaA, redA);
	dealociraj(matricaB, redB);
	dealociraj(matricaG, redG);
	dealociraj(tA, redA);
	dealociraj(tB, redB);
	return 0;
}