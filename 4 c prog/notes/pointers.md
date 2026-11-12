#
> everything is passed by value in C. We only get the effect of pass by reference using pointers.

1. *ptr += 5; increment the value at ptr by 5.
2. (*ptr)++; increment the value at ptr by 1.
3. printf("%td\n", (char*)ptr2 - (char*)ptr1); 
> Pointer arithmetic: difference in bytes or 1 byte each difference unit cz char is 1 byte
printf("%td", (int*)ptr2 - (int*)ptr1); 
> Pointer arithmetic: difference in number of elements or 4bytes each difference unit

4. pointer typecasting, memory representation and Endianness.
char *x;
int a = 512;
x = (char *) &a;
x[0] = 1;
x[1] = 2;
printf("%d\n",a);
> The output depends on the machine's byte order. On a typical x86/x64 machine, the output is 513.
- 512:
00000000 00000000 00000010 00000000
- Memory representation (Little Endian). Hex numbers
00              02                 00             00
x[0]            x[1]              x[2]             x[3]

x[0] = 1;
> changes the bit unit 00 to 01

5. *&*&*ptr = *ptr.
> printf : *ptr	=> First character (H)

6. 
```c
#include<stdio.h>
void fun(int arr[])
{
int i;
int arr_size = sizeof(arr)/sizeof(arr[0]);
for (i = 0; i < arr_size; i++)
printf("%d ", arr[i]);
}
int main(){
int arr[4] = {10, 20 ,30, 40};
fun(arr); 
}
```
int arr_size = sizeof(arr)/sizeof(arr[0]);
> sizeof(arr) = size of pointer (typically 8 bytes on a 64-bit system) cz when an array is passed to a function, it decays into a pointer.
==> 8/4 = 2 elements will be printed.

7. 
```c
char *t;
t = (p += sizeof(int))[-1];
```
- p+4 => 5th el in array  
> The negative index ( -1 ) will give the string which is one position behind the current position of p. 

8. int (*fp)(int *);
- Breakdown:
    - fp → pointer name.
    - *fp → pointer.
    - (int *) → function takes an integer pointer as argument.
    - int → function returns an integer.

9. 
int a = 10;
int *p = &a;
int **q = &p;

1. 
```c
void fun(int *x)
{
    x = NULL;
}
fun(p);
```
- x receives a copy of p.
- Changing x does not change p.

2. 
```c
void fun(int x)
{
    x = 50;
}
fun(*p);
```
- x receives the value 10.
- Changing x does not change a

3. To change a:
```c
void fun(int *x)
{
    *x = 50;
}
fun(p);
```
- Now a = 50.

4. Passing **q — value
```c
void fun(int x)
{
    x = 50;
}
fun(**q);
```
- **q gives the value of a.
- Again, only a copy is passed.

5. Passing a double pointer (int **)
```c
void fun(int ** x)
{
    static int q = 10;
    *x = &q;
}
fun(**q);
```

6. 
```c
int (*p)[R][C];
printf("%d", sizeof(*p));
```
> 800



## Near, Far and Huge Pointers in C 
- Near, Far and Huge pointers are memory-model concepts associated with `16-bit Intel 8086 architecture and Turbo C.`
- They were used to access memory in systems where the address space was larger than the directly accessible segment.
- These are `not standard C pointer` types. They are compiler/platform-specific extensions.

1. Near pointer = 2 bytes
Near → Offset only (16 bits).

2. Far pointer  = 4 bytes
Far → Segment + Offset (32 bits).

3. Huge pointer = 4 bytes
Huge → Segment + Offset (32 bits).

