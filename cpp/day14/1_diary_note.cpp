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
bool isFileExists(string readFileNames[], string fileName[], int fileLinesCount, int i) {
	ofstream fileNames("fileNames.txt", ios::app);
		for (int j = 0; j < fileLinesCount; j++) {
			if (readFileNames[j] == fileName[i]) {
				return false;
			} 
		}
		fileNames << fileName[i] << endl;
		fileNames.close();
		return true;
}

string weekday(int weekNumber) {
	string weekDay = " ";
	switch(weekNumber) {
		case diary.Mon: 
			weekDay = "Mon";
			break;
		case diary.Tue:
			weekDay = "Tue";
			break;
		case diary.Wed: 
			weekDay = "Wed";
			break;
		case diary.Thu: 
			weekDay = "Thu";
			break;
		case diary.Fri: 
			weekDay = "Fri";
			break;
		case diary.Sat: 
			weekDay = "Sat";
			break;
		case diary.Sun: 
			weekDay = "Sun";
			break;
	}
	return weekDay;
}
void ofstreamFile(string* dateParts, bool check, string weekDay) {
	ofstream file;
	file.open("notes/" + dateParts[0] + "_" + dateParts[1] + "_" + dateParts[2] + ".txt", ios::app);
	if (check) {
		file << weekDay + " " + dateParts[0] + "/" + dateParts[1] + "/" + dateParts[2] << endl;
	}
	file << diary.note << endl;
	file.close();
}


int main() {
	string date = "";
	int day, month, year;
	string dateParts[3] = {};
	string *ptr = dateParts;
	string fileName[50];
	int weekNumber;
	string addOrExit;
	int i = 0;
	
	while (true) {
		date = inputDate();
		dateParts[0] = "";
		dateParts[1] = "";
		dateParts[2] = "";
		dateTo_dd_mm_yyyy(date, ptr, &day, &month, &year);
		if (!(isTrueDate(&day, &month, &year))) {
			cout << "Date does not exist\n"; 
			return 0;
		}
		weekNumber = weekday_num(day, month, year);
		cin.ignore();
		inputNote();
		fileName[i] = "notes/" + dateParts[0] + "_" + dateParts[1] + "_" + dateParts[2] + ".txt";

		string line;
		int fileLinesCount = 0;
		ifstream fileLines("fileNames.txt");
		while (getline(fileLines, line)) {
			fileLinesCount++;
		}
		string readFileNames[fileLinesCount];
		string readFile;
		fileLines.close();
		
		ifstream checkFileNames("fileNames.txt");
		int k = 0;
		while (getline(checkFileNames, readFile)) {
			readFileNames[k] = readFile;
			k++;
		}
		checkFileNames.close();

		bool check = isFileExists(readFileNames, fileName, fileLinesCount, i);
		string weekDay;
		weekDay = weekday(weekNumber);
		ofstreamFile(ptr, check, weekDay);
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
		string str;
		int count = 0;
		ifstream newFileLines("fileNames.txt");
		while (getline(newFileLines, str)) {
			count++;
		}
		newFileLines.close();
	
		ifstream file("fileNames.txt");
		int k = 0;
		string strFile;
		string fileLinesArr[count];
		while (getline(file, strFile)) {
			fileLinesArr[k] = strFile;
			k++;
		}
		file.close();
		for (int i = 0; i < k; i++) {	
			string print;
			ifstream printFile(fileLinesArr[i]);
			bool isFirstLine = true;
			while (getline(printFile, print)) {
				if (!isFirstLine) {
					cout << "note: ";
				}
				cout << print << endl;
				isFirstLine = false;
			}
			cout <<	endl;
		}
	return 0;
}
