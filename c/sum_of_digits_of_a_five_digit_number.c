#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_MOD 100000

int main () {
    int n, sum;
    int div, mod;
    
    scanf("%d", &n);
    
    sum = 0;
    for (div = 1, mod = 10; mod <= MAX_MOD; div = mod, mod *= 10)
        sum += n % mod / div;
 
    printf("%d\n", sum);
       
    return 0;
}