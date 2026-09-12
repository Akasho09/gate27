#include <stdio.h>
int main() {
    int a = ~2147483647; // Bitwise NOT operator applied to INT_MAX
    int b  = ~0;
    printf("The value of a (~INT_MAX) is: %d\n", a);
    printf("The value of b (~0) is: %d\n", b);

}