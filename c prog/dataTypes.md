# data types
- A data type tells C what kind of data a variable will store.

```yml
x (int):
00000000 00000000 00000000 01000001   ← usually 4 bytes

c (char):
01000001                             ← usually 1 byte
```
> both are stored as binary 65 but at runtime its decided what to print (format specifier tells printf how to interpret that value.)

## 3. Main categories of C data types
```yml
C DATA TYPES
│
├── Basic / fundamental types
│   ├── char
│   ├── int
│   ├── float
│   ├── double
│   └── _Bool
│
├── void
│
├── Derived types
│   ├── arrays
│   ├── pointers
│   └── functions
│
└── User-defined / composite types
    ├── struct
    ├── union
    └── enum
```
- There are also type qualifiers such as:
const
volatile
restrict
_Atomic

> A pointer is a derived data type because its type is constructed from another type (int → int*), not because a pointer is an integer.


## 4. int — integers
- int stores integer numbers.
int age = 20;
int marks = 95;
int temperature = -10;
> No decimal portion.

### How big is int?
- This is important:
> C does not guarantee that int is exactly 4 bytes on every implementation.
- It guarantees minimum ranges and relationships between integer types.
- On most modern systems:
> int = 4 bytes
- A commonly encountered range is:
```yml
-2,147,483,648
        to
 2,147,483,647
```
- But you should use sizeof() and <limits.h> rather than blindly assuming sizes.
- 
| Type                     | Meaning                   | Typical size* |
| ------------------------ | ------------------------- | ------------: |
| `short int`              | Smaller integer           |       2 bytes |
| `int`                    | Normal integer            |       4 bytes |
| `long int`               | Larger integer            |  4 or 8 bytes |
| `long long int`          | Very large integer        |       8 bytes |
| `unsigned int`           | Only 0 and positive       |       4 bytes |
| `unsigned short int`     | Smaller, only positive    |       2 bytes |
| `unsigned long int`      | Larger, only positive     |  4 or 8 bytes |
| `unsigned long long int` | Very large, only positive |       8 bytes |

## Ranges :

1. int
-2^(n-1) to +2^(n-1)-1
> n is no of bits.

2. int
0 to + (2^n)-1
> n is no of bits.

## float :
- A floating-point value is represented differently from an integer.
- Conceptually, it contains information corresponding to:
    - sign
    - exponent
    - fraction/significand
- A typical C float uses 32 bits (4 bytes) and provides approximately 6–7 significant decimal digits of precision.
- 123.4567
- 0.0001234567
> It means significant digits, not simply digits after the decimal point.
- So don't think:
    - float can store exactly 6 digits after the decimal.
- Instead think:
> float typically gives about 6–7 significant decimal digits of precision.
| Type          |             Typical size | Approx. decimal precision |
| ------------- | -----------------------: | ------------------------: |
| `float`       |                  4 bytes |    6–7 significant digits |
| `double`      |                  8 bytes |  15–16 significant digits |
| `long double` | implementation-dependent |      ≥ `double` precision |


## short int 
short age;
short score;
short temperature;

## 19. Integer overflow
> Unsigned arithmetic is defined modulo one more than its maximum value.
- same is for short also

> Signed overflow is different => → undefined behavior

> similarly for char system also %256 here