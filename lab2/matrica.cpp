#include <iostream>
#include <iomanip>
#include "matrica.h"

using namespace std;

double** alociraj(int m, int n) {
	double** matrica = new double* [m];
	for (int i = 0; i < m; i++) {
		matrica[i] = new double[n];
	}
	return matrica;
}

void dealociraj(double** matrica, int m) {
	for (int i = 0; i < m; i++) {
		delete[] matrica[i];
	}
	delete[] matrica;
}

double** unos(int &m, int &n) {
	cout << "Unesi broj redaka: ";
	cin >> m;
	cout << "Unesi broj stupaca: ";
	cin >> n;

	double** matrica = alociraj(m, n);

	cout << "Unesi elemente matrice:" << endl;
	for (int i = 0; i < m; i++) {
		cout << "Red " << i + 1 << ":" << endl;
		for (int j = 0; j < n; j++) {
			cin >> matrica[i][j];
		}
	}
	return matrica;
}

double** generiraj(int& m, int& n, double a, double b) {
	cout << "Unesi broj redaka: ";
	cin >> m;
	cout << "Unesi broj stupaca: ";
	cin >> n;

	double** matrix = alociraj(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
		}
	}
	return matrix;
}

double** zbroji(double** A, double** B, int m, int n) {
	double** matrica = alociraj(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrica[i][j] = A[i][j] + B[i][j];
		}
	}
	return matrica;
}

double** oduzmi(double** A, double** B, int m, int n) {
	double** matrica = alociraj(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrica[i][j] = A[i][j] - B[i][j];
		}
	}
	return matrica;
}

double** pomnozi(double** A, double** B, int mA, int nA, int nB) {
	double** matrica = alociraj(mA, nB);

	for (int i = 0; i < mA; i++) {
		for (int j = 0; j < nB; j++) {
			matrica[i][j] = 0.0;
		}
	}

	for (int i = 0; i < mA; i++) {
		for (int j = 0; j < nB; j++) {
			for (int k = 0; k < nA; k++) {
				matrica[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return matrica;
}

double** transponiraj(double** matrica, int m, int n) {
	double** matricaT = alociraj(n, m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matricaT[j][i] = matrica[i][j];
		}
	}
	return matricaT;
}

void ispis(double** matrica, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(10) << fixed << setprecision(4) << matrica[i][j];
		}
		cout << endl;
	}
}
