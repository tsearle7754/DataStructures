#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include "HashNode.hpp"
#include <vector>


template <typename K, typename V>
class HashMap {
public:
    

private:
    std::vector<HashNode<K, V>*> data;
    int n;  // size of the table

};

#endif