#include <iostream>
using namespace std;
int inputWeek(int);
void isWeek(int);
int main() {
	int weekNum = inputWeek(weekNum);
	isWeek(weekNum);
	return 0;
}

int inputWeek(int week) {
	do
	{
		cout << "Input week number(1-7): ";
		cin >> week; 
	}
	while (!(week >= 1 && week <= 7));
	return week;
}
void isWeek(int weekNum) {
	switch (weekNum)
	{
		case 1:
			cout << "Monday\n";
			break;
		case 2:
			cout << "Tuesday\n";
			break;
		case 3:
			cout << "Wednesday\n";
			break;
		case 4:
			cout << "Thursday\n";
			break;
		case 5:
			cout << "Friday\n";
			break;
		case 6:
			cout << "Saturday\n";
			break;
		case 7:
			cout << "Sunday\n";
			break;
	}

}
