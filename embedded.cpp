#include <bitset>
#include <iostream>
#include <string>

using namespace std;

// Count Bits Set in a Byte
int bitsSet(int byte) {
	int table[] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

	return table[byte & 0x0F] + table[byte >> 4];
}

// Get i'th Element of 2 Arrays
int getElement(int arr1[], int arr2[], int i) {
	int* ptr1 = arr1;
	int* ptr2 = arr2;
	int index1 = 0;
	int index2 = 0;
	int count = 0;

	while (ptr1 != NULL && ptr2 != NULL) {
		count++;
		if (arr1[index1] < arr2[index2]) {
			ptr1++;
			if (count == i) {
				return arr1[index1];
			}
			else {
				index1++;
			}
		}
		else {
			ptr2++;
			if (count == i) {
				return arr2[index2];
			}
			else {
				index2++;
			}
		}
	}
}

// Check Bitwise Palindrome
bool isPalindrome(unsigned char num) {
	return (num & 0xF0 >> 4) == (num & 0x0F);
}

// Reverse Bits
int reverseBits(int num) {
	return ~num;
}

// Reverse String
string reverseString(string& str) {
	int n = str.size();
	char temp = 'a';

	for (int i = 0; i < n / 2; i++) {
		temp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = temp;
	}

	return str;
}

// Check MSB
bool checkMSB(unsigned char num) {
	return (num >> 7) == 1;
}

int main()
{
	cout << "Bits Set: " << bitsSet(170) << "\n\n";

	int arr1[] = { 1, 3, 5, 7, 9 };
	int arr2[] = { 2, 4, 6, 8, 10 };

	cout << "Element: " << getElement(arr1, arr2, 5) << "\n\n";

	cout << "Is Palindrome: " << isPalindrome(153) << "\n\n";

	cout << "Before Reverse: " << bitset<8>(5) << "\n After Reverse: " << bitset<8>(reverseBits(5)) << "\n\n";

	string str = "Hello World";

	cout << "Before Reverse: " << str << "\n After Reverse: " << reverseString(str) << "\n\n";

	cout << "MSB of 10010110: " << checkMSB(150) << "\n";
	cout << "MSB of 01101001: " << checkMSB(105) << "\n\n";

	return 0;
}
