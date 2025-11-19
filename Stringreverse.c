//Aim:To perform string reverse using stack operation
#include <stdio.h>
#include <string.h>
// Initialize stack variables
int top = -1; // Stack top pointer starts at -1 (indicating an empty stack)
int size;
char stack[50];
void push(char item)
{
    if (top == (size - 1))
    {
        printf("Stack overflow! Cannot push '%c'.\n", item);
    }
    else
    {
        top = top + 1; // Stack top pointer starts at -1 (indicating an empty stack)
        stack[top] = item;
    }
}
char pop()
{
    if (top == -1) // Check if the stack is empty (underflow condition)
    {
        printf("Stack underflow!\n");
        return '\0';
    }
    else
    {
        char temp = stack[top];
        top--; // Decrement top to remove the element from the stack
        return temp;
    }
}
int main()
{
    printf("Enter the maximum size of string to reverse: ");
    scanf("%d", &size);
    char input[50];// Declare an array to store the input string
    printf("Enter the string to reverse: ");
    scanf("%s", input);
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        push(input[i]);
    }
    printf("Reversed string is: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", pop());
    }
    printf("\n");// Print a newline after the reversed string
    return 0;
}

