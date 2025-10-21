#include <iostream>
#include <cstddef>

using namespace std;

inline bool ascending(int a, int b) {
	return a < b;
}
inline bool descending(int a, int b) {
	return a > b;
}
void sortt(int niz[], size_t n, bool (*cmp)(int, int)) {
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = 0; j < n - i - 1; j++) {
			if (cmp(niz[j+1], niz[j])) {
				int temp = niz[j];
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

	return 0;
}