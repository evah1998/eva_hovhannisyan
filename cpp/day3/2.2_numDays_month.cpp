#include <iostream>
using namespace std;

int inputMonth(int);
void isMonth(int);
int main() {
	int month = inputMonth(month);
	isMonth(month);
	return 0;
}

int inputMonth(int monthNum) {
	do
	{
		cout << "Input month number: ";
		cin >> monthNum;	
	}
	while (monthNum < 1 || monthNum > 12);
	return monthNum;
}
void isMonth(int monthNum) {	
	switch (monthNum)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout << "Total number of days = 31\n";
			break;
		case 2:
                        cout << "Total number of days = 28 or 29.Input year: ";
			int year;
			cin >> year;
			if (year % 4 == 0) {
				cout << "Total number of days = 29\n";
			} else {
				cout << "Total number of days = 28\n";
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
                     	cout << "Total number of days = 30\n";
                        break;
			
	}
}
