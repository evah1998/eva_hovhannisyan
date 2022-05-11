#include "dijkstras_path_algoritm.h"

int main() {
    Matrix matrix(6);
    matrix.addEdge(0, 1, 2);
    matrix.addEdge(0, 2, 5);
    matrix.addEdge(0, 4, 3);
    matrix.addEdge(1, 2, 6);
    matrix.addEdge(2, 3, 8);
    matrix.addEdge(2, 4, 4);
    matrix.addEdge(3, 4, 7);
    matrix.printMatrix();
    matrix.algoritm(0);
}