#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	cout << "Map (Sorted)\n\n";

	map<unsigned int, string> m = {
		{3, "Charlie"},
		{2, "Beta"},
		{1, "Alpha"} };

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << "Key: " << it->first << ", Value: " << it->second << "\n";
	}
	cout << "\n";

	m.insert({5, "Echo"});
	m.insert({4, "Delta"});

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << "Key: " << it->first << ", Value: " << it->second << "\n";
	}
	cout << "\n";

	string arr_1[3] = { "Foxtrot", "Golf", "Hotel" };
	for (unsigned int i = 0; i < 3; i++) {
		m.insert({ i + 6, arr_1[i] });
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << "Key: " << it->first << ", Value: " << it->second << "\n";
	}
	cout << "\n";

	cout << "Unordered Map (Unsorted)\n\n";

	unordered_map<unsigned int, char> um = {
		{3, 'c'},
		{2, 'b'},
		{1, 'a'} };

	for (auto it = um.begin(); it != um.end(); it++) {
		cout << "Key: " << it->first << ", Value: " << it->second << "\n";
	}
	cout << "\n";

	um.insert({ 5, 'e' });
	um.insert({ 4, 'd' });

	for (auto it = um.begin(); it != um.end(); it++) {
		cout << "Key: " << it->first << ", Value: " << it->second << "\n";
	}
	cout << "\n";

	char arr_2[3] = { 'f', 'g', 'h' };
	for (unsigned int i = 0; i < 3; i++) {
		um.insert({ i + 6, arr_2[i] });
	}

	for (auto it = um.begin(); it != um.end(); it++) {
		cout << "Key: " << it->first << ", Value: " << it->second << "\n";
	}

	return 0;
}
