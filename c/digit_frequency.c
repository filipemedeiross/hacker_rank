#include <stdio.h>
#define DIGITS 10

int main() {
    int count[DIGITS];
    char ch;

    for (int i = 0; i < DIGITS; i++)
        count[i] = 0;

    do {
        ch = getchar();

        if (ch >= '0' && ch <='9') count[ch - '0']++;
    } while (ch != -1);

    for (int i = 0; i < DIGITS; i++)
        printf("%d ", count[i]);

    return 0;
}