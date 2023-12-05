#include <stdio.h>


int main () {
    int t, n;
    long int sum;

    scanf("%d", &t);
    
    sum = 0;
    for (int a0 = 0; a0 < t; a0++) {
        scanf("%d", &n);
        
        n--;

        long int p = n / 3;
        long int q = n / 5;
        long int r = n / 15;

        long int s3 = (p * (2 * 3 + (p - 1) * 3)) / 2;
        long int s5 = (q * (2 * 5 + (q - 1) * 5)) / 2;
        long int s15 = (r * (2 * 15 + (r - 1) * 15)) / 2;

        sum = s3 + s5 - s15;
        printf("%ld\n", sum);
    }
    
    return 0;
}