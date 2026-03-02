#include "BTNode.hpp"
#include "BST.hpp"
#include "BST.cpp"

int main(void) {

    BST<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);

    tree.print();       // new print function (mar 2nd)

    tree.deleteNode(2);
    tree.print();
    tree.deleteNode(3);
    tree.print();

    // TODO - MAKE IT WORK

    // TODO test isFullTree
    // TODO search_parent       - return the address of the parent of the node of the value provided (search, then look for root)


    BTNode<int>*node = tree.search(2);
    if (node) {
        std::cout << "Found" << std:: endl;
    }
    else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}