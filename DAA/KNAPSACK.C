//Aim:To write a C program to solve the Fractional Knapsack Problem using Greedy method.

//program:
#include<stdio.h>
int i, j;
// Structure to store profit, weight, and profit/weight ratio
struct data
{
    int profit;
    int weight;
    float avg;   // profit per unit weight
};
// Function to sort items based on descending order of avg (ratio)
void sort_items(struct data items[], int n)
{
    struct data temp;
    // Simple sorting (bubble/selection style)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            // Swap if next item has higher ratio
            if(items[i].avg < items[j].avg)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
int main()
{
    int n, capacity;
    // Input number of items
    printf("Enter no. of items:\n");
    scanf("%d", &n);
    struct data items[n];
    // Input profit and weight for each item
    for(i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d:\n", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
    }
    // Input knapsack capacity
    printf("Enter knapsack capacity:\n");
    scanf("%d", &capacity);
    // Calculate profit/weight ratio
    for(i = 0; i < n; i++)
    {
        items[i].avg = (float)items[i].profit / items[i].weight;
    }
    // Sort items based on ratio (greedy choice)
    sort_items(items, n);
    float totalvalue = 0.0;
    // Select items for maximum profit
    for(i = 0; i < n; i++)
    {
        // If item can be fully taken
        if(capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalvalue += items[i].profit;
        }
        else
        {
            // Take fractional part of item
            totalvalue += items[i].avg * capacity;
            break;
        }
    }
    // Output result
    printf("Maximum profit: %.2f\n", totalvalue);
    return 0;
}
