#include <iostream>
using namespace std;

void timeConverter(int*, int, int*);

int main() {
	int seconds;
	cout << "Input: ";
	cin >> seconds;

	int secondsMinute = 60, minute = 0;
	int secondsHour = 3600, hour = 0;
	int secondsDay = 86400, day = 0;
	int monthNumber = 0;
	int startYear = 1970;

	timeConverter(&seconds, secondsDay, &day);

	while (day >= 365) {
		if ((startYear % 4 == 0 && startYear % 100 != 0) || startYear % 400 == 0) {
			day -= 366;
		} else {
			day -= 365;
		}
		startYear += 1;
	}
	int leapYear = 0;
	if ((startYear % 4 == 0 && startYear % 100 != 0) || startYear % 400 == 0) {
		leapYear = 1;
	}
	day += 1;

	int daysArr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	for (int i = 0; day >= 30; i++) {
		if (leapYear == 1 && i == 1) {
			day -= 29;	
			monthNumber++;
		} else {
			day -= daysArr[i];
			monthNumber++;
		}
	}
	
	timeConverter(&seconds, secondsHour, &hour);
	timeConverter(&seconds, secondsMinute, &minute);

	cout << months[monthNumber] << " " << day << " " << startYear << " " << hour << ":" << minute << endl;
	return 0;
}

void timeConverter(int *seconds, int constTime, int *time) {
	if (*seconds > constTime) {
		*time = *seconds / constTime;
		*seconds %= constTime;
	}
}
