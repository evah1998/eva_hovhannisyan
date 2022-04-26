#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

using namespace std;

class Vector {
    private:
        int* _arr;
        int _size;
        int _capacity;
        void IncreaseSize();

    public:
        Vector();
        ~Vector();
        void AddFront(int);
        void Add(int);
        void AddAt(int, int);
        void RemoveAt(int);
        void RemoveAll();
        friend ostream &operator << (ostream& out, const Vector&);
        int& operator[](int);

};

#endif