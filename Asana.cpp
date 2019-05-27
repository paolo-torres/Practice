#include <iostream>

#define R 3
#define C 6
// #define R 4
// #define C 4

using namespace std;

void spiralPrint(int end_row, int end_col, int arr[R][C])
{
	int start_row = 0;
	int start_col = 0;

	int curr_row = 0;
	int curr_col = 0;

	while (start_row < end_row && start_col < end_col) {
		for (; curr_col < end_col; curr_col++) {
			cout << arr[curr_row][curr_col] << " ";
		}
		curr_col--;
		start_row++;
		curr_row++;

		for (; curr_row < end_row; curr_row++) {
			cout << arr[curr_row][curr_col] << " ";
		}
		curr_row--;
		end_col--;
		curr_col--;

		if (start_row < end_row && start_col < end_col) {
			for (; curr_col >= start_col; curr_col--) {
				cout << arr[curr_row][curr_col] << " ";
			}
			curr_col++;
			end_row--;
			curr_row--;

			for (; curr_row >= start_row; curr_row--) {
				cout << arr[curr_row][curr_col] << " ";
			}
			curr_row++;
			start_col++;
			curr_col++;
		}
	}
}

/* Driver program to test above functions */
int main()
{
	int a[3][6] = { {1, 2, 3, 4, 5, 6},
		{7, 8, 9, 10, 11, 12},
		{13, 14, 15, 16, 17, 18}
	};

	int b[4][4] = { {1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	spiralPrint(R, C, a);
	// spiralPrint(4, 4, b);

	return 0;
}
