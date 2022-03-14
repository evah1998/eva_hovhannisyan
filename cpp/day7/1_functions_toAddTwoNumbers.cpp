#include <iostream>
using namespace std;

void sum1(int*, int*, int*);
void sum2(int&, int&, int&);
void sum3(int a, int b, int &sum);
void sum4(int, int*, int&);
void sum5(int*, int*, int&);
void printSum(int, int, int); 
int main() {
	int x, y;
	cout << "Input x & y for function sum1" << endl; 
	cin >> x >> y;
	int sum;
	sum1(&x, &y, &sum);
	printSum(x, y, sum);

	cout << "Input x & y for function sum2" << endl; 
	cin >> x >> y;
	sum2(x, y, sum);
	printSum(x, y, sum);

	cout << "Input x & y for function sum3" << endl; 
	cin >> x >> y;
	sum3(x, y, sum);
	printSum(x, y, sum);

	cout << "Input x & y for function sum4" << endl; 
	cin >> x >> y;
	sum4(x, &y, sum);
	printSum(x, y, sum);

	cout << "Input x & y for function sum5" << endl; 
	cin >> x >> y;
	sum5(&x, &y, sum);
	printSum(x, y, sum);
	
	return 0;
}

void sum1(int *a, int *b, int *sum) {
	*sum = *a + *b;
}

void sum2(int &a, int &b, int &sum) {
	sum = a + b;
}

void sum3(int a, int b, int &sum) {
	sum = a + b;
}

void sum4(int a, int *b, int &sum) {
	sum = a + *b;
}

void sum5(int *a, int *b, int &sum) {
	sum = *a + *b;
}
void printSum(int x, int y, int sum) {
	cout << x << " + " << y << " = " << sum << endl;
}
