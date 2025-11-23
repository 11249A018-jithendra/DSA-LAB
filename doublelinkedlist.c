// Aim: To perform doubly linked list operations

#include <stdio.h>
#include <stdlib.h>

// Structure of a node in doubly linked list
struct Node {
    int data;
    struct Node *prev;  // Pointer to previous node
    struct Node *next;  // Pointer to next node
};

// Function to create a new node with given data
struct Node *CreateNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;
    newNode->prev = NULL;  // Initially no previous link
    newNode->next = NULL;  // Initially no next link

    return newNode;
}

// Insert a node at the beginning of the list
void InsertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);

    // If list is empty, newNode becomes head
    if (*head == NULL) {
        *head = newNode;
    } 
    else {
        newNode->next = *head;      // newNode → old head
        (*head)->prev = newNode;    // old head → newNode
        *head = newNode;            // update head
    }

    printf("Node %d inserted at beginning.\n", data);
}

// Insert a node at the end of the list
void InsertAtEnd(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        printf("Node %d inserted at end.\n", data);
        return;
    }

    struct Node *temp = *head;

    // Traverse to last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;  // last → newNode
    newNode->prev = temp;  // newNode → last

    printf("Node %d inserted at end.\n", data);
}

// Insert a node at a specific position
void InsertAtPosition(struct Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    // If inserting at beginning
    if (position == 1) {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;
    int i;

    // Traverse to the node before the target position
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node *newNode = CreateNode(data);

    newNode->next = temp->next; // newNode → next node
    newNode->prev = temp;       // newNode → current node

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node %d inserted at position %d.\n", data, position);
}

// Delete a node using its value
void DeleteNode(struct Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node *temp = *head;

    // Case 1: deleting first node
    if (temp->data == value) {
        *head = temp->next;

        if (*head != NULL)
            (*head)->prev = NULL;

        free(temp);
        printf("Node %d deleted.\n", value);
        return;
    }

    // Case 2: search the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) {
        printf("Element %d not found.\n", value);
        return;
    }

    // Update the previous node’s next pointer
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    // Update the next node's prev pointer
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node %d deleted.\n", value);
}

// Display entire doubly linked list
void DisplayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("\nDoubly Linked List: \n");

    // Print each node with its previous and next pointers
    while (temp != NULL) {
        printf("|Prev=%p| %d |Next=%p| <-> ", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;

        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;

        case 5:
            DisplayList(head);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
