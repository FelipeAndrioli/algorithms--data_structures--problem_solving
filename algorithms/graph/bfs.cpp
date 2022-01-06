#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
    // Number of vertices
    int V;

    // Pointer to an array containing adjacency lists
    list<int> *adj;

public:
    // Constructor
    Graph(int V); 

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // Print BFS transversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    // Add w to v's list
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();

        cout << s << " ";

        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {

    // Create a graph
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Transversal" << endl;
    g.BFS(0);

    return 0;
}