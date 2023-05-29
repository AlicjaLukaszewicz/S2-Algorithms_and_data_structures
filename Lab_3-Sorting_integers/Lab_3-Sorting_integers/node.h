#ifndef LISTWITHSORT_NODE_H
#define LISTWITHSORT_NODE_H


class Node {
public:
    int key;
    Node* next;

    Node();
    Node(int value);
    ~Node() = default;
};


#endif //LISTWITHSORT_NODE_H