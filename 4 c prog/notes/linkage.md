# Linkage 
determines whether an identifier (variable or function name) declared in different scopes or source files refers to the same entity.
- C has three types of linkage:
1. External linkage
2. Internal linkage
3. No linkage

1. External Linkage
An identifier has external linkage when it can refer to the same entity across multiple source files.
- Global variables have external linkage by default.
- Functions have external linkage by default.
- Use extern to refer to an externally defined variable or function.

- File 1: main.c
```c
int x = 10;  // External linkage

int main() {
    return 0;
}
```

- File 2: test.c
```c
extern int x;

void display() {
    printf("%d", x);  // Accesses x from main.c
}
```
- Both declarations refer to the same variable x.

2. Internal Linkage
An identifier has internal linkage when it can be accessed only within the same translation unit (source file after preprocessing).
- Use the static keyword at file scope.
```c
static int x = 10;

static void display() {
    printf("%d", x);
}
```
- Even if another source file declares:
extern int x;
- it cannot access this static variable.
- Remember: File-scope static restricts visibility to the current translation unit.

3. No Linkage
An identifier has no linkage when it represents a separate entity and cannot refer to the same identifier in another scope.

Examples include:
- Local variables.
- Function parameters.
- Block-scope variables.
```c
void fun() {
    int x = 10;  // No linkage
}
```
- Even if another function declares a local variable named x, it is a different variable.


