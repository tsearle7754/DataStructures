#include "Graph.hpp"

template <typename T>
void Graph<T>::insertVertex(const T& value) {
    if (getVertexIndex(value) != -1) {
        std::cout << "insertVertex: vertex already exists\n";
        return;
    }
    vertices.push_back(value);  // add to vertices vector
    std::vector<int> tmp;
    edges.push_back(tmp);   // empty list of connections/neighbors for new vertex
}


template <typename T>
int Graph<T>::getVertexIndex(const T& value) const {
    // search through vector
    int i = 0;
    for (const auto& v: vertices) { // commonly used to loop through something like this
        if (v == value) {
            return i;
        }
        i++;
    }
    return -1;  // no element
}


template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
    int i1 = getVertexIndex(v1);
    int i2 = getVertexIndex(v2);
    if (i1 == -1 || i2 == -1) {
        std::cout << "insertEdge: incorrect viertices\n";
        return;
    }
    edges[i1].push_back(i2);
    if (i1 != i2) {
        edges[i2].push_back(i1);
    }
}

template <typename T>
void Graph<T>::print() const {              // make it look better TODO - done
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "\n{ " << vertices[i] << ": ";
        for (int j = 0; j < edges[i].size(); j++) {
            std::cout << vertices[edges[i][j]] << " ";      // print the actual value
        }
    }
    std::cout << "}\n";
}