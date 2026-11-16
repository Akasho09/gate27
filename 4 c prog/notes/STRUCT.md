# 

## A Structure (struct) in C 
is a user-defined data type that allows us to group variables of different data types under a single name.
```c
struct Student {
    int roll;
    char name[20];
    float cgpa;
};

struct Student s1, s2;

    s1.roll = 10;
    s1.marks = 95.5;

    struct Student *ptr = &s1;

    printf("%d", ptr->roll);

struct Student s[3] = {
    {1, 90},
    {2, 85},
    {3, 95}
};

---- OR

struct Student {
    int roll;
    float marks;
} s1, s2;

```

1. .	: Access member using structure variable
2. ->	: Access member using structure pointer

### 7. Nested Structures
```c
struct Date {
    int day, month, year;
};

struct Student {
    int roll;
    struct Date dob;
};
```

## Structure Padding
- Structure Padding is the extra memory bytes inserted by the compiler between structure members or at the end of a structure to satisfy memory alignment requirements. 

> A member must start at an offset that is a multiple of its alignment requirement.

> Arrange larger-alignment members first and smaller-alignment members later to potentially reduce padding.


## A Union in C 
is a user-defined data type that allows multiple members of different data types to share the same memory location.
```c
union Data {
    int i;
    float f;
    char c;
};

union Data d1, d2;
d1.i = 10;
printf("%d", d1.i);


```
