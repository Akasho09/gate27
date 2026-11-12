# SWAPPING 2 NUMS :

1. Using a Third (Temporary) Variable
```C
#include <stdio.h>

int main() {
    int a = 10, b = 20, temp;

    temp = a;
    a = b;
    b = temp;

    printf("a = %d, b = %d", a, b);
    return 0;
}
```

2. Without Third Variable (Using Addition and Subtraction)
```C
int a = 10, b = 20;

a = a + b;
b = a - b;
a = a - b;

```
> Disadvantage: Integer overflow can occur if the sum exceeds the maximum integer value.

3. Without Third Variable (Using Multiplication and Division)
```c
int a = 10, b = 20;

a = a * b;
b = a / b;
a = a / b;
```
- Disadvantages:
    - Does not work if either number is zero.
    - May cause integer overflow.
    - Not suitable for floating-point values.

4. Using XOR Bitwise Operator
```c
a = a ^ b;
b = a ^ b;
a = a ^ b;
```
- Note: XOR swapping works for integer types but should not be used when both variables refer to the same memory location (such as aliased pointers).
> If both pointers point to the same integer, the value becomes zero instead of remaining unchanged.

5. Using Pointers and a Temporary Variable
```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10, b = 20;

    swap(&a, &b);

    printf("%d %d", a, b);
    return 0;
}
```

6. Using Pointers Without a Temporary Variable (XOR)
```c
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
```
- Disadvantages
> Null pointer risk: If invalid or NULL pointers are passed and dereferenced, undefined behavior occurs.
> If both pointers point to the same integer, the value becomes zero instead of remaining unchanged.

