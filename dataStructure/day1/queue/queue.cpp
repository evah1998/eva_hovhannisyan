#include "queue.h"
Queue::~Queue() {
    _queueContainer.~LinkedList();
}

bool Queue::isEmpty() {
    return _queueContainer.Count() == 0;
}

void Queue::PushBack(int value) {
    _queueContainer.Add(value);
}

int Queue::PopFront() {
    int temp = _queueContainer.GetDataElementAt(0);
    _queueContainer.RemoveAt(0);
    return temp;
}

ostream& operator << (ostream &out, const Queue& queue) {
    return out << queue._queueContainer;
}