#ifndef SLLNODE_H
#define SLLNODE_H

template <typename T>
class DLLNode {
// T() - default template value
public:
    SLLNode(const T& d = T(), DLLNode<T> *p = nullptr; DLLNode<T> *n = nullptr) {
        data = d;
        prev = p;
        next = n;
    }

    T data;
    DLLNode<T> *next;  // pointer to the next node
    DLLNode<T> *prev;   // pointer to the previous node
};

#endif

// to update data in one of the nodes, n1->next->data = 100;