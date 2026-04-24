#include <stdio.h>
#define V 5   // Total number of vertices
/* Greedy function to find an approximate Vertex Cover
   Uses a simple 2-approximation approach */
void findVertexCover(int graph[V][V])
{
    int visited[V];   // Stores vertices included in the cover (0 = no, 1 = yes)
    // Initialize all vertices as not included
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    // Traverse all edges in the adjacency matrix
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // If an edge exists and both vertices are not yet included
            if (graph[u][v] == 1 && visited[u] == 0 && visited[v] == 0)
            {
                // Include both endpoints in the vertex cover
                visited[u] = 1;
                visited[v] = 1;
            }
        }
    }
    // Print the resulting vertex cover
    printf("Approximate Vertex Cover: ");
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 1)
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal vertices in the cover: %d\n", count);
}
int main()
{
    // Adjacency matrix (1 = edge exists, 0 = no edge)
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    printf("Running Vertex Cover Approximation...\n");
    findVertexCover(graph);
    return 0;
}