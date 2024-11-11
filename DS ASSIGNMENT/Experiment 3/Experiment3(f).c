#include <stdio.h>

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long result = 1; // To store the factorial result
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;

    // Taking user input for the number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Handling the case for negative numbers
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculating and printing the factorial
        printf("Factorial of %d is %lld\n", n, factorial(n));
    }

    return 0;
}
