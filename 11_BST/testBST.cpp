#include "BTNode.hpp"
#include "BST.hpp"
#include "BST.cpp"

int main(void) {
    BST<int> *tree;

    // TODO
    // insert random values, then print in order
    tree->insert(32);        // should be able to do so idk why it's not working
    tree->inorder();

    // tree.print();

    // TODO test isFullTree
    // TODO search_parent       - return the address of the parent of the node of the value provided (search, then look for root)


    BTNode<int>*node = tree->search(2);
    if (node) {
        std::cout << "Found" << std:: endl;
    }
    else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}