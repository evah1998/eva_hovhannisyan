#include <iostream>
#include "linked_list.h"

using namespace std;

Linked_list::Linked_list()
{
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

void Linked_list::AddAt(Node *a, int value)
{
    Node* p = new Node;
    p->data = value;
    p->next = a->next;
    a->next = p;
}

void Linked_list::RemoveAt(Node *before_del)
{
    Node* temp;
    temp = before_del->next;
    before_del->next = temp->next;
    delete temp;
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
}

int Linked_list::GetElementAt(int index) {
    Node* tmp = head;
    for (int i = 1; i < index; ++i) {
        tmp = tmp->next;
    }
    return tmp->data;
}
int Linked_list::Count() {
    Node *tmp = head;
    int count = 1;
    while (tmp != tail)
    {
        tmp = tmp->next;
        ++count;
    }
    return count;
}