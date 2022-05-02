#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Tree {
    public:
            int _data;
            Tree* _left;
            Tree* _right;
    Tree() {
        _left = NULL;
        _right = NULL;
    }

    Tree(int data) {
        _data = data;
    }
};

void DFT(Tree*);
void BFT(Tree*);
Tree* insert(Tree*, int);
Tree* min(Tree*);
Tree* max(Tree*);
int sum(Tree*);

int main() {
    Tree* root = new Tree(1);
    root->_left = new Tree(2);
    root->_right = new Tree(3);
    root->_left->_left = new Tree(4);
    root->_left->_right = new Tree(5);
    insert(root, 34);
    DFT(root);
    cout << endl;
    BFT (root);
    cout << endl;
    cout << "min = " << min(root)->_data << endl;
    cout << "max = " << max(root)->_data << endl;
    cout << "sum = " << sum(root) << endl;
    return 0;
}

void DFT(Tree* tmp) {
    stack<Tree*> stack;
    stack.push(tmp);
    
    if (!stack.empty()) {
        cout << stack.top()->_data << " ";
        stack.pop();
    }
    if (tmp->_left != NULL) {
        DFT(tmp->_left);
    }
    if (tmp->_right != NULL) {
        DFT(tmp->_right);
    }
}

void BFT(Tree* root) {
    queue<Tree*> q;
    q.push(root);

    while (!q.empty()) {
        Tree* tmp = q.front();
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

Tree* insert(Tree* root, int data) {
    Tree* newNode = new Tree(data);
    if (root == NULL) {
        root = newNode;
        return root;
    } 
    queue <Tree*> q;
    q.push(root);
    while (!q.empty()) {
        Tree* tmp = q.front();
        q.pop();

        if (tmp->_left == NULL) {
            tmp->_left = newNode;
            return root;
        } else {
            q.push(tmp->_left);
        }
        if (tmp->_right == NULL) {
            tmp->_right = newNode;
            return root;
        } else {
            q.push(tmp->_right);
        }
    }
    return root;
}

Tree* min(Tree* root) {
    queue<Tree*> q;
    q.push(root);
    Tree* min = root;
    while (!q.empty()) {
        Tree* tmp = q.front();
        q.pop();
        if(tmp->_data < min->_data) {
            min = tmp;
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

Tree* max(Tree* root) {
    queue<Tree*> q;
    q.push(root);
    Tree* max = root;
    while (!q.empty()) {
        Tree* tmp = q.front();
        q.pop();
        if(tmp->_data > max->_data) {
            max = tmp;
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

int sum(Tree* root)
{
    int sum = 0;
    queue<Tree*> q;
    q.push(root);
    Tree* max = root;
    while (!q.empty()) {
        Tree* tmp = q.front();
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