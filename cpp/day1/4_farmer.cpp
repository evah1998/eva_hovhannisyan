#include <iostream>
using namespace std;
int main() {
	int chicken, cow, pig;
	cout << "How many chickens are there? ";
	cin >> chicken;
	cout << "How many cows are there? ";
	cin >> cow;
	cout << "How many pigs are there? ";
	cin >> pig;
	int sum_legs = chicken * 2 + cow * 4 + pig * 4;
	cout << sum_legs << "\n";

	return 0;
}
