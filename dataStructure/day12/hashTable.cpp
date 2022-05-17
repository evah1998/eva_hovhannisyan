#include <iostream>
#include "hashTable.h"
#include <string.h>

using namespace std;

int main() {
    HashTable a(100);
    
    a.insert("Jon", "11");
    cout << "Insert " << a << endl;
   
    cout << "Search " << a.search("Jon") << endl;
    
    a.remove("Jon");
    cout << "Remove " << a << endl;
    
    cout << "Search " << a.search("Jon") << endl;

    return 0;
}