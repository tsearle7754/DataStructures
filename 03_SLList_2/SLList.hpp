#ifndef SLLIST_H
#define SLLIST_H
#include "SLLNode.hpp"

class SLList {
public:
    // no arg constructor
    SLList();

    // TODO
    // copy constructor
    SLList(const SLList& other);

    // assignment operator
    SLList& operator=(const SLList& other);
    // deallocate memory from first then copy in all elements from the second into the first

    // destructor
    ~SLList();

    unsigned size() const;  // return size of list
    bool empty() const;     // returns true if list is empty
    void push_front(int value);     // inserts the new node at the beginning
    void print() const;     // print the list

    // TODO
    void push_back(int val);   // insert the new node at the end
    // iterate through until you hit nullptr then push new node?

    // check empty, else assign pointer to head, find last node in list, set cur->next, increment size

    void pop_front();   // remove the first element (node)
    void clear();   // clear the list

    // TODO
    void pop_back();    // remove last element(node)
      
private:
    SLLNode* head;  // pointer to first node
    SLLNode* tail;  // pointer to last node
    unsigned list_size;
};


#endif