#include <iostream>
using namespace std;

void Array(int);
void printArray(int,int);
int main() {
	int n;
	cout << "Size of array: ";
	cin >> n;
	const int size = n;
	
	int arr[size];
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		arr[i] = (rand() % 100) - 50;
		cout << arr[i] << ", ";
	}
	cout << endl << endl;
	for (int i = n; i > 0; i--)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}

