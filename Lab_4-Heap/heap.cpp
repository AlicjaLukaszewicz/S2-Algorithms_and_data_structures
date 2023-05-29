#include "Heap.h"

Heap::~Heap() {
    vector.deleteObjects();
}

void Heap::push(Person& person) {
    if (size() == 0) {
        vector.push_back(person);
        return;

    }

    vector.push_back(person);
    int parent = vector.size() / 2 - 1;
    int child = size() - 1;
    while (true) {
        if (!(vector[parent] > vector[child]))
            return;
        else
            std::swap(vector[parent], vector[child]);
        child = parent;
        parent = (parent - 1) / 2;

    }
}

void Heap::heapify(int index) {
    int L = (index + 1) * 2 - 1;
    int R = (index + 1) * 2;
    int maxps;
    if (L < size() && vector[L] < vector[index])
        maxps = L;
    else
        maxps = index;
    if (R < size() && vector[R] < vector[maxps])
        maxps = R;
    if (maxps != index) {
        std::swap(vector[index], vector[maxps]);
        heapify(maxps);

    }
}

Person Heap::pop() {
    int last = vector.size() - 1;
    std::swap(vector[0], vector[last]);
    Person returnValue = vector.pop_back();

    heapify(0);
    return returnValue;
}

void Heap::print() const {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << std::endl;

    }
    std::cout << std::endl;
}

int Heap::size() const {
    return vector.size();
}

void Heap::buildHeap() {
    int first = size() / 2 - 1;

    for (int i = first; i >= 0; i--) {
        heapify(i);

    }
}

void Heap::printRoot() {
    std::cout << vector[0] << std::endl;
}
