#include <iostream>
using namespace std;
int inputNum(int number) {
	do {
		cout << "Enter number: ";
		cin >> number;
	}
	while (number < 1 || number > 10);
	return number;
}
void multiply(int x,int a,int number) {
	while (a) {
		cout << number << " * " << x << " = " << number * x << "\n";
		x++;
		a--;
	}
}
int main() {
	int num;
	num = inputNum(num);
	multiply(1,10,num);	
	return 0;
}
