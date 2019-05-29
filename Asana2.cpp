#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

int find_path(vector<vector<int>> garden, int row, int col) {
	int cur_carrots = 0;
	int max_carrots = 0;
	int new_row = 0;
	int new_col = 0;

	multimap<int, int> m = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	for (auto it = m.begin(); it != m.end(); it++) {
		if (row + it->first >= 0 && row + it->first < garden.size() &&
			col + it->second >= 0 && col + it->second < garden[row].size()) {
			if (garden[row + it->first][col + it->second] > max_carrots) {
				max_carrots = garden[row + it->first][col + it->second];
				new_row = row + it->first;
				new_col = col + it->second;
			}
		}
	}

	cur_carrots = garden[row][col];

	garden[row][col] = 0;

	if (max_carrots > 0 && new_row >= 0 && new_row < garden.size() &&
		new_col >= 0 && new_col < garden[row].size()) {
		cur_carrots += find_path(garden, new_row, new_col);
	}

	return cur_carrots;
}

tuple<int, int> find_center(vector<vector<int>> garden) {
	int rows[] = { garden.size() / 2, garden.size() / 2 };
	int cols[] = { garden[0].size() / 2, garden[0].size() / 2 };

	if (garden.size() % 2 == 0) {
		rows[0]--;
	}

	if (garden[0].size() % 2 == 0) {
		cols[0]--;
	}

	int max_carrots = 0;
	int max_row = 0;
	int max_col = 0;

	for (auto row : rows) {
		for (auto col : cols) {
			if (garden[row][col] > max_carrots) {
				max_carrots = garden[row][col];
				max_row = row;
				max_col = col;
			}
		}
	}

	return { max_row, max_col };
}

int find_carrots(vector<vector<int>> garden) {
	if (garden.size() == 0 || garden[0].size() == 0) {
		return 0;
	}

	auto [row, col] = find_center(garden);

	if (!row || !col) {
		return 0;
	}

	return find_path(garden, row, col);
}

int main()
{
	vector<vector<int>> garden{
		{5, 7, 8, 6, 3},
		{0, 0, 7, 0, 4},
		{4, 6, 3, 4, 9},
		{3, 1, 0, 5, 8} };

	cout << "Carrots Eaten: " << find_carrots(garden) << '\n';

	return 0;
}
