#ifndef GenericLinkedList
#define GenericLinkedList

using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template<class T>
class Linked_list
{
private:
    Node<T> *head,*tail;
public:
    Linked_list();
    Node<T>* getHead();
    friend ostream& operator << (ostream &out, const Linked_list<T>& );
    void Add(T n);
    void AddAt(Node<T> *a, T value);
    void RemoveAt(Node<T> *before_del);
    void Remove();
    T GetElementAt(int index);
    int Count();
};

#endif