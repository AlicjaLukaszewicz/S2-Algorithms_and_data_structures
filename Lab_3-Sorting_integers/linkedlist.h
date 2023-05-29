#ifndef LISTWITHSORT_LINKEDLIST_H
#define LISTWITHSORT_LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList {
    Node* head;
    int size = 0;

    friend bool operator==(LinkedList list_one, LinkedList list_two);
    friend bool operator>(LinkedList list_one, LinkedList list_two);
public:
    LinkedList();
    void Print();
    void Insert(int index, int value);
    void Delete(int index);
    int getSize() const;
    int Search(int index);

    void DeleteNodeAtTheFront();
    void FreeUpMemory();

};

#endif //LISTWITHSORT_LINKEDLIST_H