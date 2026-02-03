// Aim: To perform stack operations using Linked List

#include <stdio.h>
#include <stdlib.h>

// Structure of a node in singly linked list
struct Node {
    int data;
    struct Node *next;   // Pointer to next node
};

// Function to create a new node
struct Node* CreateNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check memory allocation
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data; // Store data
    newNode->next = NULL; // No next link initially
    return newNode;
}

// PUSH operation: Insert at beginning (top of stack)
void Push(struct Node **top, int data) {
    struct Node *newNode = CreateNode(data);

    // Point new node to current top
    newNode->next = *top;

    // Update top pointer
    *top = newNode;

    printf("Pushed %d successfully.\n", data);
}

// POP operation: Remove from beginning
void Pop(struct Node **top) {
    // Underflow check
    if (*top == NULL) {
        printf("Stack Underflow! POP not possible.\n");
        return;
    }

    struct Node *temp = *top;       // Temp pointer to top node
    printf("Popped %d.\n", temp->data);

    *top = (*top)->next;            // Move top to next node
    free(temp);                     // Delete old top
}

// PEEK operation: Check top element
void Peek(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element = %d\n", top->data);
    }
}

// DISPLAY operation: Print stack from top to bottom
void Display(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;
    printf("\nStack (Top to Bottom):\n");

    // Traverse and print each node
    while (temp != NULL) {
        printf("|%d| -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *top = NULL;   // Stack initially empty
    int choice, data;

    while (1) {
        // Menu for stack operations
        printf("\n--- Stack Using Singly Linked List ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &data);
            Push(&top, data);
            break;

        case 2:
            Pop(&top);
            break;

        case 3:
            Peek(top);
            break;

        case 4:
            Display(top);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
