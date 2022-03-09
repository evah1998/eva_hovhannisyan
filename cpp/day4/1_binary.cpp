#include <iostream>
using namespace std;

void binary(int);
int main() {
	int num = 0;
	while (num <= 0) {
		cout << "Input number: ";
		cin >> num;
	}
	binary(num);
	cout << endl;
	return 0;
}
void binary(int num) {
	if (num == 1) {
		cout << "1";
		return;
	}
	binary(num / 2);
	cout << num % 2;
}
