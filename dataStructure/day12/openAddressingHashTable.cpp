#include "openAddressingHashTable.h"

int main() {
    HashTable a;

    a.insert("Anna", "21");
    a.insert("Ani", "13");
    a.remove("Anna");
    a.printTable();
    cout << "search " << a.search("Ani") << endl;

    return 0;
}