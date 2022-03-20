#include <iostream>
using namespace std;

int lengthNumber(int number);
void swapIndex(int, int, int*, int);
void printNewNumber(int, int*); 

int main() {
	int number;
	cout << "Input number: ";
	cin >> number;

	int index1, index2;
	cout << "Input positions to swap: ";
	cin >> index1 >> index2;
	
	int size = lengthNumber(number);
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[size - i - 1] = number % 10;
		number = number / 10;
	}

	int *ptr = arr;
	swapIndex(index1, index2, ptr, size);
	printNewNumber(size, ptr);

	return 0;
}	

int lengthNumber(int number) { 
	int counter = 0;
	while (number) {
		number = number / 10;
		counter++;
	}
	return (counter);
}

void swapIndex(int index1, int index2, int *arr, int size) {
	int tmp = 0;
	tmp = arr[index2 - 1];
	arr[index2 - 1] = arr[index1 - 1];
	arr[index1 - 1] = tmp;
}

void printNewNumber(int size, int *ptr) {
	for (int i = 0; i < size; i++) {
		cout << ptr[i];
	}
}
