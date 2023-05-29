#include "Node.h"
#include <iostream>

Node::Node() {
    this->key = 0;
    this->next = nullptr;
}

Node::Node(int value) {
    this->key =value;
    this->next = nullptr;
}