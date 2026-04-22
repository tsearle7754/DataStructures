#include "HashMap.hpp"
#include <iostream>

template <typename K, typename V>
HashMap<K, V>::HashMap(int size) : n(0) {
    data.resize(size, nullptr);

    deleted = new HashNode<K, V>(K(), V());     // will take whatever default value, use it in constructor, create node on heap and use that address to mark the deleted node
};

template <typename K, typename V>
bool HashMap<K, V>::empty() const {
    return n == 0;
}

template <typename K, typename V>
bool HashMap<K, V>::full() const {
    return n == data.size();
}

template <typename K, typename V>
int HashMap<K, V>::hash(const K& key) const {
    return key % data.size();
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    if (full()) return;

    // find hash
    int index = hash(key);

    while (data[index] && data[index] != deleted) {
        index = (index + 1) % data.size();  // go to the next position (allows the end to go to the front next for example)
    }

    // insert the node
    data[index] = new HashNode<K, V>(key, value);
    n++;
}

template <typename K, typename V>
void HashMap<K, V>::print() const {
    // if not null print key and value
    for (int i = 0; i < data.size(); i++) {
        std::cout << i << " ";
        if (data[i] == nullptr) {
            std::cout << "nullptr\n";
        }
        else if (data[i] == deleted) {
            std:: cout << "deleted\n";
        }
        else {
            std::cout << "{" << data[i]->key << ": " << data[i]->value << "}\n";
        }
    }
}

template <typename K, typename V>
int HashMap<K, V>::searchIndex(const K& key) const {
    // start searching from the hash of the key
    int counter = 0;
    int index = hash(key);

    // loop until we find an empty slot (nullptr) which means key not found
    // or we find the key itself
    while (data[index] != nullptr) {
        if (counter++ > data.size()) {  // gone through the whole thing - if we've looped all the way around, stop searching
            return -1;
        }

        // if the current node is not deleted and key matches, return index
        if (data[index]->key == key) {
            return index;  // key found at this index
        }

        // otherwise, move to the next slot (linear probing)
        index = (index + 1) % data.size();
    }

    // if we hit a nullptr, the key does not exist in the map
    return -1;  // -1 indicates key not found
}

template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    
}