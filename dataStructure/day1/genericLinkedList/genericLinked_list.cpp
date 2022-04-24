#include <iostream>
#include "genericLinked_list.h"

using namespace std;

template<class T>
Linked_list<T>::Linked_list()
{
	count = 0;
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
	++count;
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
void Linked_list<T>::AddAt(int index, T value)
{
	Node<T>* prev = GetElementAt(index - 1);
    Node<T>* p = new Node<T>;
    p->data = value;
    p->next = prev->next;
    prev->next = p;
	++count;
}

template<class T>
void Linked_list<T>::RemoveAt(int index)
{
	Node<T>* prev = GetElementAt(index - 1);
    Node<T>* temp;
    temp = prev->next;
    prev->next = temp->next;
    delete temp;
	--count;
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
	--count;
}

template<class T>
Node<T>* Linked_list<T>::GetElementAt(int index)
{
    Node<T>* tmp = head;
    for (int i = 1; i < index; ++i) {
        tmp = tmp->next;
    }
    return tmp;
}

template<class T>
T Linked_list<T>::GetDataElementAt(int index)
{
    Node<T>* tmp;
    tmp = GetElementAt(index);
    return tmp->data;
}

template<class T>
int Linked_list<T>::Count() {
    return count;
}

template<typename T>
Linked_list<T>::~Linked_list() {
    Node<T>* current_node = head;
    Node<T>* next = NULL;
    while (current_node) {
        next = current_node-> next;
        delete current_node;
        current_node = next;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}

int main()
{
    Linked_list <int> a;
    int number;
    cout << "Make a list of 20 element\n";
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        number = 1 + rand() % 10;
        a.Add(number);
    }
    cout << a;

    cout << "Add an element after the 4-th element\n";
    a.AddAt(5, 10);
    cout << a;

    cout << "Delete element 3-rd\n";
    a.RemoveAt(3);
    cout << a;

    cout << "Add an element from the end\n";
    a.Add(12);
    cout << a;

    cout << "Delete the last element\n";
    a.Remove();
    cout << a;

    cout << "The 5-th element = " << a.GetDataElementAt(5) << endl;

    cout << "Count = " << a.Count() << endl;
	return 0;
}
