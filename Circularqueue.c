/*
===========================================================
                        AIM
===========================================================
To write a C program to implement a Circular Queue 
using arrays with operations such as Enqueue, Dequeue, 
and Display.

===========================================================
                      ALGORITHM
===========================================================
1. Start the program.
2. Declare an array 'queue[MAX]' and two variables 
   'front' and 'rear' initialized to -1.
3. For Enqueue (Insertion):
      a) Check if (front == (rear + 1) % MAX) → Queue is Full.
      b) Else if (front == -1) → set front = rear = 0.
      c) Otherwise, rear = (rear + 1) % MAX.
      d) Insert element at queue[rear].
4. For Dequeue (Deletion):
      a) Check if (front == -1) → Queue is Empty.
      b) Otherwise, print deleted element.
      c) If (front == rear) → set front = rear = -1 (queue becomes empty).
      d) Else, front = (front + 1) % MAX.
5. For Display:
      a) If (front == -1) → Queue is Empty.
      b) Otherwise, print elements from 'front' to 'rear' circularly.
6. Repeat menu choices until user selects Exit.
7. Stop the program.

===========================================================
                        PROGRAM
===========================================================
*/
#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == (rear + 1) % MAX)) {
        printf("Queue is Full.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("Inserted %d into queue.\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Deleted %d from queue.\n", value);
}

void display() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    printf("Circular Queue Implementation using Array\n");
    printf("------------------------------------------\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
