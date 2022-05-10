#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    public:
		int _count;
        Node * _head;
        Node * _tail;
        Node* GetElementAt(int index);
        LinkedList();
		~LinkedList();
    	void Add(int value);
    	void AddAt(int index, int value);
    	void RemoveAt(int index);
		void RemoveLast();
		void RemoveAll();
		int GetDataElementAt(int index);
		int Count();
		friend ostream& operator << (ostream &out, const LinkedList&);
};

#endif