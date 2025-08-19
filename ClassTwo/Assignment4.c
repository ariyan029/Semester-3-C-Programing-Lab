/*
Create a struct Op{const char *name;int (*fn)(int,int);}Build an array of operations
(add,sub,mul,max)and call them via pointers.Print Result.
*/
#include <stdio.h>

// Define the structure for an operation
struct Op {
    const char *name;
    int (*fn)(int, int);
};

// Operation functions
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    // Build an array of operations
    struct Op operations[] = {
        {"add", add},
        {"sub", sub},
        {"mul", mul},
        {"max", max}
    };

    int x = 20;
    int y = 10;
    int num_operations = sizeof(operations) / sizeof(operations[0]);

    printf("Performing operations with x = %d and y = %d\n", x, y);

    // Call the functions via pointers and print the result
    for (int i = 0; i < num_operations; i++) {
        int result = operations[i].fn(x, y);
        printf("Result of %s: %d\n", operations[i].name, result);
    }

    return 0;
}

/*
Performing operations with x = 20 and y = 10
Result of add: 30
Result of sub: 10
Result of mul: 200
Result of max: 20

*/