#include "BST.hpp"

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }

    // iterative approach
    BTNode<T>* cur = root;
    BTNode<T>* prev = root;
    while (cur) {
        prev = cur;
        if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    if (prev->data > val) {
        prev->left = new BTNode<T>(val);
    }
    else {
        prev->right = new BTNode<T>(val);
    }
}

template <typename T>       // will print tree in ascending order, from smallest to biggest
void BST<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << " ]\n";
}

template <typename T>
void BST<T>::inorder(BTNode<T>* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}

template <typename T>
bool BST<T>::isFullTree() const {
    // need helper function to traverse through tree
    return isFullTree(root);
}

// helper function
template <typename T>
bool BST<T>::isFullTree(const BTNode<T>* node) const {
    if (!node) {
        return true;
    }
    if (node.hasOneCild()) {
        return false;
    }
    return isFullTree(node->left) && isFullTree(node->right);
}

template <typename T>
BTNode<T>* BST<T>::search(const T& val) const {
    BTNode<T>* cur = root;

    while (cur) {
        if (cur->data == val) {     // found value
            return cur;
        }
        else if (cur->data > val) {      // value is less than, go left
            cur = cur->left;
        }
        else {
            cur = cur->right;       // value is greater than, go right
        }
    }
    return nullptr;     // if never found
}