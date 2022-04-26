#include "vector.h"
#include <iostream>

int main() {
    
    Vector v;
    int number;
    for (int i = 0; i < 5; ++i) {
        number = rand() % 10;
        v.Add(number);
    }
    cout << v;

    v.AddFront(20);
    //cout << v[2];
    cout << v;

    v.AddAt(2, 10);
    cout << v;

    v.RemoveAt(6);
    cout << v;

    v.RemoveAll();
    cout << v;
}