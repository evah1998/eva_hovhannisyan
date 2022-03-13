#include <iostream>
using namespace std;

int main() {
	srand(time(0));
	const int N = 5;
	int sum;
	int a[N][N] = {}, b[N][N] = {};
	cout << "First matrix" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = rand() % 10 + 1;
			if (a[i][j] < 10) {
				cout << " ";
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Second matrix" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			b[i][j] = rand() % 10 + 1;
			if (b[i][j] < 10) {
				cout << " ";
			}
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Sum of two matrix" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum = a[i][j] + b[i][j];
			if (sum < 10) {
				cout << " ";
			}
			cout << sum << " ";
		}
		cout << endl;
	}
	return 0;
}
