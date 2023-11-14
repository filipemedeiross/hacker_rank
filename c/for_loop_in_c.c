#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void print_number (int n) {
    switch (n) {
        case 1: printf("one\n"); break;
        case 2: printf("two\n"); break;
        case 3: printf("three\n"); break;
        case 4: printf("four\n"); break;
        case 5: printf("five\n"); break;
        case 6: printf("six\n"); break;
        case 7: printf("seven\n"); break;
        case 8: printf("eight\n"); break;
        case 9: printf("nine\n"); break;
        default:
            if (n % 2) printf("odd\n");
            else printf("even\n");
    }
}


int main () {
    int a, b;
    
    scanf("%d\n%d", &a, &b);
  	
    for (int n = a; n <= b; n++)
        print_number(n);

    return 0;
}