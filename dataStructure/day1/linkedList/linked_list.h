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
	int count;
    Node *head,*tail;
public:
    Linked_list();
	~Linked_list();
    Node* getHead();
    friend ostream& operator << (ostream &out, const Linked_list&);
    void Add(int n);
    void AddAt(int index, int value);
    void RemoveAt(int index);
    void Remove();
    Node* GetElementAt(int index);
    int GetDataElementAt(int index);
    int Count();
};

#endif
