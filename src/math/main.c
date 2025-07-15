#include <stdio.h>

int factorial(int n) {
    if (n < 1) {
        return 1; 
    }

    return n * factorial(n - 1);
}

int sum(int n) {
    if (n < 1) {
        return 0;
    }

    return n + sum(n - 1);
}

int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }

    return base * (power(base, exp - 1));
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } 

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    printf("factorial(3): %d\n", factorial(3));
    printf("sum(5): %d\n", sum(5));
    printf("power(5, 5): %d\n", power(5, 5));
    printf("fibonacci(6): %d\n", fibonacci(6));
}
