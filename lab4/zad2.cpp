#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input_vector(vector<int>& v) {
	int i = 1;
	while (i != 0) {
		cin >> i;
		v.push_back(i);
	}
	v.pop_back();
	cout << endl;
}
void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v;
	input_vector(v);
	print_vector(v);

	vector<int> unique;
	for (int i : v) {
		if (find(unique.begin(), unique.end(), i) == unique.end()) {
			unique.push_back(i);
		}
	}
	print_vector(unique);


	sort(unique.begin(), unique.end(), [](int a, int b) {return abs(a)<abs(b);});
	print_vector(unique);	

	return 0;
}