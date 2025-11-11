#include <iostream>
#include <vector>

using namespace std;

class Karta {
public:
	int broj;
	string zog;

	Karta(int b, string z) : broj(b), zog(z) {}
};

class Igrac {
private:
	string ime;
	vector<Karta> kombinacija;
	int punti;
public:
	Igrac(string i) : ime(i), punti(0) {}

	void dodajKartu(Karta karta) {
		kombinacija.push_back(karta);
	}
	bool akuza() {
		//Provjera istih karata
		int brojevi[14] = { 0 };
		for (const Karta& karta : kombinacija) {
			brojevi[karta.broj]++;
		}
		if (brojevi[0] == 3 || brojevi[1] == 3 || brojevi[2] == 3) {
			dodajBodove(3);
			return true;
		} 
		else if (brojevi[0] == 4 || brojevi[1] == 4 || brojevi[2] == 4) {
			dodajBodove(4);
			return true;
		}
		else {
			return false;
		}
		//Provjera napolitane
		string zogovi[4] = { "Dinari", "Bastoni", "Kupe", "Spade" };
		for (int z = 0; z < 4; z++) {
			bool jedan = false, dva = false, tri = false;
			for (const Karta& karta : kombinacija) {
				if (karta.zog == zogovi[z]) {
					if (karta.broj == 1) jedan = true;
					if (karta.broj == 2) dva = true;
					if (karta.broj == 3) tri = true;
				}
			}
			if (jedan && dva && tri) {
				dodajBodove(3);
				return true;
			}
		}
		return false;
	}
	void dodajBodove(int b) {
		punti += b;
	}
	int getBodovi() const {
		return punti;
	}
	string getIme() const {
		return ime;
	}
	void ispisiKarte() const {
		cout << ime << " ima karte: " << endl;
		for (const Karta& karta : kombinacija) {
			cout << "\t" << karta.broj << " " << karta.zog << endl;
		}
		cout << endl;
	}
};

class Mac {
private:
	vector<Karta> mac;
public:
	Mac() {
		kreiraj();
	}
	void kreiraj() {
		mac.clear();
		string zogovi[4] = { "Dinari", "Bastoni", "Kupe", "Spade" };
		for (int i = 0; i < 4; i++) {
			for (int broj = 1; broj <= 13; broj++) {
				if (broj != 8 && broj != 9 && broj != 10) {
					mac.push_back(Karta(broj, zogovi[i]));
				}
			}
		}
	}
	void shuffle() {
		for (int i = 0; i < mac.size(); i++) {
			int j = i + (i * 3) % (mac.size() - i);
			if (j < mac.size()) {
				Karta temp = mac[i];
				mac[i] = mac[j];
				mac[j] = temp;
			}
		}
	}
	void podijeli(vector<class Igrac>& igraci) {
		int kartePoIgracu = (igraci.size() == 2) ? 20 : 10;
		for (int i = 0; i < kartePoIgracu; i++) {
			for (int j = 0; j < igraci.size(); j++) {
				if (!mac.empty()) {
					Karta karta = mac[0];
					igraci[j].dodajKartu(karta);
					mac.erase(mac.begin());
				}
			}
		}
	}
};

int main() {
	Mac mac;
	mac.shuffle();

	vector<Igrac> igraci;
	igraci.push_back(Igrac("Ante"));
	igraci.push_back(Igrac("Mate"));
	igraci.push_back(Igrac("Jure"));
	igraci.push_back(Igrac("Sime"));

	mac.podijeli(igraci);

	for (Igrac& igrac : igraci) {
		igrac.ispisiKarte();
		if (igrac.akuza()) {
			cout << igrac.getIme() << " ima akuzu" << endl;
		}
	}

	return 0;
}