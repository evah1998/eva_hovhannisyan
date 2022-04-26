#include "vector.h"
#include <iostream>

int main() {
    
    Vector vector;
    int number;
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        number = rand() % 10;
        vector.Add(number);
    }
    cout << "Create a vector\n" << vector;

    cout << "vector[3] = " << vector[3] << endl;
    vector.AddFront(20);
    cout << "Add from the beginning\n" << vector;

    vector.AddAt(3, 10);
    cout << "Add an element after the 2-th element\n" << vector;

    vector.RemoveAt(6);
    cout << "Delete element 6-rd\n" << vector;

    vector.RemoveAll();
    cout << "Remove All\n" << vector;
}