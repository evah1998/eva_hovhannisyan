#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack a;
    int number;
    cout << "Make a list of 10 element\n";
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        number = 1 + rand() % 10;
        a.Push(number);
    }
    cout << a;
	cout << "Remove last element - " << a.Pop() << endl << a;
 
	cout << "Last element is " << a.Peek() << endl << a; 

	return 0;
}