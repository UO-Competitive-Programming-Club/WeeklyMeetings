#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
 
/* returns false if no path can be found from source to sink */ 
/* it updates vector<int>& path therefore the vector variable passed in the function 
 * have a new path after each iteration */ 
bool BreathFirstSearch(const vector<vector<int> > &residual_graph, 
        const int source, const int sink, vector<int> & path) {

    const int num_vertices = residual_graph.size();
    vector<bool> visited(num_vertices, false);

    queue <int> q;
    q.push(source);
    visited[source] = true;

    fill(path.begin(), path.end(), 0);
    path[source] = -1;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < num_vertices; v++) {
            if (visited[v] == false && residual_graph[u][v] > 0) {
                q.push(v);
                path[v] = u;
                visited[v] = true;
            }
        }
    }
    
    return (visited[sink] == true);
}

int FindMinimalResidualCapacity(const vector<vector<int> >& residual_graph, 
        const int source, const int sink, const vector<int>& path) {

    int path_flow = INT_MAX,
        pathlen = path.size();

    for (int v = sink; v != source; v = path[v]) { 
        int u = path[v];

        /* each iteration gets you a pair of vertices u and v between an edge in the path 
         * so residual_graphp[u][v] is the residual capacity of an edge in the path 
         * */

        /* **** your code here **** */

    }

    return path_flow;
}

void UpdateResidualGraph(vector<vector<int> >& residual_graph, 
        const int source, const int sink, const vector<int>& path, int path_flow) {

    int pathlen = path.size();
    for (int v = sink; v != source; v = path[v]) { 
        int u = path[v];

        /* each iteration gets you a pair of vertices u and v between an edge in the path 
         * so residual_graphp[u][v] is the residual capacity of an edge in the path 
         * */

        /* **** your code here **** */
    }
}

/* source and sink are the index of source and sink node */
int Edmond_Karp(const std::vector<vector<int> > & residual_graph, 
        const int source, const int sink) {

    int max_flow = 0;

    /* copy the input to a new 2d vector */
    std::vector<vector<int> > RG(residual_graph);

    /* initalize the path vector to be zero 
     * you will pass this vector to bfs */
    std::vector<int> path(residual_graph.size(), 0);

    /* **** your code here **** */

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
