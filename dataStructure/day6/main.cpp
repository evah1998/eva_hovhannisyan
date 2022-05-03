#include "binary_tree.h"

using namespace std;

int main() {
    Tree* t = new Tree(1);
    for (int i = 2; i < 6; i++) {
        t->insert(i);
    }

    t->insert(34);
    t->DFS();
    cout << endl;
    t->BFS();
    cout << endl;
    cout << "min = " << t->min() << endl;
    cout << "max = " << t->max() << endl;
    cout << "sum = " << t->sum() << endl; 

    return 0;
}