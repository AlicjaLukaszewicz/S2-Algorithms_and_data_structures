#ifndef HEAPS_VECTOR_H
#define HEAPS_VECTOR_H
#include <iostream>
#include "Person.h"

class Vector {
private:
    Person* arr;
    int capacity;
    int length;
public:
    Vector(int capacity = 32);

    void push_back(Person& person);
    Person pop_back();
    int size() const;
    Person& operator[](int index);
    Person& operator[](int index) const;
    void deleteObjects();

};


#endif //HEAPS_VECTOR_H