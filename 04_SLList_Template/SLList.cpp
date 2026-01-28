#include "SLList.hpp"
#include <iostream>
using namespace std;

template <typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

// TODO
template <typename T>
SLList<T>::SLList(const SLList<T>& other) {
    // initialize empty list, use push_back to fill in
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    SLLNode<T>* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }
}

template <typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other) {
    // account for if they're already equal
    if (this == &other) {
        return *this;
    }
    // clear whatever was there, use push_back to fill in and make equal
    clear();
    SLLNode<T>* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }
    return *this;
}

template <typename T>
SLList<T>::~SLList() {
    clear();
}

template <typename T>
unsigned SLList<T>::size() const {
    return list_size;
}

template <typename T>
bool SLList<T>::empty() const {
    return (size() == 0);
}

template <typename T>
void SLList<T>::push_front(const T& val) {
    // add new node to beginning
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;

    // alternative method
    head = new SLLNode<T>(val, head);      // creating new node, adding value, assign "head" as next for new node, then assign that to the head


    // increase list size
    list_size++;

    if (size() == 1) {
        tail = head;
    }
}

template <typename T>
void SLList<T>::push_back(const T& val) {
    if (empty()) {
        push_front(val);
        return;
    }
    tail->next = new SLLNode<T>(val);    // add the node to the end
    tail = tail->next;  // move the tail

    list_size++;
}

template <typename T>
void SLList<T>::print() const {
    cout << "{ ";

    SLLNode<T>* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->next) {
            cout << " -> ";
        }
        cur = cur->next;    // goes to the next node
    }
    cout << " }\n";
}

template <typename T>
void SLList<T>::pop_front() {
    // must deallocate address to avoid memory leak, decrement size, and change head
    if (!empty()) {
        SLLNode<T>* old_head = head;
        head = head->next;

        delete old_head;    // free the memory

        list_size--;
        if (empty()) {
            tail = head;
        }
    }
}

template <typename T>
void SLList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

// make sure to avoid memory leaks
template <typename T>
void SLList<T>::pop_back() {
    if (empty()) {
        return; // nothing to pop
    }

    if (head == tail) {
        // only one node in the list
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        // find node before tail
        SLLNode<T>* cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        delete tail;
        tail = cur;
        tail->next = nullptr;
    }

    list_size--;
}

// Node has data and next, list has head and size
