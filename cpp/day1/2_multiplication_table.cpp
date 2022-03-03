#include <iostream>
using namespace std;
int main() {
	int num;
	do {
		cout << "Enter number: ";
		cin >> num;
	}
	while (num < 1 || num > 9);

		int x = 2;
		int a = 8;
		while (a) {
			cout << num << " * " << x << " = " << num * x << "\n";
			x++;
			a--;
		}
	
			 

return 0;
}
