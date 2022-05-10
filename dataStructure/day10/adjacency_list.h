#ifndef GRAPH_LIST
#define GRAPH_LIST

#include <iostream>
#include "../day1/linkedList/linkedList.h"
#include "../day1/linkedList/linkedList.cpp"

class Graph {
    private:
        LinkedList* _arr;
        int _size;
        void remove(int, int);
    public:
        Graph(int);
        void addEdge(int, int);
        void removeEdge(int, int);
        void addNode();
        void removeNode(int);
        void isEdgeExists(int, int);
        void findNeighbours();
        void findConnections();
        void printAdjList();
        //~Graph();
};

Graph::Graph(int size) {
    _size = size;
    _arr = new LinkedList[_size];
}

void Graph::addEdge(int i, int j) {
    _arr[i].Add(j);
    _arr[j].Add(i);
}

void Graph::removeEdge(int i, int j) {
    remove(i, j);
    remove(j, i);
}

void Graph::remove(int i, int j) {
    
    Node* prev = _arr[i]._head;
    while (prev->next->data != j) {
        prev = prev->next;
    }
    Node* tmp = prev->next;
    prev->next = tmp->next;
    delete tmp;
    --_arr[i]._count;
}

void Graph::addNode() {
    ++_size;
    LinkedList* newArr = new LinkedList[_size];
    for (int i = 0; i < _size - 1; ++i) {
        newArr[i] = _arr[i];
    }
    _arr = newArr;
}

void Graph::removeNode(int list) {
    /*
    for (int i = 0; i < _size; ++i) {
    Node* prev = _arr[i]._head;
    for (int j = 0; j < _arr[i]._count; ++j) {
        if (prev->next->data == list) {
            prev = prev->next;
            remove(i, list);
            --_arr[i]._count;
        }
    }*/
    for (int i = list; i < _size - 1; ++i) {
        _arr[i] = _arr[i + 1];
    }
    --_size;
}

void Graph::printAdjList() {
    for (int i = 0; i < _size; ++i) {
        cout << i << "->" << _arr[i] << "NULL" << endl;
    }
}

#endif