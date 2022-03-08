#include <iostream>
using namespace std;

void leapYears(int year,int a) {
	while (a != 20) {
		if (year % 4 == 0) { 
			cout << year << "\n";
			a++;
		}
		year++;
	}
}
int main() {
	leapYears(2022,0);
	return 0;
}
