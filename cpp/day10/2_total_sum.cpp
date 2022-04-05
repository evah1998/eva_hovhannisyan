#include <iostream>
#include <cmath>

using namespace std;

void getCurrentMonthNumber(string currentTime, string months[12], string *currentMonth, int *currentMonthNumber, int *currentDay, int *currentYear) {
	string date[5] = {};
	int j = 0;

	for (int i = 0; currentTime[i] != '\0'; i++) {
		if (currentTime[i] == ' ') {
			j++;
			continue;
		}

		date[j] += currentTime[i];
	}

	for (int i = 0; i < 12; i++) {
		if (date[1] == months[i]) {
			*currentMonth = months[i];
			*currentMonthNumber = i + 1;
		}
	}

	*currentDay = stoi(date[2]);
	*currentYear = stoi(date[4]);
}

int main(int argc, char* argv[]) {
  string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	float mom_sum = atof(*(argv + 1));
	float perecent = atof(*(argv + 2));
	int month = atoi(*(argv + 3));

	time_t t = time(0);
	string dateTime = ctime(&t);
	cout << dateTime;

	string currentMonth;
	int currentMonthNumber;
	int currentDay;
	int currentYear;

	getCurrentMonthNumber(dateTime, months, &currentMonth, &currentMonthNumber, &currentDay, &currentYear);
	
	int monthPosition = currentMonthNumber;

	cout << "===============================================" << endl;
	cout << "Month \t | Total sum \t | Month sum \t | Year" << endl; 
	cout << "===============================================" << endl;

	for (int i = currentMonthNumber; i <= currentMonthNumber + month; i++) {
		float month_sum = (mom_sum * (perecent / 12.0) / 100.0);
		month_sum = (floor(month_sum * 100.0) / 100.0) + 0.01;
		mom_sum += month_sum;

		if (i % 12 == 1) {
			currentYear++;
			monthPosition = 1;
		}

		cout << months[monthPosition - 1] << "\t | " << mom_sum << "\t | " << month_sum;

		if (monthPosition == 1) {
			cout << "\t | " << currentYear << endl;
		} else {
			cout << "\t | " << endl;
		}

		monthPosition++;
	}

	return 0;
}
