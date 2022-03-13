#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int count = 0;
	int temp = 0;
	string str;
	cout << "Input string: ";
	getline (cin, str);
	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] < 'A' || str[i] > 'Z') && str[i] != ' ') { 
			cout << "Enter a capital letter" << endl;
			return 0;
		}	
		if (str[i] == 'B') {
			temp++;
		}
		if (str[i] == ' ') {
			if (temp == 2) {
				count++;
			}
			temp = 0;
		}
	}
	if (temp == 2) {
		count ++;
	}	
	if (count > 0) {
		cout << "There are " << count << " words in containing two B letters." << endl;
	} else {
		cout << "There are no words containing two B letters" << endl;
	}
	return 0;
} 
