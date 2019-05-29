#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

void fizzBuzz() {
	for (int i = 1; i <= 100; i++) {
		if (i % 15 == 0)
			cout << "FizzBuzz" << endl;
		else if (i % 3 == 0)
			cout << "Fizz" << endl;
		else if (i % 5 == 0)
			cout << "Buzz " << endl;
		else
			cout << i << endl;
	}	
}

int fibo(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

void reverseStr(string &str) {
	int n = str.length();
	char temp;
	for (int i = 0; i < n/2; i++) {
		temp = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = temp;
	}
	cout << str << endl;
}

int numOfWords(string &str) {
	int n = str.length();
	int count = 0;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (flag == 0 && i == n - 1)
			count++;
		else if (flag == 1 && i == n - 1)
			count++;
		else if (str[i] == ' ')
			flag = 1;
		else if (flag == 1) {
			flag = 0;
			count++;
		}
	}
	cout << count << endl;
	return count;
}

int findWinner(char board[]) {
	int win[8][3] = {{0, 1, 2},
					 {3, 4, 5},
					 {6, 7, 8},
					 {0, 3, 6},
					 {1, 4, 7},
					 {2, 5, 8},
					 {0, 4, 8},
					 {2, 4, 6}};
	for (int i = 0; i < 8; i++) {
		if (board[win[i][0]] == 'X' &&
			board[win[i][1]] == 'X' &&
			board[win[i][2]] == 'X')
			return 1;
		else if (board[win[i][0]] == 'O' &&
				 board[win[i][1]] == 'O' &&
				 board[win[i][2]] == 'O')
			return 2;
	}
	return 3;
}

void change(int arr[]) {
	int rows = 6;
	int cols = 3;
	int index = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[index] << " ";
			index++;
		}
		cout << endl;
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition (int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

bool addUp(int arr[], int num) {
	int i = 0;
	int j = 13;
	while (i < j) {
		if (arr[i] + arr[j] == num) {
			cout << arr[i] << " + " << arr[j] << " = " << num << endl;
			return 1;
		}
		else if (arr[i] + arr[j] < num)
			i++;
		else
			j--;
	}
	return 0;
}

bool followsRule(string &str) {
	int n = str.length();
	for (int i = 0; i < n; i++) {
		if (str[i] == 'c' && str[i+1] == 'i' && str[i+2] == 'e')
			return 0;
		else if (str[i] != 'c' && str[i+1] == 'e' && str[i+2] == 'i')
			return 0;
	}
	return 1;
}

bool arePalindromes(string &str1, string &str2) {
	if (str1.length() != str2.length())
		return 0;
	int n = str1.length();
	int j = 0;
	for (int i = n - 1; i > 0; i--) {
		if (str1[i] != str2[j])
			return 0;
		j++;
	}
	return 1;
}

void printUnique(string &str) {
	int count[256] = {0};
	int n = str.length();
	for (int i = 0; i < n; i++) {
		count[str[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cout << i << ": " << count[str[i]] << endl;
	}
}

int main()
{
	fizzBuzz();
	cout << "______________________________________________" << endl << endl;
	cout << fibo(8) << endl;
	cout << "______________________________________________" << endl << endl;
	string str1 = "Paolo";
	reverseStr(str1);
	cout << "______________________________________________" << endl << endl;
	string str2 = "One two         three    four five  ";
	numOfWords(str2);
	cout << "______________________________________________" << endl << endl;
	char board[] = {'X', 'X', 'O',
					'O', 'O', 'X',
					'X', 'O', 'X'};
	if (findWinner(board) == 1)
		cout << "X won"<< endl;
	else if (findWinner(board) == 2)
		cout << "O won" << endl;
	else
		cout << "Neither won" << endl;
	cout << "______________________________________________" << endl << endl;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
	change(arr);
	cout << "______________________________________________" << endl << endl;
	int sort[] = {26, 14, 74, 25, 46, 34, 7, 86, 12, 43, 55, 1, 23, 77};
	quickSort(sort, 0, 13);
	for (int i = 0; i < 13; i++) {
		cout << sort[i] << endl;
	}
	if (addUp(sort, 88))
		cout << "Numbers found" << endl;
	else
		cout << "None" << endl;
	cout << "______________________________________________" << endl << endl;
	string word1 = "priest";
	string word2 = "thief";
	string word3 = "receive";
	if (followsRule(word1))
		cout << "Word 1 passed" << endl;
	if (followsRule(word2))
		cout << "Word 2 passed" << endl;
	if (followsRule(word3))
		cout << "Word 3 passed" << endl;
	cout << "______________________________________________" << endl << endl;
	string palindrome1 = "paolo";
	string palindrome2 = "oloap";
	if (arePalindromes(palindrome1, palindrome2))
		cout << "Palindromes" << endl;
	else
		cout << "Not palindromes" << endl;
	cout << "______________________________________________" << endl << endl;
	string unique = "Microprocessors and Digital Logic";
	printUnique(unique);
	cout << "______________________________________________" << endl << endl;

	return 0;
}

