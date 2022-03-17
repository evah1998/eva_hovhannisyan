#include <iostream>
#include "matrix.h"
using namespace std;

void printMatrix(int **arr, int row, int col) {
	for (int **ptr = arr; ptr - arr < row; ptr++) {
		for (int *tmp = *ptr; tmp - *ptr < col; tmp++) {
			cout << *tmp << " ";
		}
		cout << endl;
	}
}

                  
