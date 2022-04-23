#include <iostream>
#include "genericLinked_list.h"

using namespace std;

template<class T>
Linked_list<T>::Linked_list()
{
    head = NULL;
    tail = NULL;
}

template<class T>
Node<T>* Linked_list<T>::getHead()
{
    return head;
}

template<class T>
void Linked_list<T>::Add(T n)
{
    Node<T> *tmp = new Node<T>;
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

template<class T>
ostream& operator << (ostream &out, const Linked_list<T>& a) 
{
    Node<T> *tmp;
    tmp = a.head;
    while (tmp != NULL)
    {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}

template<class T>
void Linked_list<T>::AddAt(Node<T> *a, T value)
{
    Node<T>* p = new Node<T>;
    p->data = value;
    p->next = a->next;
    a->next = p;
}

template<class T>
void Linked_list<T>::RemoveAt(Node<T> *before_del)
{
    Node<T>* temp;
    temp = before_del->next;
    before_del->next = temp->next;
    delete temp;
}

template<class T>
void Linked_list<T>::Remove()
{
    Node<T> *tmp;
    tmp = head;
    while (tmp->next != tail)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    delete tail;
    tail = tmp;
}

template<class T>
T Linked_list<T>::GetElementAt(int index) {
    Node<T>* tmp = head;
    for (int i = 1; i < index; ++i) {
        tmp = tmp->next;
    }
    return tmp->data;
}

template<class T>
int Linked_list<T>::Count() {
    Node<T> *tmp = head;
    int count = 1;
    while (tmp != tail)
    {
        tmp = tmp->next;
        ++count;
    }
    return count;
}