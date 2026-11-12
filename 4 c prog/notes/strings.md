# 

1. strcpy :
- strcpy() copies one string into another.
> strcpy(destination, source);
- 
    1. Copies the source string, including the terminating \0.
    2. Does not allocate memory for the destination.
    3. Destination must have enough space.
    4. Source and destination must not overlap.
    5. Returns a pointer to the destination.

2. strcat() in C
strcat() concatenates (joins) two strings.
> strcat(destination, source);
- 
    1. Appends the source string at the end of the destination string.
    2. The original source remains unchanged.
    3. Destination must have enough memory for both strings and \0. Otherwise, it causes undefined behavior.
    4. The terminating \0 of the destination is overwritten by the first character of the source.
    5. Returns a pointer to the destination.
    6. Source and destination must not overlap.



## Examples :
1. 
char str1[] = "Akash";
char str2[] = {'A', 'k', 'a', 's', 'h'};
> int n1 = sizeof(str1)/sizeof(str1[0]);
> int n2 = sizeof(str2)/sizeof(str2[0]);
- n1= 6 , n2 = 5
> When an array is initialized with string in double quotes, compiler adds a ‘\0′ at the end.
-  sizeof(str1) is 6 because it includes the null terminator, while sizeof(str2) is 5 because it does not include a null terminator.

2. 
```c
char c[] = "GATE2011";
char *p =c;
printf("%s", p + p[3] - p[1]) ;
```
> p+69-65 = p+4 => P[4]
- Prints all charters from P[4]

3. 
```c
char str[] = "ravindrar";
printf("%s %s %s\n", &str[5], &5[str], str+5);
printf("%c %c %c\n", *(str+6), str[6], 6[str]);
```
> drar drar drar 
> r r r

4. 
If '\0' comes at any place inside string , it doesnt print anymore. 

5. 
```c
char str[] = "%d %c", arr[] = "GatesQuiz";
printf(str, 0[arr], 2[arr + 3]);
```
- 2[arr + 3] = arr[2+3]
