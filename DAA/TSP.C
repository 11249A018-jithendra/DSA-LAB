//Aim:To write a C program to find the minimum travelling cost using the Travelling Salesman Problem (TSP) with Dynamic Programming and Bitmasking technique.

//program:
#include<stdio.h>
#include<limits.h>
#define MAXN 15        // Maximum number of cities
#define INF INT_MAX    // Infinite cost
int n, k;
int d[MAXN][MAXN];        // Cost matrix
int dp[MAXN][1<<MAXN];    // DP table for memoization
// Function to calculate minimum cost
int g(int i, int S)
{
    // Base case: if no cities left, return cost to go back to start
    if(S == 0)
    {
        return d[i][0];
    }
    // If already calculated, return stored value
    if(dp[i][S] != -1)
    {
        return dp[i][S];
    }
    int minCost = INF;
    // Try visiting all remaining cities
    for(k = 0; k < n; k++)
    {
        // Check if city k is in set S
        if(S & (1 << k))
        {
            // Cost = current to k + remaining path cost
            int cost = d[i][k] + g(k, S & ~(1 << k));

            // Update minimum cost
            if(cost < minCost)
            {
                minCost = cost;
            }
        }
    }
    // Store result in DP table
    return dp[i][S] = minCost;
}
int main()
{
    int i, j, n, mask;
    // Input number of cities
    printf("Enter the number of cities:\n");
    scanf("%d", &n);
    // Input cost matrix
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }
    // Initialize DP table with -1
    for(i = 0; i < n; i++)
    {
        for(mask = 0; mask < (1 << n); mask++)
        {
            dp[i][mask] = -1;
        }
    }
    // Create set S with all cities except starting city (0)
    int S = 0;
    for(i = 1; i < n; i++)
    {
        S |= (1 << i);
    }
    // Start from city 0
    int result = g(0, S);
    // Print cost matrix
    printf("Given Cost Matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("|");
        for(j = 0; j < n; j++)
        {
            printf(" %d ", d[i][j]);
        }
        printf("|\n");
    }
    // Print minimum cost
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
