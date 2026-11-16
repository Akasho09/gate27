# 

## 

1. (*f1)() = f1().
- This is also treated as a function call in C.

2. Inside main(), int f1(); is a function declaration (prototype).

3. 
```c
char first(int (*)(char, float));

int second(char, float);

VALID DECLATIONS :
first(*second); // Dereferenced function designator
first(second); // Address of function
first(&second); // Function-to-pointer conversion
first( ******second ); //Equi to first(second);
```


