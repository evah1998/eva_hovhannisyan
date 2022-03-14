#include <iostream>
using namespace std;

void swap(int*, int*);
int main() {
	int a = 5, b = 1;
	swap(&a, &b);
	cout << "a = " << a << "  " << "b = " << b << endl;
	return 0;
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
