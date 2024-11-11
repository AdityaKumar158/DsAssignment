/*
Design, Develop and Implement a menu-driven Program in C for the following Array operations:
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element at a given valid Position (POS)
d. Deleting an Element at a given valid Position (POS)
e. Exit
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;

void createArray() {
    printf("Enter the number of elements you want in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX_SIZE);
        size = 0;
        return;
    }

    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Array created successfully.\n");
}

void displayArray() {
    if (size == 0) {
        printf("Array is empty. Please create an array first.\n");
        return;
    }

    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertElement() {
    if (size == MAX_SIZE) {
        printf("Array is full! Cannot insert new elements.\n");
        return;
    }

    int element, pos;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d): ", size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = size; i >= pos; i--) {
        array[i] = array[i - 1];
    }
    array[pos - 1] = element;
    size++;
    printf("Element inserted successfully.\n");
}

void deleteElement() {
    if (size == 0) {
        printf("Array is empty! No elements to delete.\n");
        return;
    }

    int pos;
    printf("Enter the position to delete (1 to %d): ", size);
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos - 1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    printf("Element deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                insertElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
