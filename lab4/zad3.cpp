#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void fix_spaces(string& text) {
	auto i = unique(text.begin(), text.end(), [](char a, char b) {
		return a == ' ' && b == ' ';
	});
	text.erase(i, text.end());

	size_t pos = 0;
	while ((pos = text.find(" ,", pos)) != string::npos) {
		text.erase(pos, 1);
	}
	pos = 0;
	while ((pos = text.find(" .", pos)) != string::npos) {
		text.erase(pos, 1);
	}
	pos = 0;
	while (pos < text.length()) {
		size_t zarez_pos = text.find(',', pos);
		size_t tocka_pos = text.find('.', pos);

		size_t prviOd = min(zarez_pos, tocka_pos);
		if (prviOd == string::npos) {
			break;
		}
		if (prviOd + 1 < text.length() && text[prviOd + 1] != ' ') {
			text.insert(prviOd + 1, " ");
		}
		pos = prviOd + 2;
	}
	if (!text.empty() && text[0] == ' ') {
		text.erase(0, 1);
	}
	if (!text.empty() && text[text.length() - 1] == ' ') {
		text.erase(text.length() - 1, 1);
	}
}

int main() {
	string text("Puno  razmaka  ,i tocka .");
	fix_spaces(text);
	cout << text;

	return 0;
}