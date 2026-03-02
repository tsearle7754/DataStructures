#ifndef BST_H
#define BST_H
#include "BTNode.hpp"
#include <iostream>
#include <string>

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

    void deleteNode(const T& val);
    void print() const;     // will use recursion and a helper function
    BTNode<T>* getMinNode() const;
    BTNode<T>* searchParent(const T& val) const;

    void insert_recursive(const T& val);
    BTNode<T>* insert_recursive(BTNode<T>* node, const T& val);

    // make deleteLeaf and deleteWithOneChild private

private:
    void inorder(BTNode<T>* node) const;
    // helper function
    bool isFullTree(const BTNode<T>* node) const;

    void print(const std::string& prefix, BTNode<T>* node, bool isRight) const;

    void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);

    void deleteNodeWithTwoChildren(BTNode<T>* node);

    BTNode<T>* root;

};
#endif