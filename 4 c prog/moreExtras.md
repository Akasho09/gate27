# 

1. printf(“%d”, printf(“tim”));
> tim3

2. If a b c is the input then the following program fragment results in:
char x, y, z;
- printf(“%d”, scanf(“%c %c %c”, &x, &y, &z));

> 3

3. 3 * (y–8)/9 and (y–8)/9 * 3 
> may or may not yield the same value

4. putchar() is a standard library function in C used to print a single character to the standard output (screen).
int i = 263.
putchar(i);
> i is >255 ==> last 7 bits are considered which translate to 7 ie [BELL] in ASCII

5. getchar() is a standard input function in C used to read a single character from the keyboard.

6. void * type pointers cannot be de-referenced. We must `type cast` them before de-referencing.

1. Incorrect
```c
#include<stdio.h>
int main()
{
int a = 12;
void *ptr = (int *)&a;
printf("%d", *ptr);
getchar();
return 0;
}
```

2. Correct
```c
#include<stdio.h>
int main()
{
int a = 12;
void *ptr = (int *)&a;
> printf("%d", *(int *)ptr);
getchar();
return 0;
}
```