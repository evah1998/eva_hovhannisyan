#include <iostream>
using namespace std;

int main() {
	int x1, x2, x3, x4, y1, y2, y3, y4;
	cout << "Input A(x1, y1): ";
	cin >> x1 >> y1;
	
	cout << "Input B(x2, y2): ";
	cin >> x2 >> y2;

	cout << "Input C(x3, y3): ";
	cin >> x3 >> y3;

	cout << "Input D(x4, y4): ";
	cin >> x4 >> y4;

	if ((x1 == x2 && y1 == y2) || (x3 == x4 && y3 == y4)) {
		cout << "No\n";
	} else if ((x1 == x2 && y3 == y4) || (x3 == x4 && y1 == y2)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}
