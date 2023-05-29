#ifndef WICZENIE_NODE_H
#define WICZENIE_NODE_H

class Node {
public:
    int key;
    Node* next;

    Node();
    Node(int value);
    ~Node() = default;
};

#endif //WICZENIE_NODE_H