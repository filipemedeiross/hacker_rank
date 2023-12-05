#include <stdio.h>


int main () {
    int t, n;
    long int p, q, r;
    long int s3, s5, s15, sum;

    scanf("%d", &t);
    
    for (int a0 = 0; a0 < t; a0++) {
        scanf("%d", &n);
        
        n--;

        p = n / 3;
        q = n / 5;
        r = n / 15;

        s3  = (3 * p * (p + 1)) / 2;
        s5  = (5 * q * (q + 1)) / 2;
        s15 = (15 * r * (r + 1)) / 2;

        sum = s3 + s5 - s15;
        printf("%ld\n", sum);
    }
    
    return 0;
}