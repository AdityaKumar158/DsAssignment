/*Design, Develop and Implement a menu driven Program in C/C++ for the following operations on 
STACK of Integers (Array Implementation of Stack with maximum size MAX) 
a. Push an Element on to Stack 
b. Pop an Element from Stack 
c. Demonstrate how Stack can be used to check Palindrome 
d. Demonstrate Overflow and Underflow situations on Stack 
e. Display the status of Stack 
f. Exit 
Support the program with appropriate functions for each of the above operations*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
int stack[MAX];
int top = -1; // Stack is initially empty

// Function prototypes
void push(int element);
int pop();
int isPalindrome(char str[]);
void displayStack();
int isFull();
int isEmpty();

// Main menu-driven function
int main() {
    int choice, element;
    char str[MAX];

    while (1) {
        // Display menu
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push an Element on to Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                element = pop();
                if (element != -1)
                    printf("Popped element: %d\n", element);
                break;

            case 3:
                printf("Enter a string to check if it's a palindrome: ");
                scanf("%s", str);
                if (isPalindrome(str))
                    printf("The string \"%s\" is a palindrome.\n", str);
                else
                    printf("The string \"%s\" is not a palindrome.\n", str);
                break;

            case 4:
                if (isFull())
                    printf("Stack Overflow: Cannot push element, stack is full.\n");
                else
                    printf("Stack is not full.\n");
                
                if (isEmpty())
                    printf("Stack Underflow: Cannot pop element, stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;

            case 5:
                displayStack();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to push an element onto the stack
void push(int element) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", element);
        return;
    }
    stack[++top] = element;
    printf("Pushed %d onto the stack.\n", element);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    return stack[top--];
}

// Function to check if a string is a palindrome using a stack
int isPalindrome(char str[]) {
    int len = strlen(str);
    int mid = len / 2;

    // Push the first half of the string onto the stack
    for (int i = 0; i < mid; i++) {
        push(str[i]);
    }

    // For odd-length strings, skip the middle character
    int start = (len % 2 == 0) ? mid : mid + 1;

    // Check if the second half of the string matches the stack
    for (int i = start; i < len; i++) {
        char ch = pop();
        if (ch != str[i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to display the stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}
