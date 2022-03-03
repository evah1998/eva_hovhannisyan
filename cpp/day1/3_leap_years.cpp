#include <iostream>
using namespace std;
int main() {
	int year = 2022;
	int a = 0;
	while (a != 20) {
		if (year % 4 == 0) { 
			cout << year << "\n";
			a++;
		}
		year++;
	}
}
