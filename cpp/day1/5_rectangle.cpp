#include <iostream>
using namespace std;

int main() {
	int length, width; 
	cout << "Input length of rectangle: ";
	cin >> length;
	cout << "Input width of rectangle: ";
        cin >> width;
	int p = 2 * (length + width);
	int s = length * width;
	cout << "p = " << p << "\n" << "s = " << s << "\n";
	
}
