//Aim:To implement Dijkstra’s Algorithm in order to find the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

//program:
#include <stdio.h>
#define V 5
#define INF 999999
/* Function to find the vertex with minimum distance
   among the unvisited vertices */
int extractMin(int dist[], int visited[])
{
    int min = INF;
    int min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
/* Dijkstra's algorithm using adjacency matrix */
void dijkstra(int graph[V][V])
{
    int dist[V];      // Stores shortest distances from source
    int visited[V];   // Tracks visited vertices (0 = not visited, 1 = visited)
    // Initialize all distances as INF and visited as 0
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    // Source vertex (0) distance is always 0
    dist[0] = 0;
    // Loop to find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = extractMin(dist, visited);
        if (u == -1)
            break;
        visited[u] = 1;
        // Update distances of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            // Check if there is an edge and vertex is not visited
            if (graph[u][j] != 0 && visited[j] == 0)
            {
                // Relaxation step
                if (dist[u] + graph[u][j] < dist[j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }
    // Print the results
    printf("\nVertex\tDistance from Source (0)\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, dist[i]);
    }
}
int main()
{
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };
    dijkstra(graph);
    return 0;
}
