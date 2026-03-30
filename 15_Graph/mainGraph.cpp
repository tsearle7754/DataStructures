#include "Graph.hpp"
#include <string>

int main(void) {
    Graph<std::string> knowlegde;

    knowlegde.insertVertex("AVL");
    knowlegde.insertVertex("BST");
    knowlegde.insertVertex("Trie");
    knowlegde.insertVertex("Heap");

    knowlegde.insertEdge("BST", "AVL");
    knowlegde.insertEdge("BST", "Trie");
    knowlegde.insertEdge("BST", "Heap");

    knowlegde.print();

    return 0;
}