#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int find_carrots(vector<vector<int>> garden, int row, int col) {
	int max_carrots = 0;
	int carrots = 0;
	int new_row = 0;
	int new_col = 0;

	for (int i = -1; i < 1; i++) {
		for (int j = -1; j < 1; j++) {
			if (i == -1 && j == 0 || i == 1 && j == 0 || i == 0 && j == -1 || i == 0 && j == 1) {
				if (row + i >= 0 && row + i < garden.size() &&
					col + j >= 0 && col + j < garden[row].size()) {
					if (garden[row + i][col + j] > max_carrots) {
						max_carrots = garden[row + i][col + j];
						new_row = row + i;
						new_col = col + j;
					}
				}
			}
		}
	}

	carrots = garden[row][col];
	garden[row][col] = 0;

	if (max_carrots > 0 && new_row >= 0 && new_row < garden.size() &&
		new_col >= 0 && new_col < garden[row].size()) {
		carrots += find_carrots(garden, new_row, new_col);
	}

	return carrots;
}

tuple<int, int> find_center(vector<vector<int>> garden) {
	int row_options[] = { garden.size() / 2, garden.size() / 2};
	int col_options[] = { garden[0].size() / 2, garden[0].size() / 2 };

	if (garden.size() % 2 == 0) {
		row_options[0]--;
	}

	if (garden[0].size() % 2 == 0) {
		col_options[0]--;
	}

	int max_carrots = 0;
	int max_row = 0;
	int max_col = 0;

	for (auto row_option : row_options) {
		for (auto col_option : col_options) {
			if (garden[row_option][col_option] > max_carrots) {
				max_carrots = garden[row_option][col_option];
				max_row = row_option;
				max_col = col_option;
			}
		}
	}

	return { max_row, max_col };
}

int hungry_rabbit(vector<vector<int>> garden) {
	if (garden.size() == 0 || garden[0].size() == 0) {
		return 0;
	}

	vector<vector<int>> garden_copy = garden;
	auto [row, col] = find_center(garden_copy);

	if (!row || !col) {
		return 0;
	}

	return find_carrots(garden_copy, row, col);
}

int main()
{
	vector<vector<int>> garden{
		{5, 7, 8, 6, 3},
		{0, 0, 7, 0, 4},
		{4, 6, 3, 4, 9},
		{3, 1, 0, 5, 8} };

	cout << "Carrots Eaten: " << hungry_rabbit(garden);

	return 0;
}
