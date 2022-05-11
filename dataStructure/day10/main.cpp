#include "adjacency_list.h"

int main() {
    Graph list(5);
    list.addEdge(0, 1);
    list.addEdge(0, 2);
    list.addEdge(2, 3);
    list.addEdge(1, 2);
    list.removeEdge(0, 1);
    
    list.removeNode(1);
    list.addNode();
    list.printAdjList();
}