#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue a;
    int number;
    cout << "Make a list of 15 element\n";
    srand(time(0));
    for (int i = 0; i < 15; ++i) {
        number = 1 + rand() % 10;
        a.PushBack(number);
    }
    cout << a;
    cout << "Remove first element - " << a.PopFront() << endl << a;

    return 0;
}
