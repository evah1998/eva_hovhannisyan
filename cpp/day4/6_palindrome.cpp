#include <iostream>
#include <string.h>
using namespace std;

bool ispalindrome(string);

int main() {
	cout << "Input: ";
	string s;
	cin >> s;
	const int alpha = 'a'-'A';
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += alpha;
		}
	}
	if (ispalindrome(s)) {
		cout << "True\n";
	}
	return 0;
}

bool ispalindrome(string s) {
	for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
		if (s[i] != s[j]) {
			return false;	
		}
	}
	return true;
}
		
	
