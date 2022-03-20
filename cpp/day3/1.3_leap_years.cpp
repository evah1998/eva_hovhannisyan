#include <iostream>
using namespace std;

void leapYears() {
	int year = 2022, a = 0;
	while (a != 20) {
		if (year % 4 == 0) { 
			cout << year << "\n";
			a++;
		}
		year++;
	}
}
int main() {
	leapYears();
	return 0;
}
