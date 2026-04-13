//Aim:To write a C program to generate the Fibonacci series using both Iterative and Recursive methods.

//program:
#include <stdio.h>
// Recursive function to find Fibonacci number
int fibonacci(int n)
{
    // Base case: if n is 0 or 1, return n
    if (n <= 1)
        return n;
    // Recursive case: sum of previous two numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n, first = 0, second = 1, next, i;
    // Take input from user
    printf("Enter number of terms: ");
    scanf("%d", &n);
    // Iterative method (using loop)
    printf("\nFibonacci series using Iterative method:\n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            next = 0;   // First term
        }
        else if (i == 1)
        {
            next = 1;   // Second term
        }
        else
        {
            // Next term is sum of previous two
            next = first + second;

            // Update values for next iteration
            first = second;
            second = next;
        }
        // Print current Fibonacci number
        printf("%d ", next);
    }
    // Recursive method (function calling itself)
    printf("\n\nFibonacci series using Recursive method:\n");
    for (i = 0; i < n; i++)
    {
    printf("%d ", fibonacci(i)); // Call recursive function
    }
    return 0;
}
