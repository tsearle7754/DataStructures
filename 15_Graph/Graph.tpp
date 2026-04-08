#include "Graph.hpp"
#include <queue>
#include <vector>

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
        std::cout << "insertEdge: incorrect vertices\n";
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

template <typename T>
void Graph<T>::DFS() const {
    if (vertices.empty()) return;
    std::vector<bool> visited(vertices.size(), false);
    DFS(0, visited);
}

template <typename T>
void Graph<T>::DFS(int i, std::vector<bool>& visited) const {
    visited[i] = true;
    std::cout << vertices[i] << " -> ";

    // look through all the neighbors
    for (int j : edges[i]) {
        if (!visited[j]) {
            DFS(j, visited);
        }
    }
}

template <typename T>
void Graph<T>::BFS(int start) const {
    if (vertices.empty() || start < 0 || start >= vertices.size()) return;  // wrong starting number

    std::vector<int> discovered(vertices.size(), false);    // size, default
    std::queue<int> where_to_go;

    where_to_go.push(start);
    discovered[start] = true;

    while (!where_to_go.empty()) {
        int cur = where_to_go.front();
        std::cout << vertices[cur];
        where_to_go.pop();

        // explore the neighbors
        for (int j : edges[cur]) {
            if (!discovered[j]) {
                where_to_go.push(j);
                discovered[j] = true;
            }
        }
    }
}

template <typename T>
int Graph<T>::shortestPath(const T& src, const T& dest) const { // BFS
    // find indices
    int i_src = getVertexIndex(src);
    int i_dest = getVertexIndex(dest);

    // check edge case
    if (i_src == -1 || i_dest == -1) {
        std::cout << "shortestPath: incorrect indices";
        return -1;
    }
    if (i_src == i_dest) {  // beginning is end
        return 0;
    }

    // create distances vector
    std::vector<int> distances(vertices.size());    // distances from source to all other nodes
    // Set initial distances
    for (int i = 0; i < distances.size(); i++) {
        distances[i] = (i == i_src) ? 0 : -1;
    }

    // perform BFS and update distances
    std::queue<int> q;
    q.push(i_src);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        // check the neighbors
        for (int i : edges[cur]) {
            if (distances[i] == -1) {   // means we've never been there
                distances[i] = distances[cur] + 1;
                q.push(i);
            }
            if (i == i_dest) {
                return distances[i];
            }
        }
    }
    return -1;  // no path exists
}

template <typename T>
bool Graph<T>::isConnected() const {
    if (vertices.empty()) return true;

    std::vector<bool> visited(vertices.size(), false);
    std::queue<int> q;

    q.push(0);
    visited[0] = true;
    int visited_count = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();    // don't reuse or revisit nodes

        for (int neighbor : edges[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                ++visited_count;
                q.push(neighbor);
            }
        }
    }
    return visited_count == (int)vertices.size();
}