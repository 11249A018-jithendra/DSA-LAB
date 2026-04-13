//Aim:Implementation of tower of hanoi using recursion.

//program:
#include<stdio.h>
// Function to solve Tower of Hanoi
void towerofhanoi(int n, char s, char d, char a)
{
    // Base case: if only one disk, move it directly
    if(n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, s, d);
        return;
    }
    // Step 1: Move (n-1) disks from source to auxiliary
    towerofhanoi(n-1, s, a, d);
    // Step 2: Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, s, d);
    // Step 3: Move (n-1) disks from auxiliary to destination
    towerofhanoi(n-1, a, d, s);
}
int main()
{
    int disk_count;
    // Taking input from user
    printf("Enter number of disks:\n");
    scanf("%d", &disk_count);
    // Display heading
    printf("Required moves:\n");
    // Function call
    // s = source, d = destination, a = auxiliary
    towerofhanoi(disk_count, 'S', 'D', 'A');
    return 0;
}
