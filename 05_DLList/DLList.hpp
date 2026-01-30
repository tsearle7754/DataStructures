#ifndef DLLIST_H
#define DLLIST_H
#include "DLLNode.hpp"

template <typename T>
class DLList {
public:
    // no arg constructor
    DLList();

    // TODO
    // copy constructor
    DLList(const DLList<T>& other);

    // assignment operator
    // SLList<T>& operator=(const SLList<T>& other);
    // deallocate memory from first then copy in all elements from the second into the first

    // destructor
    //~SLList();

    bool empty() const; // returns true if the list is empty
    // visualize where you are, where to link - draw


    // unsigned size() const;  // return size of list
    // bool empty() const;     // returns true if list is empty
    void push_front(const T& value);     // inserts the new node at the beginning
    void print() const;     // print the list
    void pop_back();

    bool empty() const; // returns true if the list is empty

    // TODO
    // void push_back(const T& val);   // insert the new node at the end
    // iterate through until you hit nullptr then push new node?
    // check empty, else assign pointer to head, find last node in list, set cur->next, increment size

    // void pop_front();   // remove the first element (node)
    // void clear();   // clear the list

    // TODO
    // void pop_back();    // remove last element(node)
      
private:
    DLLNode<T>* head;  // pointer to first node
    DLLNode<T>* tail;  // pointer to last node
    unsigned list_size;
};


#endif

// Sentinel nodes: two specific nodes, one at the head and one at the tail, that 
// to insert, point head of new node to head, then have that head point back. repeat for tail.
