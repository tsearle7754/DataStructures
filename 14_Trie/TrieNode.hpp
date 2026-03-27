#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP
#include <iostream>

#define ALPHABET_SIZE 26

class TrieNode {
public:
    TrieNode() : end_of_word(false) {
        // TODO
        // initialize all children with nullptr
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }

    TrieNode* children[ALPHABET_SIZE];
    bool end_of_word;

private:

};

#endif