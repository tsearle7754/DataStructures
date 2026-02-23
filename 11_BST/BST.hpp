#ifndef BST_H
#define BST_H
#include "BTNode.hpp"

template <typename T>
class BST {
public:
    BST();

    bool empty() const;
    void insert(const T& val);

    // traversals of the tree
    void inorder() const;   // standard traversal, in order

private:
    void inorder(BTNode<T>* node) const;

    BTNode<T>* root;

};
#endif