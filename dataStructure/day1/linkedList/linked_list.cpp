#include <iostream>
#include "linked_list.h"

using namespace std;

Linked_list::Linked_list()
{
	count = 0;
    head = NULL;
    tail = NULL;
}

Node* Linked_list::getHead()
{
    return head;
}

void Linked_list::Add(int n)
{
    Node *tmp = new Node;
    tmp->data = n;
    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
	++count;
}

ostream& operator << (ostream &out, const Linked_list& a) 
{
    Node *tmp;
    tmp = a.head;
    while (tmp != NULL)
    {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}

void Linked_list::AddAt(int index, int value)
{
	Node* prev = GetElementAt(index - 1);
    Node* p = new Node;
    p->data = value;
    p->next = prev->next;
    prev->next = p;
	++count;
}

void Linked_list::RemoveAt(int index)
{
	Node* prev = GetElementAt(index - 1);
    Node* temp;
    temp = prev->next;
    prev->next = temp->next;
    delete temp;
	--count;
}

void Linked_list::Remove()
{
    Node *tmp;
    tmp = head;
    while (tmp->next != tail)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    delete tail;
    tail = tmp;
	--count;
}

Node* Linked_list::GetElementAt(int index) {
    Node* tmp = head;
    for (int i = 1; i < index; ++i) {
        tmp = tmp->next;
    }
    return tmp;
}

int Linked_list::GetDataElementAt(int index) {
    Node* tmp ;
	tmp = GetElementAt(index); 
    return tmp->data;
}

int Linked_list::Count() {
    return count;
}

Linked_list::~Linked_list() {
    Node* current_node = head;
    Node* next = NULL;
    while (current_node) {
        next = current_node->next;
        delete current_node;
        current_node = next;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}
