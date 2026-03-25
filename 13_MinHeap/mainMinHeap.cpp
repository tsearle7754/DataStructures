#include "MinHeap.hpp"
#include "MinHeap.cpp"
#include <cstdlib>
#include <vector>

int main(void) {
    MinHeap<int> heap;
    std::vector<int> v;

    for (int i = 0; i < 10; i++) {
        int num = rand() % 1000;
        heap.insert(num);
        v.push_back(num);
    }

    MinHeap<int> heap2(v);

    heap.print();
    std::cout << "\n----------\n";
    heap2.print();

    // for(int i = 0; i < 10; i++) {
        // heap.deleteMin();
        // heap.print();
        // std::cout << "\n--------------------\n";
    // }

    return 0;
}