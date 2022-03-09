#include <iostream>
using namespace std;

bool isPerfect(int);

int main() {
	int num = 0;
	while (num < 1) {
		cout << "Input: ";
		cin >> num;
	}
	if (isPerfect(num)) {
		cout << num << " is perfect" << endl;
	} else {
		cout << num << " is not perfect" << endl;	
	}
	return 0;
}

bool isPerfect(int num) {
	int sum = 0;
	for (int i = num / 2; i > 0; i--) {
		if (num % i == 0) {
			sum+=i;
		}
	} 	
	if (num == sum) { 
		return true;
	}
	return false;
}
