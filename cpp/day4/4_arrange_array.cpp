#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	int size;
	cout << "Input size of array: ";
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 100) - 50;
		cout << arr[i] << ", ";
	}
	cout << endl << endl;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp; 
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}

