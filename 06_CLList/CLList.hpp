#ifndef CLLIST_H
#define CLLIST_H
#include "DLLNode.hpp"

template <typename T>
class CLList {
public:

    CLList();

    void push_front(const T& value);
    void print() const;
    void print_backwards() const;
    bool empty() const;

    // todo
    void push_back(const T& value);
    void pop_back();
    void pop_front();

private:
    DLLNode<T>* tail;
    unsigned list_size;
};

#endif