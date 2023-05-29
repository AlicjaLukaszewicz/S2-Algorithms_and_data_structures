#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    Node* newNode = new Node();
    this->head = newNode;
}
void LinkedList::Print() {
    if (head->next != nullptr) {
        Node* temp = head->next;
        std::cout << "LinkedList: ";
        while (temp != nullptr) {
            std::cout << temp->key << " ";
            temp = temp->next;
        
}
    
} else std::cout << "Empty";
    std::cout<<std::endl;
}

void LinkedList::i(int index, int value) {
    size++;
    Node* temp = new Node();
    temp->key = value;
    temp->next = nullptr;

    if (this->head == nullptr) {
        if (index != 0) {
            return;
        
} else {
            this->head = temp;
        
}
    
}
    if (head != nullptr && index == 0) {
        temp->next = this->head;
        this->head = temp;
        return;
    
}
    Node* current = this->head;
    Node* previous = nullptr;

    int i = 0;
    while (i < index) {
        previous = current;
        current = current->next;

        if (current == nullptr) {
            break;
        
}
        i++;
    
}
    temp->next = current;
    previous->next = temp;
}


int LinkedList::g(int index) {
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    
}
    return temp->key;
}

void LinkedList::DeleteNodeAtTheFront() {
    if (head->next != nullptr) {
        Node* nodeToDelete = head->next;
        if (head->next->next != nullptr)
            head->next=head->next->next;
        delete nodeToDelete;
        this->size--;
    
}
}

int LinkedList::getSize() const {
    return size;
}

void LinkedList::d(int index) {
    this->size--;

    if (index == 0 && head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    
} else {
        Node* temp = head->next;
        for(int i = 1; i < index-1; i++) {
            if(temp != nullptr) {
                temp = temp->next;
            
}
        
}
        if(temp != nullptr && temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        
}
    
}
}

void LinkedList::q() {
    int listSize = getSize();
    for (int i = 0; i < listSize; ++i) {
        this->DeleteNodeAtTheFront();
    
}
    delete head;
}


