#include<stdio.h>

/* To Find Factorial of a Number using Recursion and loops */

int factorial_recursive(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial using recursion: %d\n", factorial_recursive(num));
    printf("Factorial using iteration: %d\n", factorial_iterative(num));

    return 0;
}

/* --------------OUTPUT----------------
Enter a number: 5
Factorial using recursion: 120
Factorial using iteration: 120
*/