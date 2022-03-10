#include <iostream>
using namespace std;
int inputNum() {
	int number;
	do {
		cout << "Enter number: ";
		cin >> number;
	}
	while (number < 1 || number > 10);
	return number;
}
void multiply(int number) {
	int a = 1;
	while (a <= 10) {
		cout << number << " * " << a << " = " << number * a << "\n";
		a++;
	}
}
int main() {
	int num = inputNum();
	multiply(num);	
	return 0;
}
