#include "CLList.hpp"
#include "DLLNode.hpp"
#include <iostream>

template <typename T>
CLList<T>::CLList() {
    tail = nullptr;
    list_size = 0;
}

template <typename T>
void CLList<T>::push_front(const T& val) {
    if (empty()) {
        tail = new DLLNode<T>(val);
        tail->prev = tail;
        tail->next = tail;
    }
    else {
        DLLNode<T>* new_node = new DLLNode<T>(val, tail, tail->next);   // didn't link new node to tail or head correctly
        tail->next->prev = new_node;    // link head correctly
        tail->next = new_node;      // link tail correctly
    }
    
    list_size++;
}

template <typename T>
void CLList<T>::print() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail->next;
    do {
        std::cout << cur->data;
        if (cur != tail) { // not the last node
            std::cout << " -> ";
        }
        cur = cur->next;
    } while (cur != tail->next);
    
    std::cout << std::endl;
}

template <typename T>
void CLList<T>::print_backwards() const {
    if (empty()) {
        return;
    }
    DLLNode<T>* cur = tail;

    do {
        std::cout << cur->data;
        if (cur != tail->next) { // not the last node
            std::cout << " <- ";
        }
        cur = cur->prev;
    } while (cur != tail);
    
    std::cout << std::endl;
}


template <typename T>
bool CLList<T>::empty() const {
    return (list_size == 0);
}

template <typename T>
void CLList<T>::push_back(const T& val) {
    if (empty()) {
        tail = new DLLNode<T>(val);
        tail->prev = tail;
        tail->next = tail;
    }
    else {
        DLLNode<T>* new_node = new DLLNode<T>(val, tail, tail->next);     // link same way, but new_node becomes tail
        tail->next->prev = new_node;
        tail->next = new_node;
        tail = new_node;
    }
    list_size++;
}

template <typename T>
void CLList<T>::pop_front() {
    if(empty()) {
        return;
    }
    DLLNode<T>* head = tail->next;      // establish head node
    
    if(head == tail) {  // only one node
        delete head;
        tail = nullptr;
    } else {
        tail->next = head->next;   // update tail
        head->next->prev = tail;    // point head to tail
        delete head;
    }
    list_size--;
}

template <typename T>
void CLList<T>::pop_back() {
    if(empty()) {
        return;
    }
    DLLNode<T>* old_tail = tail;
    DLLNode<T>* head = tail->next;

    if(head == tail) {
        delete old_tail;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = old_tail->next;    // point new tail to head
        old_tail->next->prev = tail;
        delete old_tail;
    }
    list_size--;
}
