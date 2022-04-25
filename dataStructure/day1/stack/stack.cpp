#include "stack.h"

bool Stack::isEmpty() 
{
    return _stackContainer.Count() == 0;
}

void Stack::Push(int value)
{
    _stackContainer.Add(value);
}

int Stack::Pop()
{
    int top = Peek();
    _stackContainer.RemoveLast();
    return top;
}

int Stack::Peek()
{
    return _stackContainer.GetDataElementAt(_stackContainer.Count() - 1);
}

ostream& operator << (ostream &out, const Stack& stack) 
{
    return out << stack._stackContainer;
}
