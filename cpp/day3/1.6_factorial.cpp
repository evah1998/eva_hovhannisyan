#include <iostream>
using namespace std;

int inputNum();
int factorial(int,int,int);
int main() {
	int n = inputNum();
    	if (n < 0) {
	     	cout << "Error! Factorial of a negative number\n";
	} else {
		factorial(0,1,n);
	}
	return 0;
}
int inputNum() {
	int num;
	cout << "Enter a positive integer: ";
	cin >> num;
	return num;
}
int factorial(int i,int factorial,int n) {

	while (i < n) {
		i++;
		factorial *= i;
	}
	cout << "Factorial of " << n << " = " << factorial << "\n";
	return factorial;
}

