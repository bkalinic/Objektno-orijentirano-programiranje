#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string word_to_pig_latin(const string& word) {
	char prvoSlovo = tolower(word[0]);
	if (prvoSlovo == 'a' || prvoSlovo == 'e' || prvoSlovo == 'i' || prvoSlovo == 'o' || prvoSlovo == 'u') {
		return word + "hay";
	} 
	else {
		return word.substr(1) + word[0] + "ay";
	}
}

int main() {
	string word = "rijec"; //ijecray
	cout << word_to_pig_latin(word);

	return 0;
}