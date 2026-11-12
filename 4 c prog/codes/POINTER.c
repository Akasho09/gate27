#include <stdio.h>

int main() {
    int arr[5];

    char *x;
    int a = 512;
    x = (char *) &a;
    x[0] = 1;
    x[1] = 2;
    printf("%d\n",a);

    // int *ptr1 = &arr[0];
    // int *ptr2 = &arr[3];

    // printf("%td\n", (char*)ptr2 - (char*)ptr1); // Pointer arithmetic: difference in bytes or 1 byte each difference unit cz char is 1 byte
    // printf("%td", (int*)ptr2 - (int*)ptr1); // Pointer arithmetic: difference in number of elements or 4bytes each difference unit

    return 0;
}