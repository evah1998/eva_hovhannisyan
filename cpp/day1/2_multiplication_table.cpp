#include <iostream>
using namespace std;
int main() {
	int num;
	do {
		cout << "Enter number: ";
		cin >> num;
	}
	while (num < 1 || num > 10);

	int x = 1;
	int a = 9;
	while (a) {
		cout << num << " * " << x << " = " << num * x << "\n";
		x++;
		a--;
	}
	
			 

return 0;
}
