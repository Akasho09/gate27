#include <stdio.h>

int main() {
    int a = -129 % 256;
    int b = -12 % 7;
    int C = 12 % -7;
    // sign of ans is sign of dividend (first operand) in C language.

    printf("The value of a is: %d\n", a);
    printf("The value of b is: %d\n", b);
    printf("The value of C is: %d\n", C);

    return 0;
}