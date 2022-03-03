#include <iostream>
using namespace std;
int main() {
	int num;
	do {
		cout << "Enter a number from 1 to 100: ";
		cin >> num;
	}
	while (num <= 0 || num >= 100);
	
	bool a = true;
	int num_1;

	do {
		cout << "Guess the number: ";
		cin >> num_1;
		if (num_1 == num) {
			cout << "True \n";
			a = false;
		} else if (num_1 > num) {
			cout << "Enter a smaller number \n";
		} else {
			cout << "Enter a larger number \n";
		}
	}
	while (a);

	return 0;
}
