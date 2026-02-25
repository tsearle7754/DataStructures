#ifndef BST_H
#define BST_H
#include "BTNode.hpp"
#include <iostream>

template <typename T>
class BST {
public:
    BST();

    bool empty() const;
    void insert(const T& val);

    // traversals of the tree
    void inorder() const;   // standard traversal, in order
    // TODO
    void preorder() const;
    void postorder() const;

    bool isFullTree() const;

    BTNode<T>* search(const T& val) const;

private:
    void inorder(BTNode<T>* node) const;
    // helper function
    bool isFullTree(const BTNode<T>* node) const;

    BTNode<T>* root;

};
#endif