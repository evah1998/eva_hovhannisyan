#include "deque.h"

Deque::~Deque() {
    _dequeContainer.~LinkedList();
}

bool Deque::isEmpty() {
    return _dequeContainer.Count() == 0;
}

void Deque::PushBack(int value) {
    _dequeContainer.Add(value);
}

void Deque::PushFront(int value) {
    _dequeContainer.AddAt(0, value);
}

int Deque::PopFront() {
    int temp = _dequeContainer.GetDataElementAt(0);
    _dequeContainer.RemoveAt(0);
    return temp;
}

int Deque::PopBack() {
    int temp = _dequeContainer.GetDataElementAt(_dequeContainer.Count() - 1);
    _dequeContainer.RemoveLast();
    return temp;
}

ostream& operator << (ostream &out, const Deque& deque) {
    return out << deque._dequeContainer;
}