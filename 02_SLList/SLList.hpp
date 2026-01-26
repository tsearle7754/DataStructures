#ifndef SLLIST_H
#define SLLIST_H
#include "SLLNode.hpp"

class SLList {
public:
    // no arg constructor
    SLList();

    unsigned size() const;  // return size of list
    bool empty() const;     // returns true if list is empty
    void push_front(int value);     // inserts the new node at the beginning
    void print() const;     // print the list

    // TODO
    void push_back(int val){    // insert the new node at the end
    // iterate through until you hit nullptr then push new node?

    // check empty, else assign pointer to head, find last node in list, set cur->next, increment size
        if (empty()) {
            head = new SLLNode(val);

        }

        else {
            SLList* l = new SLList;
        }
    }
private:
    SLLNode* head;
    unsigned list_size;
};


#endif