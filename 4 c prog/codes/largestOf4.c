#include <stdio.h>

int main() {
    int a, b, c, d;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int  largest = (a>b && a>c && a>d ) ? a : (b>c && b>d) ? b : (c>d) ? c : d;

    printf("The largest number is: %d\n", largest);
    return 0;
}