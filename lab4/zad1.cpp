#include <iostream>
#include <vector>

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
}

int main() {
	vector<int> v;
	input_vector(v);
	print_vector(v);

	return 0;
}