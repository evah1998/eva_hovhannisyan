#include <iostream>
using namespace std;

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

	double result;
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
				return 0;
			}
			result = num1 / num2;
			break;
		default:
			cout << "Invalid operator\n";
			return 0;
	} 
	
	cout << num1 << " " << op << " " << num2 << " = " << result << "\n"; 

	return 0;
}
