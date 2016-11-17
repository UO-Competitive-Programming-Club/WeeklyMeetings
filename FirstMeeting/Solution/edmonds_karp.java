// Java program for implementation of Ford Fulkerson algorithm
import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.LinkedList;

class EdmondsKarp {

    /* Returns true if there is a path from source 's' to sink
      't' in residual graph. Also fills parent[] to store the
      path */
    boolean breathFirstSearch(int residual_graph[][], int s, int t, int parent[]) {
        // Create a visited array and mark all vertices as not
        int numOfVertices = residual_graph.length;
        boolean visited[] = new boolean[numOfVertices];
        for(int i = 0; i < numOfVertices; ++i)
            visited[i]=false;

        // Create a queue, enqueue source vertex and mark
        // source vertex as visited
        LinkedList<Integer> queue = new LinkedList<Integer>();
        queue.add(s);
        visited[s] = true;
        parent[s]=-1;

        // Standard BFS Loop
        while (queue.size()!=0) {
            int u = queue.poll();

            for (int v = 0; v < numOfVertices; v++) {
                if (visited[v]==false && residual_graph[u][v] > 0) {
                    queue.add(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }

        // If we reached sink in BFS starting from source, then
        // return true, else false
        return (visited[t] == true);
    }


    void UpdateResidualGraph(int residual_graph[][], int source, int sink, int path[], int path_flow) {

        for (int v = sink; v != source; v = path[v]) {
            int u = path[v];

            /* update normal edges */
            residual_graph[u][v] -= path_flow;

            /* update normal edges */
            residual_graph[v][u] += path_flow;
        }
    }

    int FindMinimalResidualCapacity(int residual_graph[][], int source, int sink, int path[]) {

        int path_flow = Integer.MAX_VALUE;

        for (int v = sink; v != source; v = path[v]) {
            int u = path[v];

            path_flow = Math.min(residual_graph[u][v], path_flow);
        }

        return path_flow;
    }

    /* source and sink are the index of source and sink node */
    int Edmond_Karp(int input_graph[][], int source, int sink) {
        int numOfVertices = input_graph.length;

        /* create a residual_graph by copying the capacity graph */
        int RG[][] = new int[numOfVertices][numOfVertices];
        for (int u = 0; u < numOfVertices; u++)
            for (int v = 0; v < numOfVertices; v++)
            	RG[u][v] = input_graph[u][v];

        /* the vector to save the new path computed by BFS */
        int path[] = new int[numOfVertices];
        int max_flow = 0;

        while (breathFirstSearch(RG, source, sink, path)) {
            /* find the minimal residual capacity on the path */
            int path_flow = FindMinimalResidualCapacity(RG, source, sink, path);

            /* update residual capacities of the edges and reverse edges */
            UpdateResidualGraph(RG, source, sink, path, path_flow);

            max_flow += path_flow;
        }

        return max_flow;
    }

    // Returns tne maximum flow from s to t in the given graph

    // Driver program to test above functions
    public static void main (String[] args) throws java.lang.Exception {
        // Let us create a graph shown in the above example

        int graph[][] =new int[][] { {0, 16, 13, 0, 0, 0},
                                     {0, 0, 10, 12, 0, 0},
                                     {0, 4, 0, 0, 14, 0},
                                     {0, 0, 9, 0, 0, 20},
                                     {0, 0, 0, 7, 0, 4},
                                     {0, 0, 0, 0, 0, 0}
                                   };
        EdmondsKarp m = new EdmondsKarp();

        System.out.println("The maximum possible flow is " +
                           m.Edmond_Karp(graph, 0, 5));
    }
}
