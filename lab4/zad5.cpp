#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverse_strings(vector<string>& words) {
	for (string& s : words) {
		reverse(s.begin(), s.end());
	}
}

int main() {
	vector<string> v = { "ivan", "mate", "jure", "goran", "zoran" };
	reverse_strings(v);
	for (string s : v) {
		cout << s << " ";
	}
	cout << endl;

	return 0;
}