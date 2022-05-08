#include <iostream>
#include "../day6/binary_tree.h"

using namespace std;

bool isTree (bool** arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int countRoot = 0;
        int countTrue = 0;
        for(int j = 0; j < size; j++) {
            if (arr[i][j]) countTrue++;
            if (arr[j][i] == 0) countRoot++;
            if (arr[i][j] == 1 && arr[j][i] == 1) return false;

        }
        if (countTrue > 2) return false;
        if (countRoot == size) {
            count++;
        }
        else if(countRoot < size - 1) return false;
    }
    if(count != 1) return false;
    return true;
}

int findRoot(bool** arr, int size) {
    for (int i = 0; i < size; i++) {
        int countRoot = 0;
        for(int j = 0; j < size; j++) {
            if (arr[j][i] == 0) countRoot++;
        }
        if (countRoot == size)
            return i;
    }
    return 0;
}

void addChild(Tree* root, bool** arr, int size, int j, Node* tmp) {
    int i = j;
    for (int j = 0; j < size; j++) {
        if(arr[i][j] == 1) {
            tmp = root->add(tmp, j);
            addChild(root, arr, size, j, tmp);
        }
    }
}

void createTree (bool** arr, int size) {
    Tree* root = new Tree(findRoot(arr, size));
    int j = findRoot(arr, size);
    Node* tmp = root->_root;
    addChild(root, arr, size, j, tmp);
    root->BFS();
    cout << endl;
}

int main() {
    int size;
	cout << "Input size\n";
	cin >> size;
	bool **arr = new bool*[size];
    cout << "Input 0 | 1 \n";
	for (bool **ptr = arr; ptr - arr < size; ptr++) {
		*ptr = new bool[size];
		for (bool *tmp = *ptr; tmp - *ptr < size; tmp++) {
			cin >> *tmp;
		}
	}

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

	if (isTree(arr, size)) {
        cout << "Is binary tree\n";
        createTree(arr, size);
    } else {
        cout << "Is not binary tree\n";
    }

    return 0;
}