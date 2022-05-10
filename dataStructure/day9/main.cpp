#include "graph.h"

int main() {
    UndirectGraph graph(4);
    int arr[graph.GetVertices()];
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(3, 2);
    graph.PrintMatrix();
    cout << graph.isEdgeExist(2, 3) << endl;
    cout << graph.isEdgeExist(0, 3) << endl;
    for (int i = 0; i < graph.NodeNeighbours(1, arr); ++i) {
        cout << arr[i] << " is neighbour" << endl;
    }
    graph.AddNode();
    graph.RemoveEdge(2, 3);
    graph.PrintMatrix();
   
    graph.RemoveNode(1);
    graph.PrintMatrix();
    
    return 0;
}