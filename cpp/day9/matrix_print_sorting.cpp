#include <iostream>
#include "../lib/matrix.h"
using namespace std;

int main() {
	srand(time(0));
	int row, col;
	cout << "Input row & column size\n";
	cin >> row >> col;
	int **arr = new int*[row];
	for (int **ptr = arr; ptr - arr < row; ptr++) {
		*ptr = new int[col];
		for (int *tmp = *ptr; tmp - *ptr < col; tmp++) {
			*tmp = rand() % 10;
		}
	}
	printMatrix(arr, row, col);

	return 0;
}
                  
