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


