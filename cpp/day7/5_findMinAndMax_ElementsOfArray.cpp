#include <iostream>
using namespace std;

void MinAndMaxElements(int*, int, int*, int*); 
int main() {
	int size;
	cout << "Size of array: ";
	cin >> size;

	int *arr = new int[size];
	int *ptr = arr;
	srand(time(0));
	while (ptr - arr < size) {
		*ptr = rand() % 10;
		cout << *ptr << ", ";
		ptr++;
	}
	cout << endl;

	int min = arr[0], max = arr[0];
	MinAndMaxElements(arr, size, &min, &max);
	cout << "min = " << min << endl;
	cout << "max = " << max << endl;
	return 0;
}

void MinAndMaxElements(int *arr, int size, int *min, int *max) {
	int *ptr = arr;
	while (ptr - arr < size) {
		if (*ptr < *min) {
			*min = *ptr;
		} else if (*ptr > *max) {
			*max = *ptr;
		}
		ptr++;
	}
}


