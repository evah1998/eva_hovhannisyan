#ifndef GRAPH_MATRIX
#define GRAPH_MATRIX

#include <iostream>
#include <queue>

using namespace std;

class UndirectGraph {
    private:
        bool **_matrix;
        int _vertices;
    public:
        UndirectGraph(int);
        ~UndirectGraph();
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
    _matrix = new bool *[_vertices];
    for (int i = 0; i < _vertices; ++i)
    {
        _matrix[i] = new bool[_vertices];
        for (int j = 0; j < _vertices; ++j)
        {   
           _matrix[i][j] = 0;
        }
    }
}

UndirectGraph::~UndirectGraph() {
    for (int i = 0; i < _vertices; ++i) {
        RemoveNode(_vertices - 1);
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
    bool **newArr = new bool *[_vertices];
    for (int i = 0; i < _vertices; ++i) {
        newArr[i] = new bool[_vertices];
        for (int j = 0; j < _vertices; ++j) {
            if (i != _vertices - 1 && j != _vertices - 1) {
                newArr[i][j] = _matrix[i][j];
            } else {
                newArr[i][j] = false;
            }
        }
    }
    delete _matrix;
    _matrix = newArr;
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
    } else if (node > _vertices - 1) {
        cout << "This node is not present in the graph\n";
        return;
    } else {
        delete _matrix[node];
        for (int i = node; i < _vertices - 1; ++i) {
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
    return _matrix[i][j];
}

void UndirectGraph::PrintMatrix() {
    for (int i = 0; i < _vertices; ++i) {
        for (int j = 0; j < _vertices; ++j) {
            cout << _matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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

#endif