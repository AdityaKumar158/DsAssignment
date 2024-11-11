#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Stack structure
#define MAX 100
int stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expression) {
    int i = 0;
    int operand1, operand2, result;

    while (expression[i] != '\0') {
        // If the character is a digit
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        }
        // If the character is an operator
        else {
            operand2 = pop();
            operand1 = pop();

            switch (expression[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '%': result = operand1 % operand2; break;
                case '^': result = (int)pow(operand1, operand2); break;
                default: 
                    printf("Invalid operator\n");
                    return -1;
            }

            push(result);
        }
        i++;
    }

    return pop(); // Final result
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    fgets(expression, MAX, stdin);

    int result = evaluatePostfix(expression);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}
