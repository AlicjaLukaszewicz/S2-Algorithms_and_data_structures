#ifndef HEAPS_HEAP_H
#define HEAPS_HEAP_H
#include "Vector.h"

class Heap {
    Vector vector;
public:

    void push(Person& person);
    void heapify(int index);
    Person pop();
    void print() const;
    int size() const;
    void buildHeap();
    void printRoot();
    ~Heap();
};


#endif //HEAPS_HEAP_H