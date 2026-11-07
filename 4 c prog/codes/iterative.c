#include <stdio.h>

int main() {
    int j=0;
    for(int i=0; i<5; i++) {
        printf("Iteration %d , %d\n", i, j);
        j++;
    }
    printf("J  %d\n", j);

    while(j<10) {
        printf("J is %d\n", j);
        j++;
    }
    printf("Final J: %d\n", j);
}