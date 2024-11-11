/*5.Design, Develop and Implement a Program in C/C++ for converting an Infix Expression to Postfix 
Expression. Program should support for both parenthesized and free parenthesized expressions with 
the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Function prototypes
void push(char ch);
char pop();
char peek();
int isOperator(char ch);
int precedence(char ch);
int isRightAssociative(char ch);
void infixToPostfix(char infix[], char postfix[]);

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    return 0;
}

// Function to push an element onto the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = ch;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Function to peek at the top element of the stack
char peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

// Function to check the precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if an operator is right associative
int isRightAssociative(char ch) {
    return ch == '^';
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;
    
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            push(ch);
        }
        // If the character is ')', pop and output from the stack until '(' is encountered
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '('
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)) && peek() != '(') {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all the remaining operators in the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
}