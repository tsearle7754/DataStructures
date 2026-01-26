#include "SLList.hpp"
#include <iostream>
using namespace std;

SLList::SLList() {
    head = nullptr;
    list_size = 0;
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
