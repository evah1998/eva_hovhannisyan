#include <iostream>
using namespace std;

int main() {
	const int size = 10;
	int arr[size][size] = {};
	int startColumn = 0, endColumn = size - 1;
	int startRow = 0, endRow = size - 1;
	int count = 1;
	while (startColumn <= endColumn && startRow <= endRow) {
		for (int i = startColumn; i < endColumn; i++) {
			arr[startRow][i] = count;
			count++;
		}	

		for (int i = startRow; i <= endRow; i++) {
			arr[i][endColumn] = count;
			count++;
		}
		startRow++;

		for (int i = endColumn - 1; i >= startColumn; i--) {
			arr[endRow][i] = count;
			count++;
		}
		endColumn--;

		for (int i = endRow - 1; i >= startRow; i--) {
			arr[i][startColumn] = count;
			count++;
		}
		endRow--;

		startColumn++;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] < 10) {
				cout << "  ";
			} else if (arr[i][j] < 100) {
				cout << " ";
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
