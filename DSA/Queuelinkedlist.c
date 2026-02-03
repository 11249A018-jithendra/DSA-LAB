/*
===========================================================
                        AIM
===========================================================
To write a C program to implement a Queue using Linked List 
with operations such as Enqueue (Insert), Dequeue (Delete), 
and Display the queue elements along with their addresses.

===========================================================
                      ALGORITHM
===========================================================
1. Start the program.
2. Define a structure 'Node' with:
      - data (to store integer value)
      - next (pointer to next node)
3. Maintain two pointers:
      - front → points to the first node.
      - rear  → points to the last node.
4. For Enqueue (Insertion):
      a) Create a new node using malloc.
      b) If queue is empty, set front and rear to new node.
      c) Otherwise, link the new node at the end and 
         update rear pointer.
5. For Dequeue (Deletion):
      a) If queue is empty, display "Queue is empty".
      b) Otherwise, delete the node pointed by front and 
         move front to the next node.
      c) If queue becomes empty after deletion, set rear = NULL.
6. For Display:
      a) Traverse from front to rear and display each node's 
         address, data, and next pointer.
7. Repeat menu options until user chooses Exit.
8. Stop the program.

===========================================================
                        PROGRAM
===========================================================
*/
#include <stdio.h>
#include <stdlib.h>

// Structure defining a single node of the queue
struct Node {
    int data;              // To store data
    struct Node *next;     // Pointer to next node
};

// Function to create a new node
struct Node* CreateNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation failed
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;   // Store the value
    newNode->next = NULL;   // New node's next is NULL
    return newNode;
}

// Function to insert an element (ENQUEUE)
void Enqueue(struct Node **front, struct Node **rear, int data) {
    struct Node *newNode = CreateNode(data);  // Create new node

    // If queue is empty (front and rear both are NULL)
    if (*rear == NULL) {
        *front = *rear = newNode;  // Both front and rear point to new node
    } else {
        (*rear)->next = newNode;   // Link new node at the end
        *rear = newNode;           // Move rear to new node
    }

    printf("Enqueued %d successfully.\n", data);
}

// Function to remove an element (DEQUEUE)
void Dequeue(struct Node **front, struct Node **rear) {
    // If queue is empty
    if (*front == NULL) {
        printf("Queue is empty! Dequeue not possible.\n");
        return;
    }

    struct Node *temp = *front;   // Store front node in temp
    printf("Dequeued %d.\n", temp->data);

    *front = (*front)->next;      // Move front to next node

    // If queue becomes empty after dequeue
    if (*front == NULL)
        *rear = NULL;             // Rear should also become NULL

    free(temp);                   // Free removed node
}

// Function to show the front element
void Peek(struct Node *front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element = %d\n", front->data);
    }
}

// Function to display the entire queue
void Display(struct Node *front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("\nQueue (Front to Rear):\n");
    while (temp != NULL) {            // Traverse till NULL
        printf("|%d| -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *front = NULL;   // Initially queue is empty
    struct Node *rear = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Queue Using Singly Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &data);
            Enqueue(&front, &rear, data);
            break;

        case 2:
            Dequeue(&front, &rear);
            break;

        case 3:
            Peek(front);
            break;

        case 4:
            Display(front);
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
