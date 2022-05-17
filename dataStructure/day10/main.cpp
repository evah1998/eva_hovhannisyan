#include "adjacency_list.h"

int main() {
    Graph list(5);
    int arr[list.getSize()];
    list.addEdge(0, 1);
    list.addEdge(0, 2);
    list.addEdge(2, 3);
    list.addEdge(1, 2);
/*for (int i = 0; i < list.findNeighbours(1, arr); ++i) {
        cout << arr[i] << " is neighbour" << endl;
    }
    */list.removeEdge(0, 1);
    
    list.removeNode(1);
    list.addNode();
    list.printAdjList();

    return 0;
}