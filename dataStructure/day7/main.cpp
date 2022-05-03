#include "BSTree.h"

using namespace std;

int main() {
    Tree* b = new Tree(5);
    b->insert(21);
    b->insert(5);
    b->insert(3);
    b->insert(1);
    b->insert(7);

    b->printByAscendingOrder();
    cout << endl;

    return 0;
}