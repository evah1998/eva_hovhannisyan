#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
    Linked_list a;
    int number;
    cout << "Make a list of 20 element\n";
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        number = 1 + rand() % 10;
        a.Add(number);
    }
    cout << a;
    
    cout << "Add an element after the 4-th element\n";
    a.AddAt(5, 10);
    cout << a;
    
    cout << "Delete element 3-rd\n";
    a.RemoveAt(3);
    cout << a;
    
    cout << "Add an element from the end\n";
    a.Add(12);
    cout << a;
    
    cout << "Delete the last element\n";
    a.Remove();
    cout << a;
    
    cout << "The 5-th element = " << a.GetDataElementAt(5) << endl;

    cout << "Count = " << a.Count() << endl;
    return 0;
}
