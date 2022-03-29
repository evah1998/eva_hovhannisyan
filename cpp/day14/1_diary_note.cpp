#include <iostream>
#include <fstream>

using namespace std;

string inputDate() {
	string date;
	cout << "Input date: ";
	cin >> date;
	return date;
}

void dateTo_dd_mm_yyyy(string date, string *dateParts, int *day, int *month, int *year) {
	int j = 0;
	for (int i = 0; date[i] != '\0'; i++) {
		if (date[i] == '/') {
			j++;
			continue;
		}
		dateParts[j] += date[i];
	}
	*day = stoi(dateParts[0]);
	*month = stoi(dateParts[1]);
	*year = stoi(dateParts[2]);
}

bool isTrueDate(int *day, int *month, int *year) {
	int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (*month >= 1 && *month <= 12 && *day >= 1 && *day <= arr[*month - 1] && *year >= 1900) {
		if (*month == 2) {
			if (*year % 4 != 0 && *day <= 28) {
				return true;
			} else if (*year % 4 == 0 && *day <= arr[*month - 1]) {
				return true;
			} else {
				return false;
			}
		}
		return true;
	}
	return false;
}

int weekday_num(int day, int month, int year) {
	tm time_in = {0, 0, 0, day, month - 1, year - 1900};
	time_t time_temp = mktime(&time_in);
	const tm* time_out = localtime(&time_temp);
	return time_out->tm_wday;
}

struct diary {
	string note;
	int day;
	enum weekDay {
		Sun,
		Mon,
		Tue,
		Wed,
		Thu,
		Fri,
		Sat,
	};
} diary;

void inputNote() {
	cout << "Add Note: ";
	getline(cin, diary.note);
}

void ofstreamFile(string* dateParts) {
	ofstream file;
	file.open("notes/" + dateParts[0] + "_" + dateParts[1] + "_" + dateParts[2] + ".txt", ios::app);
	file << diary.note << endl;
	file.close();
}

void weekday(int *weekNumber) {
switch(*weekNumber)
	{
		case diary.Mon: 
			cout<<"Mon";
			break;
		case diary.Tue:
			cout<<"Tue";
			break;
		case diary.Wed: 
			cout<<"Wed";
			break;
		case diary.Thu: 
			cout<<"Thu";
			break;
		case diary.Fri: 
			cout<<"Fri";
			break;
		case diary.Sat: 
			cout<<"Sat";
			break;
		case diary.Sun: 
			cout<<"Sun";
			break;
	}
}
int main() {
		string date = "";
		int day, month, year;
		string dateParts[3] = {};
		string *ptr = dateParts;
		string fileName[50];
		int weekNumber[10];
		string addOrExit;
	int i = 0;
	while (true) {
		date = inputDate();
		dateParts[0] = "";
		dateParts[1] = "";
		dateParts[2] = "";
		dateTo_dd_mm_yyyy(date, ptr, &day, &month, &year);
		if (isTrueDate(&day, &month, &year) == false) {
			cout << "Date does not exist\n"; 
			return 0;
		}
		weekNumber[i] = weekday_num(day, month, year);
		cin.ignore();
		inputNote();
		fileName[i] = "notes/" + dateParts[0] + "_" + dateParts[1] + "_" + dateParts[2] + ".txt";
		ofstreamFile(ptr);
		do {
			cout << "Do you want to add another note (command): ";
			cin >> addOrExit;
		} while (addOrExit != "add" && addOrExit != "exit" ); 
		if (addOrExit == "exit") {
			break;
		}
		i++;
	}
	int size = i;
	int *weekPtr = weekNumber;
	for (int i = 0; i <= size; i++) {
		weekday(weekPtr + i);
		cout << "  " << dateParts[0] + "/" + dateParts[1] + "/" + dateParts[2] << endl;
		string print;
		ifstream printFile(fileName[i]);
		while (getline(printFile, print)) {
			cout << "     Note: " << print << endl;
		}
		cout <<	endl;
	}
	return 0;
}
