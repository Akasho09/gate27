#include <stdio.h>

int main() {
    // int a = 2.5;
    // char b = 'A';
    // printf("Hello, World!\n");
    // printf("The value of a is: %d\n", a);
    // printf("The address of a is: %p\n", (void*)&a);
    // // (void*)&age = "the address of age, treated as a generic pointer."
    // printf("The value of b is: %c\n", b);
    // printf("The value of b is: %d\n", b);

    float c = 3.145678901234;
    printf("The value of c is: %f\n", c);
    printf("The value of c is: %.10f\n", c);

    // > float typically gives about 6–7 significant decimal digits of precision.

    float d = 0.000145678901234;
    printf("The value of d is: %f\n", d);
    printf("The value of d is: %.10f\n", d);

    return 0;
}