#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> niz = { 3, 6, 4, 8, 1 };

	auto parni = [](int n) -> bool { return n % 2 == 0; };
	auto neparni = [](int n) -> bool { return n % 2 != 0; };
	auto poduplaj = [](int n) -> int { return n * 2; };
	auto prepolovi = [](int n) -> int { return n / 2; };

	int suma = 0;
	auto dodajUSumu = [&](int n) { return suma += n; };
	int produkt = 1;
	auto dodajUProdukt = [&](int n) { return produkt *= n; };

	int s = 0;
	int prag = 5;
	auto dodajAkoJeVeci = [prag, &s](int n) {
		if (n > prag) { s += n; }
	};

	auto transformiraj = [&]() {
		vector<int> rezultat = niz;
		for (int& num : rezultat) {
			if (parni(num)) {
				num = prepolovi(num);
			}
			else {
				num = poduplaj(num);
			}
		}
		return rezultat;
	};
	auto sumaIProdukt = [&](vector<int>& niz, int& suma, int& produkt) {
		suma = 0;
		produkt = 1;

		for (int num : niz) {
			suma += num;
			produkt *= num;
		}
	};
	auto zbrojiVeceOd = [&](int prag) -> int {
		s = 0;
		prag = prag;

		for (int num : niz) {
			dodajAkoJeVeci(num);
		}
		return s;
	};

	cout << "\nOriginalni niz: ";
	for (int num : niz) {
		cout << num << " ";
	}
	cout << endl;

	vector<int> transformirani = transformiraj();
	cout << "Transformirani niz (parni prepolovljeni, neparni udvostruceni): ";
	for (int num : transformirani) {
		cout << num << " ";
	}
	cout << endl;

	sumaIProdukt(niz, suma, produkt);
	cout << "Suma svih brojeva: " << suma << endl;
	cout << "Produkt svih brojeva: " << produkt << endl;

	int sPrag = 5;
	int sumaPragRez = zbrojiVeceOd(sPrag);
	cout << "Suma brojeva vecih od " << sPrag << ": " << sumaPragRez << endl;

	return 0;
}