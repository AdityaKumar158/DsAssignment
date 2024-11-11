#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the Circular Queue

// Structure for Circular Queue
struct CircularQueue {
    char queue[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct CircularQueue* cq) {
    cq->front = cq->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* cq) {
    return (cq->front == (cq->rear + 1) % MAX);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* cq) {
    return (cq->front == -1);
}

// Function to insert an element into the Circular Queue
void insert(struct CircularQueue* cq, char value) {
    if (isFull(cq)) {
        printf("Overflow! The queue is full.\n");
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX;
    cq->queue[cq->rear] = value;
    printf("Inserted '%c' into the queue.\n", value);
}

// Function to delete an element from the Circular Queue
void delete(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Underflow! The queue is empty.\n");
        return;
    }
    printf("Deleted '%c' from the queue.\n", cq->queue[cq->front]);
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;  // Queue is empty
    } else {
        cq->front = (cq->front + 1) % MAX;
    }
}

// Function to display the status of the Circular Queue
void display(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Queue status: ");
    int i = cq->front;
    while (i != cq->rear) {
        printf("%c ", cq->queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", cq->queue[cq->rear]);
}

int main() {
    struct CircularQueue cq;
    initQueue(&cq);
    char value;
    int choice;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display the status of the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to insert: ");
                getchar();  // to clear the newline left by scanf
                scanf("%c", &value);
                insert(&cq, value);
                break;
            case 2:
                delete(&cq);
                break;
            case 3:
                printf("Demonstrating Overflow and Underflow:\n");
                insert(&cq, 'A');
                insert(&cq, 'B');
                insert(&cq, 'C');
                insert(&cq, 'D');
                insert(&cq, 'E');  // Now the queue is full
                insert(&cq, 'F');  // Overflow case
                delete(&cq);       // Remove 'A'
                delete(&cq);       // Remove 'B'
                delete(&cq);       // Remove 'C'
                delete(&cq);       // Remove 'D'
                delete(&cq);       // Remove 'E' - Now the queue is empty
                delete(&cq);       // Underflow case
                break;
            case 4:
                display(&cq);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
