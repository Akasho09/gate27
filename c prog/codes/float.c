 #include <stdio.h>

int main() {
    
    float c = 3.145678901234;
    printf("The value of c is: %f\n", c);
    printf("The value of c is: %.10f\n", c);

    // > float typically gives about 6–7 significant decimal digits of precision.

    float d = 0.000145678901234;
    printf("The value of d is: %f\n", d);
    printf("The value of d is: %.10f\n", d);

}