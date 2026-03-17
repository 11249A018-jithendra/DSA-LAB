#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, first = 0, second = 1, next, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci series using Iterative method:\n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            next = 0;
        else if (i == 1)
            next = 1;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }

    printf("\n\nFibonacci series using Recursive method:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
