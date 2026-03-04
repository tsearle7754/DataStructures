#include "BTNode.hpp"
#include "BST.hpp"
#include "BST.cpp"

int main(void) {

    BST<int> tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);


    tree.print();       // new print function (mar 2nd)

    // TODO check with search as an argument (tree.search(2))   - will have to make non constant because passing a const thing into non const
    BTNode<int>* node = tree.search(2);
    tree.rotateRight(node);
    tree.print();

    // where did 1 go??


    // TODO search_parent       - return the address of the parent of the node of the value provided (search, then look for root)

/*
BTNode<int>*node = tree.search(2);
if (node) {
    std::cout << "Found" << std:: endl;
}
else {
    std::cout << "Not Found" << std::endl;
}
*/

    return 0;
}