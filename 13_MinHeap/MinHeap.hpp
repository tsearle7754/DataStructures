#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <vector>

template <typename T>
class MinHeap {
public:
    // constructors
    MinHeap();
    MinHeap(const std::vector<T>& v);

    void insert(const T& val);
    void print() const;

    T deleteMin();
private:
    std::vector<T> data;

    void percolateUp();
    void percolateDown(int i = 0);  // can use to heapify now
    int getLeftKidIndex(int i);
    int getRightKidIndex(int i);
    int getParentIndex(int i);
    int getLastWithKidsIndex();     // size / 2 - 1

    void heapify();
};

#endif