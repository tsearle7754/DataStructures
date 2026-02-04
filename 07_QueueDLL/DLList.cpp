#include "DLList.hpp"
#include <iostream>

template <typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>;   // sentinel head node
    tail = new DLLNode<T>;   // sentinel tail node
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

template <typename T>
void DLList<T>::push_front(const T& val) {
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;    // links the one after to the new one

    list_size++;
}

template <typename T>
void DLList<T>::print() const {
    DLLNode<T>* cur = head->next;
    while (cur != tail) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }

    std::cout << std::endl;
}

template <typename T>
void DLList<T>::pop_back() {
    if (!empty()) {
        DLLNode<T>* to_delete = tail->prev;
        tail->prev = to_delete->prev;
        tail->prev->next = tail;

        list_size--;
        delete to_delete;
    }

}

template <typename T>
void DLList<T>::pop_front() {
    if (head-> != tail) {
        DLLNode<T>* to_delete = head->next; // pointer to first real node
        head->next = to_delete->next;   // assign to second node
        head->next->prev = head;    // link back to head
        delete to_delete;
        list_size--;
    }
}

template <typename T>
void DLList<T>::print_backwards() const {
    DLList<T>* cur = tail->next;    // first real node
    while (cur != head) {
        std::cout << cur->data << " -> ";
        cur = cur->prev;        // from back to front
    }
    std::cout << std::endl;
}

template <typename T>
void DLList<T>::push_back(const T&) {
    DLLNode<T>* new_node = new DLLNode<T>(val, tail->prev, tail);   // new node at end
    tail->prev->next = new_node;
    tail->prev = new_node;
    list_size++;
}