//Aim:
To write and execute a C program to implement the Best Fit algorithm for the Bin Packing problem, which places each item into the bin that leaves the least remaining space after placement,
thereby minimizing the number of bins used.
  
//program:

#include <stdio.h>
// Function to implement Best Fit Bin Packing Algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");
    int bin[n];        // Array to store remaining capacity of bins
    int binCount = 0;  // Number of bins used
    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;
    // Process each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;         // Index of best bin
        int minSpace = capacity+1;  // Minimum remaining space
        // Check all existing bins to find best fit
        for (int j = 0; j < binCount; j++)
        {
            // Bin must have space and leave minimum leftover
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }
        // If a suitable bin is found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];  // Reduce remaining capacity
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create a new bin
            bin[binCount] = capacity - items[i];
            binCount++;
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], binCount);
        }
    }
    printf("Total bins used = %d\n", binCount);
}
int main()
{
    int n, capacity;
    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    int items[n];  // Array to store item sizes
    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    printf("Enter item sizes:\n");
    // Read item sizes
    for (int i = 0; i < n; i++)
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);
        // Validate item size
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Enter again.\n");
            i--; // repeat input
        }
    }
    // Call Best Fit function
    bestFit(items, n, capacity);
    return 0;
}
