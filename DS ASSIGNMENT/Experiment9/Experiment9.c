#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create the doubly linked list (DLL)
void createDLL(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;  // If list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Link the new node at the end
        newNode->prev = temp;  // Set the previous pointer of the new node
    }
}

// Function to print the DLL in forward direction
void printForward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the DLL in reverse direction
void printReverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    printf("Reverse Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function implementing the menu-driven program
int main() {
    struct Node* head = NULL;  // Initialize an empty list
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Create a DLL\n");
        printf("2. Print all elements in DLL in forward traversal order\n");
        printf("3. Print all elements in DLL in reverse traversal order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                createDLL(&head, data);
                break;
            case 2:
                printForward(head);
                break;
            case 3:
                printReverse(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
