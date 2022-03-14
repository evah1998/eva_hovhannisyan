#include <iostream>
using namespace std;

void reverseArray(int*, int*);
int main() {
	int size;
	cout << "Input size of array: ";
	cin >> size;
	int *arr = new int[size];
	int *ptr = arr;
	srand(time(0));
	cout << "	Array: ";
	while (ptr - arr < size) {
		*ptr = rand() % 10;
		cout << *ptr << ", ";
		ptr++;
	}
	cout << endl;
	reverseArray(ptr, arr);
	return 0;
}
void reverseArray(int *ptr, int *arr) {
	cout << "Reverse Array: ";
	while (ptr - arr > 0) {
		ptr--;
		cout << *ptr << ", ";
	}
	cout << endl;
}
