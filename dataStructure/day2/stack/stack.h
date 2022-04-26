#ifndef STACK_H
#define STACK_H

#include "../../day1/linkedList/linkedList.h"

class Stack {
    private:
        LinkedList _stackContainer;
    public:
        Stack() = default;
        ~Stack() = default;
        bool isEmpty();
        void Push(int);
        int Pop();
        int Peek();
        friend ostream& operator << (ostream &out, const Stack&);
};

#endif
