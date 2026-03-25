#ifndef TRIENODE_H
#define TIRENODE_H
#include <iostream>

#define ALPHABET_SIZE 26

class TrieNode {
public:
    TrieNode() : end_of_word(false) {
        // TODO
        // initialize all children with nullptr
    }

    TrieNode* children[ALPHABET_SIZE];
    bool end_of_word;

private:

};

#endif