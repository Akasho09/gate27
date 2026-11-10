# 

## 1. Floating-point data types
1. float	: 4 bytes	6–7 decimal digits
2. double	: 8 bytes	15–16 decimal digits
3. long double	: 8, 12 or 16 bytes	Implementation-dependent

- Suffixes:
    - f or F → float
    - No suffix → double
    - l or L → long double
- example:
```yml
3.14f   // float
3.14    // double
3.14L   // long double
```

2. Arithmetic operators
Floating-point numbers support these arithmetic operators:

> The modulus operator % cannot be used with floating-point operands.
- For floating-point remainder, use `fmod():`
```c
#include <math.h>

double r = fmod(5.5, 2.0);  // 1.5
```
> The modf() function in C splits a floating-point number into its integer and fractional parts.

```c
int a = (int) 5.9;   // 5
int b = (int) -5.9;  // -5

float x = 5 / 2;  // 2.0, NOT 2.5

```

## Round off n Related Functions :
1. ceil(x)	: Smallest integer ≥ x	
- ceil(4.2)	5.0
>  Towards positive infinity.

2. floor(x)	: Largest integer ≤ x	
- floor(4.8)	4.0
> Towards negative infinity.

3. round(x)	: Nearest integer; 
- round(4.5)	5.0
> Nearest integer, ties away from zero.

4. trunc(x)	Remove fractional part	
- trunc(4.9)	4.0
> Towards zero.

5. rint(x)	Round according to current rounding mode	
- rint(4.5)	Usually 4.0
6. nearbyint(x)	: Like rint, but does not raise the inexact exception	
- nearbyint(4.5)	Usually 4.0

