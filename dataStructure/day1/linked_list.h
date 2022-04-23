#ifndef LinkedList
#define LinkedList

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Linked_list
{
private:
    Node *head,*tail;
public:
    Linked_list();
    Node* getHead();
    friend ostream& operator << (ostream &out, const Linked_list&);
    void Add(int n);
    void AddAt(Node *a, int value);
    void RemoveAt(Node *before_del);
    void Remove();
    int GetElementAt(int index);
    int Count();
};

#endif