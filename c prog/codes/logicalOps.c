#include <stdio.h>

int main() {
    // int a = 5 && 0; // Logical AND
    // int b = printf("akash\n") && (-1); // Logical AND with printf
    // int c = 5 || 0; // Logical OR
    // int d = !5;     // Logical NOT

    // printf("The value of a (5 && 0) is: %d\n", a);
    // printf("The value of b (printf && -1) is: %d\n", b);
    // printf("The value of c (5 || 0) is: %d\n", c);
    // printf("The value of d (!5) is: %d\n", d);


    int val = 0 && printf("akash\n"); // akash wont be printed because 0 is false, so the second operand is not evaluated.
    printf("The value of val (0 && printf) is: %d\n", val);

    return 0;
}