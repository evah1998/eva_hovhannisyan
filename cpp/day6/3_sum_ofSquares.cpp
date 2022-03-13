#include <iostream>
#include <math.h>
using namespace std;

int main() {
	const int size = 10;
	int arr[size];
	
	for (int i = 1, k = 0; k < size; i++) {
		for (int j = 1; j < size - 1; j++) {
			int sumOfSquare = pow(i, 2) + pow(j, 2);
			if (sumOfSquare % 5 == 0) {
				arr[k] = pow(i, 2) + pow(j, 2);
				cout << pow(i, 2) << " + " << pow(j, 2) << " = " << arr[k] << endl;
				k++;

			}
			
		}
	
	}
	cout << "arr[] = {";
	for (int i = 0; i < size - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[9] << "}\n";
	return 0;
}
