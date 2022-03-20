#include <iostream>
using namespace std;

int main() {
	srand(time(0));
	int size;
	cout << "Input size: ";
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 - 50;
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;

	int tmp = 1, counter = 1;
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < arr[i + 1]) {
			tmp++;
		} else if (counter < tmp) {
			counter = tmp;		
			tmp = 1;
			index = i;
		} else {
			tmp = 1;
		} 
		if (arr[0] == '\0' && counter < tmp) {
			counter = tmp;
			tmp = 1;
			index = i;
		}
	}
	cout << " index = " << index << endl;
	cout << "counter = " << counter << endl;
	for (int i = index - counter + 1; i <= index; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;

	return 0;
}
