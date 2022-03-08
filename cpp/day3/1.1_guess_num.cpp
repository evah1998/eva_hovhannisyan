#include <iostream>
using namespace std;

int inputNum(int number) {
	do {
		cout << "Enter a number from 1 to 100: ";
		cin >> number;
	}
	while (number <= 0 || number >= 100);
	return number;
}
void guessNum(int number, int number1) {

		if (number1 == number) {
			cout << "True \n";
		} else if (number1 > number) {
			cout << "Enter a smaller number \n";
		} else {
			cout << "Enter a larger number \n";
		}
}
void inputGuessNum(int number, int number1) {
	bool a = true;
	do {
		cout << "Guess the number: ";
		cin >> number1;
		if (number1 == number) {
			a = false;
		}
		guessNum(number, number1);
	}
	while (a);
}

int main() {
	int num;
	int num_1;
	num = inputNum(num);
	inputGuessNum(num, num_1);	
	return 0;
}
