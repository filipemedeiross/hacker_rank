#include <stdio.h>


int main () {
    int t;
    long n, t0, t1, t2, sum;

    scanf("%d", &t);
    
    for(int a0 = 0; a0 < t; a0++){
        scanf("%ld", &n);

        t0 = 0;
        t1 = 0;
        t2 = 2;

        sum = 0;
        while (t2 < n) {
            sum += t2;

            t0 = t1;
            t1 = t2;
            t2 = 4*t1 + t0;
        }

        printf("%ld\n", sum);
    }
    
    return 0;
}