#include <iostream>
using namespace std;

int main() {
	int n;
 long double factorial = 1.0;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0)
        cout << "Error! Factorial of a negative number\n";
    else {
	int i = 0;
	while (i < n) {
		i++;
        	factorial *= i;
        }
        cout << "Factorial of " << n << " = " << factorial << "\n";    
    }

}
