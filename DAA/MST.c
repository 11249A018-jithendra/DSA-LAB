//Aim:
To write and execute a C program to implement Prim’s Algorithm to find the Minimum Spanning Tree (MST) of a graph using an adjacency matrix.

//program:
  
#include <stdio.h>
#define V 5        // Number of vertices
#define INF 999999 // A large value representing infinity
// Function to find the vertex with the minimum key value
int minKey(int key[], int visited[])
{
    int min = INF;
    int min_index = -1;
    // Search for the smallest key value among unvisited vertices
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
// Function to print the Minimum Spanning Tree
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    int total = 0;
    // Start from vertex 1 because vertex 0 is the root
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total Cost of MST = %d\n", total);
}
// Function implementing Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Stores MST
    int key[V];      // Minimum edge weight for each vertex
    int visited[V];  // Track visited vertices
    // Step 1: Initialize arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        visited[i] = 0;
    }
    // Step 2: Start from vertex 0
    key[0] = 0;
    parent[0] = -1; // Root of MST
    // Step 3: Construct MST
    for (int count = 0; count < V - 1; count++)
    {
        // Pick vertex with smallest key value
        int u = minKey(key, visited);
        visited[u] = 1;
        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Check if there is an edge, vertex not visited, and weight is smaller
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Print the MST
    printPrimMST(parent, graph);
}
int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] =
    {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };
    // Run Prim's Algorithm
    primMST(graph);
    return 0;
}
