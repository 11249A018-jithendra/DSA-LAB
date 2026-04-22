//Aim:
To write and execute a C program to implement the First Fit algorithm for the Bin Packing problem, which places each item in the first available bin that has enough remaining capacity.

//program:
#include <stdio.h>
// Function to implement First Fit Bin Packing Algorithm
void firstFit(int items[], int n, int capacity)
{
    int bin[n];       // Array to store remaining capacity of bins
    int binCount = 0; // Number of bins currently used
    // Initialize bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;
    // Process each item
    for (int i = 0; i < n; i++)
    {
        int placed = 0; // Flag to check whether item is placed
        // Check existing bins
        for (int j = 0; j < binCount; j++)
        {
            // If item fits in the bin
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i]; // Reduce remaining capacity
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break; // Stop after first suitable bin (First Fit)
            }
        }
        // If item does not fit in any bin, create a new bin
        if (!placed)
        {
            bin[binCount] = capacity - items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;
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
    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    int items[n]; // Array to store item sizes
    printf("Enter item sizes:\n");
    // Input item sizes
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
            i--; // Repeat the input
        }
    }
    // Call First Fit algorithm
    firstFit(items, n, capacity);
    return 0;
}
