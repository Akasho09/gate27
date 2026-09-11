# Operators in C
- An operator is a symbol that tells C to perform an operation on one or more values.
- For example:
- int c = a + b;
Here:
- a and b → operands
- + → operator
- a + b → expression

## C has several categories of operators.

1. Arithmetic operators
Used for mathematical calculations.
- 
| Operator | Meaning        | Example | Result |
| -------- | -------------- | ------- | ------ |
| `+`      | Addition       | `5 + 2` | `7`    |
| `-`      | Subtraction    | `5 - 2` | `3`    |
| `*`      | Multiplication | `5 * 2` | `10`   |
| `/`      | Division       | `5 / 2` | `2`    |
| `%`      | Remainder      | `5 % 2` | `1`    |

2. Assignment operators
- Used to assign or update values.
- Basic assignment
int x = 10;
= means:
- Put the value on the right into the object on the left.
- It does not mean mathematical equality.

### Compound assignment
- Instead of:
x = x + 5;
- you can write:
> x += 5;
- All the common compound operators are:
x += 5   → x = x + 5
x -= 5   → x = x - 5
x *= 5   → x = x * 5
x /= 5   → x = x / 5
x %= 5   → x = x % 5
- There are also bitwise compound assignments:
x &= y;
x |= y;
x ^= y;
x <<= 2;
x >>= 2;

3. Relational operators
- Used to compare values.
| Operator | Meaning               |
| -------- | --------------------- |
| `==`     | Equal to              |
| `!=`     | Not equal to          |
| `>`      | Greater than          |
| `<`      | Less than             |
| `>=`     | Greater than or equal |
| `<=`     | Less than or equal    |

4. Logical operators
- Used to combine or negate conditions.
- 
| Operator | Meaning     |   |            |
| -------- | ----------- | - | ---------- |
| `&&`     | Logical AND |   |            |
| `        |             | ` | Logical OR |
| `!`      | Logical NOT |   |            |

5. Increment and decrement operators
- These change a value by 1.
> x++;
### Prefix vs postfix
++x;
x++;

6. Bitwise operators
- These operate directly on the bits of integer values.
- This is especially important in C because C gives you low-level control over memory and hardware.
- The operators are:
```yml
&    AND
|    OR
^    XOR
~    NOT
<<   left shift
>>   right shift
```

8. Conditional / ternary operator
- C has a special operator:
> condition ? value_if_true : value_if_false
> It's called the conditional operator and is C's only ternary operator.

9. sizeof operator
- sizeof tells you the size of a type or object in bytes.

10. Address-of operator — &
- This & is different from bitwise AND depending on context.

11. Dereference operator — *
- When used with a pointer, * means dereference.
int age = 20;
int *ptr = &age;
printf("%d", *ptr);
- *ptr means:
    - Go to the address stored in ptr and access the value there.

12. Member access operators
```yml
.    member access
->   member access through pointer
```

13. Comma operator
- The comma , can act as an operator in expressions.

14. Cast operator
- You can explicitly convert a value to another type:
int a = 5;
int b = 2;

float result = (float)a / b;

> (float)a is cast 

15. Operator precedence
Highest
   ↓
```yml
                ()
                []
                -> .
                postfix ++ --

                unary ++ -- ! ~ * & sizeof (cast)

                * / %

                + -

                < <= > >=

                == !=

                &

                ^

                |

                &&

                ||

                ? :

                = += -= *= /= %= ...

                ,
```

   ↓
Lowest


## Mod operator

