#ifndef QUEUE_H
#define QUEUE_H

#include "../linkedList/linkedList.h"

class Queue {
    private:
        LinkedList _queueContainer;
    public:
        Queue() = default;
        ~Queue();
        bool isEmpty();
        void PushBack(int);
        int PopFront();
        friend ostream& operator << (ostream &out, const Queue&);
};

#endif