# statement
- A statement in C is an instruction that tells the computer to perform some action. Most C statements end with a semicolon ;.
```c
int a = 10;
printf("%d", a);
a++;
```
- Each of these is a statement.

1. Declaration statement
- Declares a variable.
```c
int a;
float x;
char ch;
```
- You can also initialize while declaring:
- int a = 10;

2. Expression statement
- An expression followed by ;.
```c
a = 10;
a++;
a = b + c;
printf("Hello");
```
- Even a function call such as printf() is an expression statement.

3. Compound statement / Block
- A group of statements enclosed in { }.
```c
{
    int a = 10;
    a++;
    printf("%d", a);
}
```
- A block is treated as a single statement syntactically.
- You'll see this heavily with if, loops, and functions.


4. Selection statements
- Used to make decisions.
    1. if
    ```c

    if (a > 10)
        printf("Greater");
    ```

    2. if-else
    ```c

    if (a > 10)
        printf("Greater");
    else
        printf("Smaller");
    ```

    3. switch
    ```c
    switch (a) {
        case 1:
            printf("One");
            break;

        case 2:
            printf("Two");
            break;

        default:
            printf("Other");
    }
    ```

5. Iteration statements
- Used for repetition.
    1. while
    ```c
    while (a < 10) {
        a++;
    }
    ```

    2. do-while
    ```c
    do {
        a++;
    } while (a < 10);
    ```

    3. for
    ```c
    for (int i = 0; i < 10; i++) {
        printf("%d", i);
    }
    ```

6. Jump statements
- Change the normal flow of execution.

| Statement  | Purpose                         |
| ---------- | ------------------------------- |
| `break`    | Exit a loop or `switch`         |
| `continue` | Skip to the next loop iteration |
| `return`   | Exit a function                 |
| `goto`     | Jump to a labeled statement     |

---

```yml
;
```
> is an empty (null) statement