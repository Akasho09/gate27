#include <stdio.h>

int main(){
    // short a = 32768;
    // printf("Val %d\n" ,a );
    // printf("Val %u" ,a );

int a=0, b=0; 
a=(a=4)||(b=1); 
if (a&&b) printf("Programming");
else printf("PankajSharma");
printf("%d",b); 
// Output: PankajSharma0 cz b=1 never executed due to short-circuit evaluation of the logical OR operator (||).
}