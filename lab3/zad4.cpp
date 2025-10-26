#include <iostream>

using namespace std;

typedef struct {
	string ime;
	string JMBAG;
	int godinaStudija;
	int brojPolozenihECTS;
	float prosjekOcjena;
} Student;

void filter_students(Student studenti[], size_t velicina, void (*akcija)(Student&), bool (*filter)(Student&)) {
	for (size_t i = 0; i < velicina; i++) {
		if (filter(studenti[i])) {
			akcija(studenti[i]);
		}
	}
}
void ispisStudenta(Student& student) {
	cout << "Ime: " << student.ime << endl
		<< "JMBAG: " << student.JMBAG << endl
		<< "Godina studija: " << student.godinaStudija << endl
		<< "Broj polozenih ECTS bodova: " << student.brojPolozenihECTS << endl
		<< "Prosjek ocjena: " << student.prosjekOcjena << endl << endl;
}
void povecajGodinu(Student& student) {
	student.godinaStudija++;
	cout << "Studentu " << student.ime << " povecana godina studija na: " << student.godinaStudija << endl << endl;
}

int main() {
	const size_t nStudenata = 5;
	Student studenti[nStudenata] = {
		{"Ante Antic", "00123456789", 1, 0, 0.0},
		{"Bartul Kalinic", "00987654321", 1, 30, 3.8},
		{"Marko Markic", "00555123456", 2, 60, 4.2},
		{"Petra Petric", "00333214567", 1, 15, 3.1},
		{"Lara Laric", "00777889900", 3, 45, 3.9}
	};

	auto prvaGodinaJedanIspit = [](Student& s) -> bool {
		return s.godinaStudija == 1 && s.brojPolozenihECTS > 0;
	};
	filter_students(studenti, nStudenata, ispisStudenta, prvaGodinaJedanIspit);

	auto prosjekVeciOd = [](Student& s) -> bool {
		return s.prosjekOcjena > 3.5;
	};
	filter_students(studenti, nStudenata, ispisStudenta, prosjekVeciOd);

	auto barem45ECTS = [](Student& s) -> bool {
		return s.brojPolozenihECTS >= 45;
	};
	filter_students(studenti, nStudenata, povecajGodinu, barem45ECTS);

	for (auto& student : studenti) {
		ispisStudenta(student);
	}

	return 0;
}