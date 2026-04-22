#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "HashNode.hpp"
#include <vector>


template <typename K, typename V>
class HashMap {
public:
    HashMap(int size = 31);
    
    // DO DECONSTRUCTOR
    ~HashMap();
    
    bool empty() const;
    bool full() const;

    void insert(const K& key, const V& value);
    void print() const;
    // TODO
    const V& search(const K& key) const;    // if key doesn't exist, throw exception. if exists, return reference to value

    void remove(const K& key);  // TODO

private:
    std::vector<HashNode<K, V>*> data;
    int n;  // number of records

    HashNode<K, V>* deleted;

    int hash(const K& key) const;

    // TODO
    int searchIndex(const K& key) const;

};

#include "HashMap.tpp"

#endif