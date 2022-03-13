#include <iostream>
using namespace std;

int main() {
	srand(time(0));
	const int m = 3, n = 3, randNum = 3;
	int arr[m][n] = {};
	int count = 0;	
	for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                        arr[i][j] = rand() % randNum;
                        cout << arr[i][j] << " ";
                }
                cout << endl;
        }

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] % 2 == 0) {
				count++;
			}
		}
		if (count == n) {
			cout << "Number of row: " << i + 1 << endl;
			break;
		}
		count = 0;
		if (i == m - 1) {
			cout << "No\n";
		}
	}

	return 0;
}
