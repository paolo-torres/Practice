#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

// find center or closest to the center with highest carrots
tuple<int, int> find_center(vector<vector<int>> garden) {
	// store halfway points and (potentially) one spot before
	int rows[] = { garden.size() / 2, garden.size() / 2 };
	int cols[] = { garden[0].size() / 2, garden[0].size() / 2 };

	// if number of rows is even, store one spot before
	if (garden.size() % 2 == 0) {
		rows[0]--;
	}

	// if number of columns is even, store one spot before
	if (garden[0].size() % 2 == 0) {
		cols[0]--;
	}

	int max_carrots = 0;
	int max_row = 0;
	int max_col = 0;

	// get center or iterate through surrounding spots for highest carrots
	for (auto row : rows) {
		for (auto col : cols) {
			if (garden[row][col] > max_carrots) {
				max_carrots = garden[row][col];
				max_row = row;
				max_col = col;
			}
		}
	}

	// return center or location of highest carrots
	return { max_row, max_col };
}

// helper function to find maximum value
void find_max(multimap<int, int> &m, vector<vector<int>> &garden,
	int &row, int &col, int &max_carrots, int &new_row, int &new_col) {
	// stay within bounds and determine maximum carrots for next move
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
}

// find path to maximize carrots
int find_path(vector<vector<int>> garden, int row, int col) {
	int cur_carrots = 0;
	int max_carrots = 0;
	int new_row = 0;
	int new_col = 0;

	// store up, right, down, and left moves in multimap
	multimap<int, int> m = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	// find maximum carrots for next move
	find_max(m, garden, row, col, max_carrots, new_row, new_col);

	// eat carrots on current position
	cur_carrots = garden[row][col];

	// remove carrots on current position
	garden[row][col] = 0;

	// avoid 0's, ensure within garden, use recursion for subsequent moves
	if (max_carrots > 0 && new_row >= 0 && new_row < garden.size() &&
		new_col >= 0 && new_col < garden[row].size()) {
		cur_carrots += find_path(garden, new_row, new_col);
	}

	// return total number of carrots
	return cur_carrots;
}

// find number of carrots rabbit eats
int find_carrots(vector<vector<int>> garden) {
	// even though nonempty assumption made, easy and cheap to still check
	if (garden.size() == 0 || garden[0].size() == 0) {
		return 0;
	}

	// determine starting coordinates with a tuple
	auto [row, col] = find_center(garden);

	// return final count of carrots
	return find_path(garden, row, col);
}

int main()
{
	// vector preferred over array to use size function
	vector<vector<int>> garden{
		{5, 7, 8, 6, 3},
		{0, 0, 7, 0, 4},
		{4, 6, 3, 4, 9},
		{3, 1, 0, 5, 8} };

	// expected: 7 + 8 + 7 + 5 = 27
	// actual: Carrots Eaten: 27
	cout << "Carrots Eaten: " << find_carrots(garden) << '\n';

	return 0;
}
