#include <iostream>
using namespace std;

int main() {
	const int m = 5, n = 4;
	int indexMin = 0, indexMax = 0;
	srand(time(0));
	int arr[m][n] = {};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int Min, Max;
	for (int i = 0; i < m; i++) {
		Max = arr[i][0], Min = arr[i][0];
		for (int j = 0; j < n; j++) {     
			if (arr[i][j] >= Max) {
				Max = arr[i][j];
				indexMax = j;
			}
			if (arr[i][j] <= Min) {
				Min = arr[i][j];
				indexMin = j;
			}
		}
		arr[i][indexMax] = Min;
		arr[i][indexMin] = Max;
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
