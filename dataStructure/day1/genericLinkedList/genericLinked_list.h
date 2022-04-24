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
	int count;
    Node<T> *head,*tail;
public:
    Linked_list();
	~Linked_list();
    Node<T>* getHead();
	template<class Type>
    friend ostream& operator << (ostream &out, const Linked_list<Type>& );
    void Add(T n);
    void AddAt(int index, T value);
    void RemoveAt(int index);
    void Remove();
    Node<T>* GetElementAt(int index);
    T GetDataElementAt(int index);
    int Count();
};

#endif
