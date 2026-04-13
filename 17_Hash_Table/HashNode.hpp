#ifndef HASHNNODE_HPP
#define HASHNODe_HPP

template <typename K, typename V>   // for the search code
class HashNode {
public:
    HashNode(const K& key, const V& value): key(key), value(value) {};

    K key;
    V value;

private:

};

#endif