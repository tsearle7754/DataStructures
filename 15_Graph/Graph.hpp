#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>

template <typename T>
class Graph {
public:
    void insertVertex(const T& value);
    void insertEdge(const T& v1, const T& v2);  // connec
    void print() const;

private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> edges;    // vector of integers - list of adjacent nodes

    // prevent duplicates
    int getVertexIndex(const T& value) const;
};

#include "Graph.tpp"    // now only have to include hpp in main file

#endif