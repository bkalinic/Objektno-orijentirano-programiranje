#include <iostream>

using namespace std;

int check(int n, int low=15, int high=26) {
	if (n < low) {
		return low;
	}
	if (n > high) {
		return high;
	}
	return n;
}
double check(double n, double low=10.16, double high=20.48) {
	if (n < low) {
		return low;
	}
	if (n > high) {
		return high;
	}
	return n;
}

int main() {
	cout << check(20) << endl;
	cout << check(14.05) << endl;
	cout << check(10) << endl;
	cout << check(5.45) << endl;
	cout << check(56) << endl;
	cout << check(23.23) << endl;

	return 0;
}