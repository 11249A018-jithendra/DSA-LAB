//Aim:To implement a Randomized Quicksort algorithm to sort a list of elements efficiently by selecting a random pivot and applying the divide-and-conquer technique.

//program:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Swap two integers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* Partition function using last element as pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // Pivot element
    int i = low - 1;         // Index of smaller element
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Place pivot in correct position
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
/* Randomized QuickSort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Select a random pivot and move it to the end
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[high]);
        // Partition the array
        int pi = partition(arr, low, high);
        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int n;
    srand(time(NULL));  // Seed for random pivot selection
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Enter a positive number.\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Sort the array
    quickSort(arr, 0, n - 1);
    // Display sorted result
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
