//Aim:Implementation of tower of hanoi using recursion.

//program:
#include <stdio.h>

// Function to solve Tower of Hanoi problem
// n  -> number of disks
// s  -> source rod
// d  -> destination rod
// a  -> auxiliary rod
void towerofhanoi(int n, char s, char d, char a)
{
    // Base case: if there is only one disk
    if (n == 1)
    {
        // Move the single disk directly from source to destination
        printf("move the disk %d from %c to %c\n", n, s, d);
        return;
    }

    // Step 1: Move (n-1) disks from source to auxiliary rod
    towerofhanoi(n - 1, s, a, d);

    // Step 2: Move the nth (largest) disk from source to destination
    printf("move disk %d from %c to %c\n", n, s, d);

    // Step 3: Move the (n-1) disks from auxiliary rod to destination
    towerofhanoi(n - 1, a, d, s);
}

int main()
{
    int disk_count;

    // Ask the user for the number of disks
    printf("enter how many disk are there:\n");
    scanf("%d", &disk_count);
    printf("required moves:\n");
    towerofhanoi(disk_count, 's', 'd', 'a');

    return 0;
}


