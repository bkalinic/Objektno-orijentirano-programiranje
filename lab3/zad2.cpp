#include <iostream>
#include <cstddef>

using namespace std;

template<typename T>
inline bool ascending(T a, T b) {
	return a < b;
}
template<typename T>
inline bool descending(T a, T b) {
	return a > b;
}
template<typename T>
void sortt(T niz[], size_t n, bool (*cmp)(T, T)) {
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = 0; j < n - i - 1; j++) {
			if (cmp(niz[j + 1], niz[j])) {
				T temp = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
}

int main() {
	int niz[] = { 3, 6, 4, 8, 1 };
	size_t n = sizeof(niz) / sizeof(niz[0]);
	sortt(niz, n, ascending);
	sortt(niz, n, descending);

	double niz2[] = { 3.5, 6.2, 4.1, 8.8, 1.7 };
	size_t n2 = sizeof(niz2) / sizeof(niz2[0]);
	sortt(niz2, n2, ascending);
	sortt(niz2, n2, descending);

	return 0;
}