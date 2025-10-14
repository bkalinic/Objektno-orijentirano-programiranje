#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (auto& x : s) {
		x = toupper(x);
		if (isdigit(x)) {
			x = '*';
		}
		if (isspace(x) || x == '\t') {
			x = '_';
		}
	}
	cout << s << endl;

	return 0;
}