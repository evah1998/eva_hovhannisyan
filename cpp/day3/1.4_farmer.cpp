#include <iostream>
using namespace std;
void sum_legs(int,int,int);
int main() {
	int chicken, cow, pig;
	cout << "How many chickens are there? ";
	cin >> chicken;
	cout << "How many cows are there? ";
	cin >> cow;
	cout << "How many pigs are there? ";
	cin >> pig;

	sum_legs(chicken,cow,pig);
	return 0;
}

void sum_legs(int chicken,int cow,int pig) {
	int sum_legs = chicken * 2 + cow * 4 + pig * 4;
        cout << sum_legs << "\n";
}
