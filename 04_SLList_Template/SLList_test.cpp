#include "SLList.hpp"
#include "SLList.cpp"
#include <string>

int main(void) {
    SLList<std::string> list;
    list.push_front("abc");
    list.push_front("def");
    list.push_front("ghi");
    list.push_front("jkl");


    list.print();


    return 0;
}