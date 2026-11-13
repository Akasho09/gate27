#

## typedef in C
typedef is a keyword in C used to create an alias (another name) for an existing `data type`.
- It does NOT create a new data type. It only provides an alternative name.
```c
typedef int INTEGER;

int main() {
    INTEGER x = 10;
    printf("%d", x);
}
```
> i a; = int *a;
> typedef is a storage-class specifier according to C grammar.
- Unlike other storage-class specifiers, it does not determine storage duration or linkage. It creates a type alias.
==> typedef static int *i; ===> Compiler Error -> Multiple Storage classes for a.


