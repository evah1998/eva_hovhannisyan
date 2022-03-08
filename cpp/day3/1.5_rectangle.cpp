#include <iostream>
using namespace std;
int isP(int length,int width) {
	return (2 * (length + width));
}
int isS(int length,int width) {
	return length * width;
}
int main() {
	int length, width; 
	cout << "Input length of rectangle: ";
	cin >> length;
	cout << "Input width of rectangle: ";
        cin >> width;
	int s = isS(length,width);
	int p = isP(length,width);
	cout << "p = " << p << "\n" << "s = " << s << "\n";
	return 0;	
}
