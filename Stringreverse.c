/*
===========================================================
                        AIM
===========================================================
To write a C program to reverse a given string 
without using the built-in strrev() function.

===========================================================
                      ALGORITHM
===========================================================
1. Start the program.
2. Read a string from the user.
3. Initialize two variables:
      start = 0 
      end = length of string - 1
4. Repeat while start < end:
      a) Swap the characters at positions 'start' and 'end'.
      b) Increment 'start' and decrement 'end'.
5. After the loop ends, the string will be reversed.
6. Display the reversed string on the screen.
7. Stop the program.

===========================================================
                        PROGRAM
===========================================================
*/
#include <stdio.h>
#include <stdlib.h>

int top = -1;       // Top pointer of stack (initially empty)
int size;           // Size of string (and stack)
char *STACK;        // Dynamic array for stack

// Function to push a character into stack
void push(char item)
{
    // Overflow condition: when top reaches last index
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;         // Increase top
        STACK[top] = item;     // Insert character
    }
}

// Function to pop and return a character from stack
char pop()
{
    char temp = STACK[top];    // Take the top element
    top = top - 1;             // Move top backward
    return temp;               // Return popped character
}

int main()
{
    // Ask user for string size
    printf("Enter the size of string to reverse: ");
    scanf("%d", &size);

    char input[size];          // Array to store user string

    // Allocate memory for stack dynamically
    STACK = (char *)malloc(size * sizeof(char));

    // Input the string
    printf("Enter the string of size %d to reverse: ", size);
    scanf("%s", input);

    // Push each character of string into stack
    for (int i = 0; i <= size - 1; i++)
    {
        push(input[i]);
    }

    // Pop all characters to print reversed string
    printf("Reversed string is - \n");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", pop());
    }

    return 0;
}
