#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    // A function used by DFSFullGraph
    void DFSUtil(int v);

public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices reachable from v
    void DFS(int v);

    // print DFS traversal of the complete graph
    void DFSFullGraph();

    // reset visited to print the entire graph
    void resetGraph();
};

void Graph::addEdge(int v, int w) {
    // Add w to v's list
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;

    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

void Graph::DFSUtil(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;

    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (!visited[*i]) {
            DFSUtil(*i);
        }
    }
}

// The function to do DFS transversal. It uses recursive DFSUtil()

void Graph::DFSFullGraph() {
    // Call the recursive helper function to print DFS
    // transversal starting from all vertices one by one

    for (auto i : adj) {
        if (!visited[i.first]) {
            DFSUtil(i.first);
        }
    }
}

void Graph::resetGraph() {
    for (auto i : adj) {
        if (visited[i.first]) {
            visited[i.first] = false;
        }
    }
}

int main() {

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Transversal (starting from vertex 2)" << endl;
    
    g.DFS(2);

    cout << endl;
    cout << "Reseting graph to execute the algorithm again..." << endl;

    g.resetGraph();

    cout << "Following is Depth First Traversal" << endl;

    g.DFSFullGraph();

    cout << endl;

    return 0;
}