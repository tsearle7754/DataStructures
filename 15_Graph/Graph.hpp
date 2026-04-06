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

    void DFS() const;
    void DFS(int i, std::vector<bool>& visited) const;  // helper function
    void BFS(int start = 0) const;

    int shortestPath(const T& src, const T& dest) const;

    // TODO
    bool isConnected() const;   // figure it out - if all nodes are in the network, 
                                // false if at least one node cannot be reached 
                                // (getVertexIndex, same approach as BFS, have a counter, compare how many visited and total number of nodes. 
                                // if the same, connected graph. if different, graph is disconnected)

private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> edges;    // vector of integers - list of adjacent nodes

    // prevent duplicates
    int getVertexIndex(const T& value) const;
};

#include "Graph.tpp"    // now only have to include hpp in main file

#endif