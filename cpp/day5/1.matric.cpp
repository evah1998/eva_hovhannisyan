#include <iostream>
using namespace std;

int main() {	
	srand(time(0));
	const int size = 6;
	int arr[size][size] = {};	
	int topSmall = 0, rightSmall = 0, leftSmall =0, botomSmall = 0, topRightBig = 0, botomLeftBig = 0, topLeftBig = 0, botomRightBig = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i < j) {
				topRightBig += arr[i][j]; 
				if (i + j < size - 1) {
					topSmall += arr[i][j];
				} else if (i + j > size - 1) {
					rightSmall += arr[i][j];
				} 
			} else if (i > j) {
				botomLeftBig += arr[i][j];
				if (i + j < size - 1) {
					leftSmall += arr[i][j];
				} else if (i + j > size - 1) {
					botomSmall += arr[i][j];
				}
			}
			if (i + j < size -1) {
				topLeftBig += arr[i][j];
			} else if (i + j > size -1) {
				botomRightBig += arr[i][j];
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;		 
	cout << "topSmall = " << topSmall << endl;
	cout << "rightSmall = " << rightSmall << endl;
	cout << "leftSmall = " << leftSmall << endl;
	cout << "botomSmall = " << botomSmall << endl;
	cout << "topRightBig = " << topRightBig << endl;
	cout << "botomLeftBig = " << botomLeftBig << endl;
	cout << "topLeftBig = " << topLeftBig << endl;
	cout << "botomRightBig = " << botomRightBig << endl;
	
	return 0;
}
