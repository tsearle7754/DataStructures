#include "CLList.hpp"
#include "CLList.cpp"

#include <iostream>

int main(void) {
    CLList<int> cl;
    cl.push_front(2);
    cl.push_front(1);
    cl.push_back(3);
    cl.push_back(4);
    cl.push_front(0);

    
    while(!cl.empty()) {
        cl.print();
        cl.print_backwards();
        std::cout << "=========================\n";
        cl.pop_back();
    }
    
    cl.push_front(2);
    cl.push_front(1);
    cl.push_back(3);
    cl.push_back(4);
    cl.push_front(0);
    
    while(!cl.empty()) {
        cl.print();
        cl.print_backwards();
        std::cout << "=========================\n";
        cl.pop_front();
    }

    return 0;
}
