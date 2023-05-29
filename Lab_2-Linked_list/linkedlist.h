#ifndef WICZENIE_LINKEDLIST_H
#define WICZENIE_LINKEDLIST_H
#include "Node.h"

class LinkedList {
    Node* head; //Wskaźnik na początek listy
    int size = 0;
public:
    LinkedList();
    void Print();
    void i(int index, int value);
    void DeleteNodeAtTheFront();
    void d(int index);
    void q();
    int getSize() const;
    int g(int index);
};


#endif //WICZENIE_LINKEDLIST_H