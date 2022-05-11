#ifndef DIJKSTRAS_PATH
#define DIJKSTRAS_PATH

#include <iostream>
#include <limits>

using namespace std;

class Matrix {
    private:
        int** _matrix;
        int _vertices;
        int minDistance(int*, bool*);
    public:
        Matrix(int);
        void addEdge(int, int, int);
        void printMatrix();
        void algoritm(int);
};

Matrix::Matrix(int vertices) {
    _vertices = vertices;  
    _matrix = new int *[_vertices];
    for (int i = 0; i < _vertices; ++i)
    {
        _matrix[i] = new int[_vertices];
        for (int j = 0; j < _vertices; ++j)
        {   
           _matrix[i][j] = INT8_MAX;
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < _vertices; ++i) {
        for (int j = 0; j < _vertices; ++j) {
            cout << _matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::addEdge(int i, int j, int value) {
    if (i > _vertices || j > _vertices) {
        cout << "Node does not exist\n";
        return;
    }
    _matrix[i][j] = value;
    _matrix[j][i] = value;
}

int Matrix::minDistance(int distances[], bool visited[]) {
    int min = INT8_MAX;
    int minIndex;
    for (int i = 0; i < _vertices; ++i) {
        if (distances[i] < min && !visited[i]) {
            min = distances[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Matrix::algoritm(int start) {
    int distances[_vertices];
    bool visited[_vertices];
    for (int i = 0; i < _vertices; ++i) {
        visited[i] = false;
        distances[i] = INT8_MAX;
    }
    distances[start] = 0;
    for (int k = 0; k < _vertices; ++k) {
        int min = minDistance(distances, visited);
        visited[min] = true;
        for (int k = 0; k < _vertices; ++k) {
            if(!visited[k] 
                && _matrix[min][k] 
                && distances[min] != INT8_MAX 
                && distances[min] + _matrix[min][k] < distances[k]) {
                distances[k] = distances[min] + _matrix[min][k];
            } 
        }
    }
    cout << "Distances\n";
    for (int i = 0; i < _vertices; ++i) {
        cout << distances[i] << " ";
    }
    cout << endl;
}

#endif