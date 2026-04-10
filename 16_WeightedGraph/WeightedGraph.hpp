#ifndef WEIGHTEDGRAPH_HPP
#define WEIGHTEDGRAPH_HPP
#include <vector>


template <typename T>
class WeightedGraph {
public:

    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2, int weight = 1);
    void print() const;

    void DFS() const;       // adjust for weight
    void BFS(int start = 0) const;      // adjust for weight
    int shortestPath(const T& src, const T& dest) const;
    bool isConnected() const;       // adjust for weight


private:
    std::vector<T> vertices; 
    std::vector<std::vector<Edge>> edges; 

    
    int getVertexIndex(const T& vs) const;

    bool hasEdge(int i1, int i2) const;
    void DFS(int i, std::vector<bool>& visited) const;
};

// EDGE CLASS
class Edge {
public:
    int neighbor;
    int weight;

    Edge(int n, int w) : neighbor(n), weight(w) {}

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

#include "WeightedGraph.tpp"

#endif