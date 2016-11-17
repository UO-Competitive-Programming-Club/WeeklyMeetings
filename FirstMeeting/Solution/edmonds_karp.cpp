// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
 
bool BreathFirstSearch(const vector<vector<int> > &rG, const int source, const int sink, vector<int> & path) {


    return 0;
}

int FindMinimalResidualCapacity(const vector<vector<int> >& residualGraph, int source, int sink, const vector<int>& path) {


    int path_flow = INT_MAX;


    return path_flow;
}

void UpdateResidualGraph(vector<vector<int> >& residualGraph, int source, int sink, vector<int>& path, int path_flow) {



}

/* source and sink are the index of source and sink node */
int Edmond_Karp(const std::vector<vector<int> > & residualGraph, int source, int sink) {
    /* create a residualGraph by copying the capacity graph */
    std::vector<vector<int> > rG(residualGraph);
    /* the vector to save the new path computed by BFS */
    std::vector<int> path;
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

