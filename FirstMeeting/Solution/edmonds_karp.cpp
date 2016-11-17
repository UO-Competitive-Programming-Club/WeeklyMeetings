// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
 
bool BreathFirstSearch(const vector<vector<int> > &residualGraph, const int source, const int sink, vector<int> & path) {
    const int num_vertices = residualGraph.size();
    vector<bool> visited(num_vertices, false);

    // Create a queue, enqueue source vertex and mark source vertex
    queue <int> q;
    q.push(source);
    visited[source] = true;

    /* reset the path to zero */
    fill(path.begin(), path.end(), 0);
    path[source] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < num_vertices; v++) {
            if (visited[v] == false && residualGraph[u][v] > 0) {
                q.push(v);
                path[v] = u;
                visited[v] = true;
            }
        }
    }
    
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[sink] == true);
}

int FindMinimalResidualCapacity(const vector<vector<int> >& residualGraph, int source, int sink, const vector<int>& path) {
    int path_flow = INT_MAX;
    int pathlen = path.size();

    for (int v = sink; v != source; v = path[v]) { 
        int u = path[v];

        path_flow = min(residualGraph[u][v], path_flow);
    }

    return path_flow;
}

void UpdateResidualGraph(vector<vector<int> >& residualGraph, int source, int sink, vector<int>& path, int path_flow) {
    int pathlen = path.size();
    for (int v = sink; v != source; v = path[v]) { 
        int u = path[v];
        /* update normal edges */
        residualGraph[u][v] -= path_flow;

        /* update normal edges */
        residualGraph[v][u] -= path_flow;
    }
}

/* source and sink are the index of source and sink node */
int Edmond_Karp(const std::vector<vector<int> > & residualGraph, int source, int sink) {
    /* create a residualGraph by copying the capacity graph */
    std::vector<vector<int> > rG(residualGraph);

    /* the vector to save the new path computed by BFS */
    std::vector<int> path(residualGraph.size(), 0);
    int max_flow = 0;

    while (BreathFirstSearch(rG, source, sink, path)) {
        /* find the minimal residual capacity on the path */
        int path_flow = FindMinimalResidualCapacity(rG, source, sink, path);

        /* update residual capacities of the edges and reverse edges */ 
        UpdateResidualGraph(rG, source, sink, path, path_flow);

        max_flow += path_flow;
    }

    return max_flow;
}

int main(void) {
    int num_vertices, source, sink;

    cin >> num_vertices;
    cin >> source >> sink;

    /* initalize 2 d vector with all zeros */
    vector<vector<int> > graph(num_vertices, vector<int>(num_vertices, 0));

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            cin >> graph[i][j];
        }
    }
     
    std::cout << Edmond_Karp(graph, source, sink) << std::endl;
}
