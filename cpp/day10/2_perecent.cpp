#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	double mom_sum = stod(*(argv + 1));
	double perecent = stod(*(argv + 2));
	int month = atoi(*(argv + 3));

	time_t t = time(0);
	tm* timePtr = localtime(&t);
	int currentMonth = timePtr->tm_mon + 1;
	int currentDay = timePtr->tm_mday;

	cout << "month of year:" << currentMonth << endl; 
	cout << "day of month: " << currentDay << endl;
	for (int i = currentMonth; i < currentMonth + month; i++) {
		double month_sum = (mom_sum * (perecent / 12) / 100);
		month_sum = floor(month_sum * 100) / 100;
		mom_sum += month_sum;
		cout << "month:" << i << "  " << "mom_sum:" << mom_sum << "  "<< "month_sum:" << month_sum << endl;
	}

	return 0;
}
