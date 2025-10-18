#ifndef MATRICA_H
#define MATRICA_H

double** alociraj(int m, int n);

void dealociraj(double** matrica, int m);

double** unos(int &m, int &n);

double** generiraj(int &m, int &n, double a, double b);

double** zbroji(double** A, double** B, int m, int n);

double** oduzmi(double** A, double** B, int m, int n);

double** pomnozi(double** A, double** B, int mA, int nA, int nB);

double** transponiraj(double** matrica, int m, int n);

void ispis(double** matrica, int m, int n);

#endif