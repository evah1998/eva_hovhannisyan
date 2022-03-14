#include <iostream>
using namespace std;

void SumofArrayElements(int *ptr, int size, int *arr, int *sum) {
//	int sum = 0;
	srand(time(0));
	while (ptr - arr < size) {
                *ptr = rand() % 10;
                *sum += *ptr;
                cout << *ptr << ", ";
                ptr++;
        }
	cout << endl;
}
int main() {
	int n;
	cout << "size of array: ";
	cin >> n;

	int *arr = new int[n];
	int *ptr = arr;
	int sum = 0;

	SumofArrayElements(ptr, n, arr, &sum); 
	cout << "Sum = " << sum << endl;

	return 0;
}

