#include "Trie.hpp"
#include <string>
#include <iostream>
#include <cctype>

Trie::Trie() {
    root = new TrieNode();  // sentinel node
}

Trie::Trie(const std::vector<std::string>& v) {
    root = new TrieNode();
}

void Trie::insert(const std::string& s) {
    TrieNode* cur = root;   // start w/ root, iterate through string character by character

    for (char c : s) {
        if (!isalpha(c)) continue;

        int i = tolower(c) - 'a';    // find index by subtracting ASCII code
        if (!cur->children[i]) {    // create new path, does not exist
            cur->children[i] = new TrieNode();
        }
        cur = cur->children[i];  // then go to this path (new if created above, goes straight there if not)
    }
    cur->end_of_word = true;
}

bool Trie::search(const std::string& s) const {
    TrieNode* cur = root;

    for (char c : s) {
        int i = tolower(c) - 'a';   // find index, check if children are not nullptr
        if (!cur->children[i]) {
            return false;   // no such word
        }
        cur = cur->children[i]; // go on for all characters
    }
    return cur->end_of_word;
}

void Trie::print() const {
    std::string word;
    print(root, word);  // need helper function
}


void Trie::print(const TrieNode* node, std::string& word) const {
    if (!node) return;  // base case

    static int lineNumber = 1;
    if (node->end_of_word) {
        std::cout << lineNumber << ": " << word << std::endl;
        lineNumber++;
    }
    // consider all children for all paths - check all children
    // if child exists, add character to the word - recursion
    // remove the character from the word
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char c = 'a' + i;
            // add character to word
            word.push_back(c);
            print(node->children[i], word);     // call recursively to print
            // remove character from word
            word.pop_back();
        }
    }
    if (word.empty()) {
        lineNumber = 1;
    }
}
