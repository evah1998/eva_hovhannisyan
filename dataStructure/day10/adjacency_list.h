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
        int getSize();
        void addEdge(int, int);
        void removeEdge(int, int);
        void addNode();
        void removeNode(int);
        bool isEdgeExists(int, int);
        int findNeighbours(int, int*);
        void findConnections();
        void printAdjList();
        //~Graph();
};

Graph::Graph(int size) {
    _size = size;
    _arr = new LinkedList[_size];
}

int Graph::getSize() {
    return _size;
}

void Graph::addEdge(int i, int j) {
    _arr[i].Add(j);
    _arr[j].Add(i);
}


void Graph::remove(int i, int j) {    
    Node *prev = _arr[i]._head;
    if (prev->data == j) {
        _arr[i]._head = prev->next;
        delete prev;
        return;
    }
    while (prev->next) {
        if (prev->next->data == j) {
            Node* tmp = prev->next;
            prev->next = tmp->next;
            delete tmp;
            return;
        }
        prev = prev->next;
    }
    --_arr[i]._count;
}

void Graph::removeEdge(int i, int j) {
    remove(i, j);
    remove(j, i);
}

void Graph::addNode() {
    ++_size;
    LinkedList* newArr = new LinkedList[_size];
    for (int i = 0; i < _size - 1; ++i) {
        newArr[i] = _arr[i];
    }
    _arr = newArr;
}

bool Graph::isEdgeExists(int i, int j) {
    Node *temp = _arr[i]._head;
    while (temp) {
        if (temp->data == j) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Graph::removeNode(int list) {
    for (int i = 0; i < _size; ++i) {
        if (isEdgeExists(i, list)) {
            remove(i, list);
        }
    }
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