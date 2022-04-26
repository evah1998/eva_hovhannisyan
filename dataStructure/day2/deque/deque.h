#ifndef DEQUE_H
#define DEQUE_H

#include "../../day1/linkedList/linkedList.h"

class Deque {
    private:
        LinkedList _dequeContainer;
    public:
        Deque() = default;
        ~Deque();
        bool isEmpty();
        void PushFront(int);
        void PushBack(int);
        int PopFront();
        int PopBack();
        friend ostream& operator << (ostream &out, const Deque&);
};

#endif