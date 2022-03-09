#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int size;
	cout << "Input size of array: ";
	cin >> size;

	double arr[size];
	double Max = 0;
	srand(time(NULL));
	for(int i=0; i < size; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << ", ";
		Max = max(Max,arr[i]);
	}
	cout << endl;
	cout << "Max = " << Max << endl;
	return 0;
}
