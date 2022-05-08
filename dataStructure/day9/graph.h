#include <iostream>
#include <limits>
#include <queue>

using namespace std;

class UndirectGraph {
    private:
        int _vertices;
        bool _matrix[INT8_MAX][INT8_MAX];
    public:
        UndirectGraph(int);
        int GetVertices();
        void AddEdge(int, int);
        void AddNode();
        void RemoveEdge(int, int);
        void RemoveNode(int);
        bool isEdgeExist(int, int);
        void PrintMatrix();
        int NodeNeighbours(int, int*);
};

UndirectGraph::UndirectGraph(int vertices) {
    _vertices = vertices;  
    for (int i = 0; i < _vertices; ++i)
    {
        for (int j = 0; j < _vertices; ++j)
        {   
           _matrix[i][j] = 0;
        }
    }
}

int UndirectGraph::GetVertices() {
    return _vertices;
}

void UndirectGraph::AddEdge(int i, int j) {
    if (i > _vertices || j > _vertices) {
        cout << "Node does not exist\n";
        return;
    }
    _matrix[i][j] = 1;
    _matrix[j][i] = 1;
}

void UndirectGraph::AddNode() {
    ++_vertices;
    for (int i = 0; i < _vertices; ++i) {
        _matrix[i][_vertices-1] = 0;
    }
    for (int j = 0; j < _vertices; ++j) {
        _matrix[_vertices-1][j] = 0;
    }
}

void UndirectGraph::RemoveEdge(int i, int j) {
    if (i > _vertices || j > _vertices || !(_matrix[i][j])) {
        cout << "This edge does not exist\n";
        return;
    }
    _matrix[i][j] = 0;
    _matrix[j][i] = 0;
}

void UndirectGraph::RemoveNode(int node) {
    if (_vertices == 0) {
        cout << "Graph is empty\n";
        return;
    }
    if (node == _vertices - 1) {
        --_vertices;
    } else if (node > _vertices - 1) {
        cout << "This node is not present in the graph\n";
        return;
    } else {
        for (int i = node; i < _vertices; ++i) {
            for (int j = 0; j < _vertices; ++j) {
                _matrix[j][i] =_matrix[j][i + 1];
            }
            for (int j = 0; j < _vertices; ++j) {
               _matrix[i][j] = _matrix[i + 1][j];
            }
        }
        --_vertices;
    }
}

bool UndirectGraph::isEdgeExist(int i, int j) {
    if (_matrix[i][j]) {
        return true;
    }
    return false;
}

void UndirectGraph::PrintMatrix() {
    for (int i = 0; i < _vertices; ++i) {
        for (int j = 0; j < _vertices; ++j) {
            cout << _matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int UndirectGraph::NodeNeighbours(int node, int* arr) {
    int j = 0;
    for (int i = 0; i < _vertices; ++i) {
        if (_matrix[node][i]) {
            arr[j] = i;
            ++j;
        }
    }
    return j;
}