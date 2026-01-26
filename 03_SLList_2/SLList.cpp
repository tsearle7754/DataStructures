#include "SLList.hpp"
#include <iostream>
using namespace std;

SLList::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

SLList::SLList(const SLList& other) {
    
}

SLList::~SLList() {
    clear();
}

unsigned SLList::size() const {
    return list_size;
}

bool SLList::empty() const {
    return (size() == 0);
}

void SLList::push_front(int val) {
    // add new node to beginning
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;

    // alternative method
    head = new SLLNode(val, head);      // creating new node, adding value, assign "head" as next for new node, then assign that to the head


    // increase list size
    list_size++;

    if (size() == 1) {
        tail = head;
    }
}

void SLList::push_back(int val) {
    if (empty()) {
        push_front(val);
        return;
    }
    tail->next = new SLLNode(val);    // add the node to the end
    tail = tail->next;  // move the tail

    list_size++;
}

void SLList::print() const {
    cout << "{ ";

    SLLNode* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->next) {
            cout << " -> ";
        }
        cur = cur->next;    // goes to the next node
    }
    cout << " }\n";
}

void SLList::pop_front() {
    // must deallocate address to avoid memory leak, decrement size, and change head
    if (!empty()) {
        SLLNode* old_head = head;
        head = head->next;

        delete old_head;    // free the memory

        list_size--;
        if (empty()) {
            tail = head;
        }
    }
}

void SLList::clear() {
    while (!empty()) {
        pop_front();
    }
}

// Node has data and next, list has head and size

// #1
// SLList l;
// l.push_front(...);
// repeat 23 times
// cout << l.size();

// #2
// SLList l;
// l.head->next->data;

// #3
// 
