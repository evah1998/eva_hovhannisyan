#include "linkedList.h"

LinkedList::LinkedList()
{
	_count = 0;
    _head = NULL;
    _tail = NULL;
}

void LinkedList::Add(int value)
{
    Node *tmp = new Node;
    tmp->data = value;
    tmp->next = NULL;

    if(_head == NULL)
    {
        _head = tmp;
        _tail = tmp;
    }
    else
    {
        _tail->next = tmp;
        _tail = _tail->next;
    }
	++_count;
}

void LinkedList::AddAt(int index, int value)
{
	Node* prev = GetElementAt(index - 1);
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = prev->next;
    prev->next = newNode;
	++_count;
}

void LinkedList::RemoveAt(int index)
{
    if (Count() > 1 && index < Count()) {
		if (index > 0) {
        	Node* prev = GetElementAt(index - 1);
        	Node* temp = prev->next;
        	prev->next = temp->next;
        	delete temp;
        	--_count;
		} else if (index == 0) {
			Node* tmp = _head->next;
			delete _head;
			_head = tmp;
		}
    } else {
        _count = 0;
        _head = NULL;
        _tail = NULL;
    }
}

void LinkedList::RemoveLast()
{
    RemoveAt(Count() - 1);
}

void LinkedList::RemoveAll()
{
    while (_count > 0)
    {
        RemoveLast();
    }
}

Node* LinkedList::GetElementAt(int index)
{
    Node* tmp = _head;
    while (index--)
    {
        tmp = tmp->next;
    }
    return tmp;
}

int LinkedList::GetDataElementAt(int index) 
{
    return GetElementAt(index)->data;
}

int LinkedList::Count() 
{
    return _count;
}

LinkedList::~LinkedList() 
{
    RemoveAll();
}

ostream& operator << (ostream &out, const LinkedList& a) 
{
    Node *tmp;
    tmp = a._head;
    while (tmp != NULL)
    {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}
