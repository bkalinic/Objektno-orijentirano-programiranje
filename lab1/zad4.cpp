#include <iostream>
#include <string>

using namespace std;

char& at(string& str, int i) {
	return str[i];
}

int main() {
	string str("1950torcasplit");
	int i;
	cout << "Unesi indeks koji trazis: " << endl;
	cin >> i;
	at(str, i) += 1;
	cout << str << endl;

	return 0;
}