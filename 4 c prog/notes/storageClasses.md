# Storage Classes in C
Storage classes in C define the properties of variables and functions, such as:
1. Scope – Where can the variable be accessed?
2. Lifetime – How long does the variable exist in memory?
3. Default value – What is its default initialization value?
4. Storage location – Where is it stored (conceptually)?

- C has four commonly taught storage classes:
1. auto
2. register
3. static
4. extern


## 1. auto Storage Class
- Default storage class for local variables.
- Declared inside a function or block.
- Scope: Local (block scope).
- Lifetime: Until the block finishes execution.
- Default value: `Garbage` value (indeterminate value).
- in RAM.


2. register Storage Class
- Requests the compiler to store the variable in a CPU register for faster access.
- Scope: Block scope.
- Lifetime: Until the block finishes execution.
- Default value: Garbage value (indeterminate).
- Address operator & cannot be applied to a variable declared with register.
```c
void fun() {
    register int x = 10;
    // printf("%p", &x);  // Constraint violation
}
```
Important:
- Compiler may ignore the register request.
- Modern compilers decide register allocation themselves.
- Cannot declare a global variable as register.

3. static Storage Class
A static variable retains its value throughout the program's execution.

Properties:
- Default value: 0.
- Lifetime: Entire program execution.
- Memory is allocated only once.

- There are two important cases:
    1. Local static variable
    - Scope: Block scope.
    - Lifetime: Entire program.
    - Retains its value between function calls.
    #include <stdio.h>
```c
void fun() {
    static int x = 0;
    x++;
    printf("%d ", x);
}

int main() {
    fun();
    fun();
    fun();
}
```
> Global or static variable must be initialized using a constant expression in C.
int x = 10;
static int y = x;  // Invalid


2. Global static variable
- Scope: File scope.
- Lifetime: Entire program.
- Internal linkage: Accessible only within the same source file.
static int x = 10;

4. extern Storage Class
- Used to declare a global variable or function defined elsewhere.
- Scope: Depends on where it is declared.
- Lifetime: Entire program for an object with static storage duration.
- Default value: 0 for a zero-initialized global definition.
- Does not create a new variable when used as an external declaration.
```c
#include <stdio.h>

int x = 100;

int main() {
    extern int x;
    printf("%d", x);
}
```

## Type Qualifiers in C
Type qualifiers are keywords used to modify the properties or behavior of a data type or variable without changing its basic data type.

C has four commonly recognized type qualifiers:
1. const
2. volatile
3. restrict (C99)
4. _Atomic (C11)

1. const
- Makes a variable read-only through that identifier.
- Its value cannot be modified after initialization through that identifier.
- Must be initialized at declaration for ordinary non-extern block-scope const objects? No — initialization is not mandatory in C.
```c
const int x = 10;

x = 20;  // Compilation error

const int *p;       // Pointer to constant integer
int *const p = &x;  // Constant pointer
const int *const p = &x; // Both constant
```

- EXAMPLES : 
1. const int *ptr : Pointer to constant integer
```c
int i = 10;
const int *ptr = &i;
```
- Here:
    - i is a normal integer.
    - ptr is a pointer to a constant integer.
    - ptr can point to another integer.
    - But the value cannot be modified through ptr

2. int *const ptr	: Constant pointer to integer
```c
int i = 10;

const int *p = &i;
int *const q = &i;

A. *p = 20; Invalid
B. p = NULL; valid
C. *q = 20; valid
D. q = NULL; Invalid
```

3. const int *const ptr	: Constant pointer to constant integer
    

2. volatile
- Tells the compiler that the variable's value may change unexpectedly.
- Prevents the compiler from assuming that the value remains unchanged between accesses.
- Commonly used in hardware registers, interrupt service routines and memory-mapped I/O.
```c
volatile int x = 10;

while (x == 10) {
    // x may change unexpectedly
}
```

3. restrict (C99)
- Used with pointers.
- Indicates that, for a particular execution of a block, the pointer is the primary means of accessing the object it points to.
- Helps the compiler perform optimizations.

4. _Atomic (C11)
- Used to perform atomic operations on objects.
- An atomic operation appears indivisible to other threads.
- Useful in multithreaded programming.
```c
#include <stdatomic.h>

_Atomic int x = 0;

x++;
```


