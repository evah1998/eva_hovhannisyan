#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string.h>

using namespace std;

class Node {
    public:
        string _key;
        string _data;
        Node *_next;
        ~Node();
};

class LinkedList {
    public:
		int _count;
        Node * _head;
        LinkedList();
		~LinkedList();
};

class HashTable {
    private:
        int _arrSize;
        LinkedList *_arr;
    public:
        HashTable(int);
        int hashFunction(string&);
        void insert(string, string);
        void remove(string);
        string search(string);
    	friend ostream& operator << (ostream &out, const HashTable&);
        ~HashTable();
};

Node::~Node() {
    delete _next;
}

LinkedList::LinkedList() {
    _count = 0;
    _head = NULL;
}

LinkedList::~LinkedList() {
    delete _head;
}

HashTable::HashTable(int size) {
    _arrSize = size;
    _arr = new LinkedList[_arrSize];
    
    for (int i = 0; i < _arrSize; ++i) {
        _arr[i]._head = NULL;
    }
}

HashTable::~HashTable() {
    delete[] _arr;
}

int HashTable::hashFunction(string& s) {
	int hashVal = 0;
    int ascii;
	for(int i = 0; i < s.size(); ++i) {
		ascii = s[i] > 96 ? s[i] - 96 : s[i] - 64;
		hashVal = (hashVal * 32 + ascii) % _arrSize;
	}
	return hashVal;
}


void HashTable::insert(string key, string value) {
    int index = hashFunction(key);
    Node* newNode = new Node;
    newNode->_data = value;
    newNode->_key = key;
    if (_arr[index]._head == NULL) {
        _arr[index]._head = newNode;
    } else {
        newNode->_next = _arr[index]._head;
        _arr[index]._head = newNode;
    }
	++_arr[index]._count;
}

void HashTable::remove(string key) {
    int index = hashFunction(key);
    Node *prev = _arr[index]._head;
    if (prev->_key == key) {
        _arr[index]._head = prev->_next;
        delete prev;
        return;
    }
    while (prev->_next) {
        if (prev->_next->_key == key) {
            Node* tmp = prev->_next;
            prev->_next = tmp->_next;
            delete tmp;
            return;
        }
        prev = prev->_next;
    }
    --_arr[index]._count;
}

string HashTable::search(string key) {
    int index = hashFunction(key);
    Node *tmp = _arr[index]._head;
    if (_arr[index]._head == NULL) {
       return " arr[" + to_string(index) + "] is empty";
    }
    while (tmp) {
        if (tmp->_key == key) {
            return tmp->_data;
        }
        tmp = tmp->_next;
    }
    return "key not found";
}

ostream& operator << (ostream &out, const HashTable& a) {
    Node *tmp;
    for (int i = 0; i < a._arrSize; ++i) {
        tmp = a._arr[i]._head;
        while (tmp != NULL) {
            out << tmp->_data << " ";
            tmp = tmp->_next;
        }
    }
    return out;
}

#endif