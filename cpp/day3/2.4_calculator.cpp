#include <iostream>
using namespace std;

void isOperator(double,char,double);

int main() {
	
	double num1;
	cout << "Input number 1: ";
	cin >> num1;
	
	char op;
	cout << "Input operator: ";
	cin >> op;

	double num2;
	cout << "Input number 2: ";
	cin >> num2;

	isOperator(num1, op, num2);
	return 0;
}

void isOperator(double num1, char op, double num2) {
	double result = 0;
	switch (op) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				cout << "Can not be divided by 0\n";
				return;
			}
			result = num1 / num2;
			break;
		default:
			cout << "Invalid operator\n";
			return;
	} 
	cout << num1 << " " << op << " " << num2 << " = " << result << "\n"; 
}





