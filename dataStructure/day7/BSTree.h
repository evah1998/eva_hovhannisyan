#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Node {
    public:
        int _data;
        Node* _left;
        Node* _right;
        Node() {
            _left = NULL;
            _right = NULL;
        }
        Node(int data) {
            _data = data;
        }
};

class Tree {
    private:
        void printByAscendingOrder(Node*);
        Node* insert(Node*, int);
    public:
        Node* _root;
        Tree(int);
        void printByAscendingOrder();
        Node* insert(int);
};

Tree::Tree(int data) {
    _root = new Node(data);
}

void Tree::printByAscendingOrder() {
    printByAscendingOrder(_root);
}

void Tree::printByAscendingOrder(Node* _root) {
    stack<Node*> stack;
    stack.push(_root);
    
    if (_root->_left != NULL) {
        printByAscendingOrder(_root->_left);
    }
    if (!stack.empty()) {
        cout << stack.top()->_data << " ";
        stack.pop();
    }
    if (_root->_right != NULL) {
        printByAscendingOrder(_root->_right);
    }
}

Node* Tree::insert(int data) {
    insert(_root, data);
    return _root;
}

Node* Tree::insert(Node* _root, int data) {
    Node* newNode = new Node(data);
    if (_root == NULL) {
        _root = newNode;
        return _root;
    } else {
        if (data < _root->_data) {
            if (_root->_left == NULL) {
                _root->_left = newNode;
            } else {
                insert (_root->_left, data);
            }
        } else {
            if (_root->_right == NULL) {
                _root->_right = newNode;
            } else {
                insert (_root->_right, data);
            }
        }
    }
    
    return _root;
}

#endif