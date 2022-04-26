#include <iostream>
#include "deque.h"

using namespace std;

int main() {
    Deque a;
    int number;
    cout << "Make a list of 15 element\n";
    srand(time(0));
    for (int i = 0; i < 15; ++i) {
        number = 1 + rand() % 10;
        a.PushBack(number);
    }
    cout << a;
    a.PushFront(32);
    cout << "Add from the beginning " << endl << a;
    cout << "Remove first element - " << a.PopFront() << endl << a;
    cout << "Remove last element - " << a.PopBack() << endl << a;

    return 0;
}