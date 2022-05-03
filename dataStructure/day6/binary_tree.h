#ifndef BINARY_TREE
#define BINARY_TREE

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
        void DFS(Node*);
    public:
        Node* _root;
        Tree(int);
        void DFS();
        void BFS();
        Node* insert(int);
        int min();
        int max();
        int sum();
};

Tree::Tree(int data) {
    _root = new Node(data);
}

void Tree::DFS() {
    DFS(_root);
}

void Tree::DFS(Node* _root) {
    stack<Node*> stack;
    stack.push(_root);
    
    if (!stack.empty()) {
        cout << stack.top()->_data << " ";
        stack.pop();
    }
    if (_root->_left != NULL) {
        DFS(_root->_left);
    }
    if (_root->_right != NULL) {
        DFS(_root->_right);
    }
}

void Tree::BFS() {
    queue<Node*> q;
    q.push(_root);

    while (!q.empty()) {
        Node* tmp = q.front();
        cout << tmp->_data << " ";
        q.pop();
        if (tmp->_left != NULL) {
            q.push(tmp->_left);
        }
        if (tmp->_right != NULL) {
            q.push(tmp->_right);
        }
    }
}

Node* Tree::insert(int data) {
    Node* newNode = new Node(data);
    if (_root == NULL) {
        _root = newNode;
        return _root;
    } 
    queue <Node*> q;
    q.push(_root);
    while (!q.empty()) {
        Node* tmp = q.front();
        q.pop();

        if (tmp->_left == NULL) {
            tmp->_left = newNode;
            return _root;
        } else {
            q.push(tmp->_left);
        }
        if (tmp->_right == NULL) {
            tmp->_right = newNode;
            return _root;
        } else {
            q.push(tmp->_right);
        }
    }
    return _root;
}

int Tree::min() {
    if (!_root) {
        return 0;
    }

    queue<Node*> q;
    q.push(_root);
    int min = _root->_data;
    while (!q.empty()) {
        Node* tmp = q.front();
        q.pop();
        if(tmp->_data < min) {
            min = tmp->_data;
        }
        if (tmp->_left != NULL) {
            q.push(tmp->_left);
        }
        if (tmp->_right != NULL) {
            q.push(tmp->_right);
        }
    }
    return min;
}

int Tree::max() {
    if (!_root) {
        return 0;
    }

    queue<Node*> q;
    q.push(_root);
    int max = _root->_data;
    while (!q.empty()) {
        Node* tmp = q.front();
        q.pop();
        if(tmp->_data > max) {
            max = tmp->_data;
        }
        if (tmp->_left != NULL) {
            q.push(tmp->_left);
        }
        if (tmp->_right != NULL) {
            q.push(tmp->_right);
        }
    }
    return max;
}

int Tree::sum()
{
    if (!_root) {
        return 0;
    }

    int sum = 0;
    queue<Node*> q;
    q.push(_root);
    
    while (!q.empty()) {
        Node* tmp = q.front();
        q.pop();
        sum+=tmp->_data;

        if (tmp->_left != NULL) {
            q.push(tmp->_left);
        }
        if (tmp->_right != NULL) {
            q.push(tmp->_right);
        }
    }
    return sum;
}

#endif