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
        Node* search(Node*, int);
        Node* deleteNode(Node*, int);
    public:
        Node* _root;
        Tree(int);
        void printByAscendingOrder();
        Node* insert(int);
        Node* search(int);
        Node* deleteNode(int);
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

Node* Tree::search(int data) {
    return search(_root, data);
}

Node* Tree::search(Node* tmp, int data) {
    if (tmp == NULL || tmp->_data == data) {
       return tmp;
    }
    if (data > tmp->_data) {
       return search(tmp->_right, data);
    }
    return search(tmp->_left, data);
}

Node *Tree::deleteNode(int value) {
    return deleteNode(_root, value);
}

Node *Tree::deleteNode(Node *root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->_data) {
        root->_left = deleteNode(root->_left, value);
    } else if (value > root->_data) {
        root->_right = deleteNode(root->_right, value);
    } else {
        if (root->_left == NULL && root->_right == NULL) {
            root = NULL;
        } else if (root->_left == NULL) {
            root = root->_right;
        } else if (root->_right == NULL) {
            root = root->_left;
        } else {
            Node *temp = root->_right;
            while (temp->_left) {
                temp = temp->_left;
            }
            root->_data = temp->_data;
            root->_right = deleteNode(root->_right, temp->_data);
        }
    }
    return root;
}

#endif