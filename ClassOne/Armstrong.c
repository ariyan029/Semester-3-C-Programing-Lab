#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int original = num, sum = 0, digits = 0, temp = num;

    // Count digits
    while (temp != 0) {
        digits++;           
        temp /= 10;
    }

    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return (sum == original);
}

int main() {
    int lower, upper;
    printf("Enter lower and upper range: ");
    scanf("%d %d", &lower, &upper);

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}