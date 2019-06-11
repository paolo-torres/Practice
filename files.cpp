#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

void readWords() {
	ifstream file;
	file.open("Text1.txt");
	string word;

	unordered_map<string, unsigned int> um;
	vector<string> v;

	while (file >> word) {
		auto it = um.find(word);
		if (it != um.end()) {
			it->second++;
		}
		else {
			um.insert({ word, 1 });
			v.push_back(word);
		}
	}

	for (unsigned int i = 0; i < v.size(); i++) {
		auto it = um.find(v[i]);
		cout << "Key: " << v[i] << " Value: " << it->second << "\n";
	}
	cout << "\n";
}

void readLines() {
	ifstream file;
	file.open("Text2.txt");

	const size_t size = 5;

	string line;
	string buffer[size];

	size_t i = 0;
	while (getline(file, line)) {
		buffer[i] = line;
		if (i >= size - 1) {
			i = 0;
		}
		else {
			i++;
		}
	}

	for (size_t j = 0; j < size; j++) {
		cout << buffer[i] << "\n";
		if (i >= size - 1) {
			i = 0;
		}
		else {
			i++;
		}
	}
}

int main()
{
	readWords();
	readLines();

	return 0;
}
