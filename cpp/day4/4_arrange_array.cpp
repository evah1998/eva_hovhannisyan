#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << ", ";
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9-i; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp; 
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}

