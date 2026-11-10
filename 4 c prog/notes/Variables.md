# Variables in C

## 1. What is a variable?
> A variable is a named location in the computer's memory that stores a value.
- Think of it like a labeled box:
```yml
       Memory
   ┌─────────────┐
   │     25      │
   └─────────────┘
        ↑
      age
```
- Here:
age → name of the variable
25 → value stored in it
int → type of data it can store
- In C:
int age = 25;
This means:
"Create a variable called age, capable of storing an integer, and put 25 inside it."

## 2. Why do we need variables?
- Programs need to store and manipulate data.
- Without variables, it would be extremely difficult for programs to remember and manipulate information.

## 3. Basic syntax
- The general syntax is:
> data_type variable_name;

- For example:
int age;
float height;
char grade;
- You can also assign a value immediately:
int age = 20;
float height = 5.9;
char grade = 'A';

> This is called `initialization`.

## 4. Declaration vs initialization vs assignment
- These three terms are important.
1. Declaration
- You're telling C that a variable exists:
int age;
- No value has been explicitly assigned.

2. Initialization
- You're creating the variable and giving it its first value:
int age = 20;

3. Assignment
- You're changing the value of an existing variable:
age = 25;
- So:
int age = 20;  // declaration + initialization
age = 25;      // assignment

## 5. Data types
- Every variable in C has a data type.
- The type tells C:
    - What kind of data is this variable going to store, and how should that data be interpreted?
| Type             | Stores                | Example    |
| ---------------- | --------------------- | ---------- |
| `int`            | Whole numbers         | `25`       |
| `float`          | Decimal numbers       | `3.14`     |
| `double`         | More precise decimals | `3.141592` |
| `char`           | One character         | `'A'`      |
| `_Bool` / `bool` | True/false            | `true`     |


## 11. Variable names
- You need to follow certain rules when naming variables.
- Valid
```c
int age;
int studentAge;
int student_age;
int age2;
int _age;
```
- Invalid
```c
int 2age;        // ❌ cannot start with a number
int student-age; // ❌ '-' isn't allowed in identifiers
int student age; // ❌ spaces aren't allowed
```
- A variable name:
> can contain letters
> can contain digits
> can contain _
> cannot start with a digit
> cannot contain spaces
> cannot be a C keyword

## 12. C is case-sensitive
These are completely different variables:
int age;
int Age;
int AGE;
- C treats them as three different names.

## 13. Keywords cannot be variable names
- C has reserved words called keywords.
- For example:
```c
int
float
char
if
else
while
for
return
void
struct
```

## 14. Changing a variable
One of the most important properties of a variable is that its value can change.
```c
int age = 20;

age = 21;
age = 22;
age = 23;
```
> Think of it as replacing the contents of the box.


## 15. Variables and memory
- This is where things become really interesting.
- Suppose you write:
int age = 20;
- The computer reserves memory for an integer.
- Conceptually:
```yml
Memory address
     ↓
  1000
┌──────────┐
│    20    │
└──────────┘
     ↑
    age
```
- The actual address will be different on your machine.
- You can see it using the & operator:
> printf("%p", (void*)&age);
- &age means:
"Give me the memory address of age."


## 18. Uninitialized variables
- Consider:
int age;
printf("%d", age);
> For a local automatic variable, age has an indeterminate value because you didn't initialize it.

## 20. Constants
- If you want a value that shouldn't be modified through that variable, use const:
> const int DAYS_IN_WEEK = 7;
- const means the object should not be modified through that identifier.

## 23. Format specifiers
- When printing variables with printf, you use format specifiers.
```c
%d → int
%f → floating-point output
%c → char
%s → string
%p → pointer/address
```
> There are more, including length modifiers such as %ld, %lld, %zu, etc.

## 31. Global variables
- A variable declared outside functions has file scope.
```c
#include <stdio.h>

int score = 100;

int main() {
    printf("%d", score);

    return 0;
}
```
- Here score is a global/file-scope variable.
> Global variables have static storage duration, meaning they exist for the entire execution of the program.

## 33. Storage duration
- The main categories are:
1. Automatic
- Typical local variables:
```c
void f() {
    int x = 10;
}
```
- They generally come into existence when execution enters their block and cease to exist when it leaves.

2. Static
```c
static int x;
```
- and file-scope variables.
- They exist for the entire execution of the program.


3. Allocated
- Memory obtained dynamically using:
```c
malloc()
calloc()
realloc()
```
and released with:
```c
free()
```
- This is dynamic memory, which you'll encounter when learning pointers.

## 34. static variables
```c
#include <stdio.h>

void counter() {
    static int count = 0;

    count++;

    printf("%d\n", count);
}

int main() {
    counter();
    counter();
    counter();

    return 0;
}
```
- Output:
```yml
1
2
3
```

## 35. Variable type conversion
- C can convert between different types.
- Example:
```c
int x = 10;
double y = x;
```
> x gets converted to a double when assigned to y.
- So:
x = 10
y = 10.0

## 36. Explicit type casting
> You can explicitly tell C to convert something:
```c
int a = 5;
int b = 2;

double result = (double)a / b;
```
- (double)a means:
- Convert a to a double for this expression.
- Result:
    - 2.5

## Literal
1. Variable
int age = 20;
- age is a variable.

2. Literal
20
- 20 is an integer literal.

3. Constant object
const int days = 7;


