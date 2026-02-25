#ifndef BTNODE_H
#define BTNODE_H

template <typename T>
class BTNode {
public:
    BTNode(const T& val = T(), BTNode<T>* l = nullptr, BTNode<T>* r = nullptr)
        : data(val), left(l), right(r) {}

    bool isLeaf() const {
        return !left && !right;
    }

    bool hasOneChild() const {
        return !isLeaf() && !hasTwoChildren();      // exclusively one child
    }

    bool hasTwoChildren() const {
        return left && right;
    }

    T data;
    BTNode<T>* left;
    BTNode<T>* right;
};

#endif
