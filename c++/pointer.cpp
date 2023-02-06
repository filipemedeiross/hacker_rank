#include <stdio.h>

void update(int *a, int *b) {
    int a_ = *a, b_ = *b;

    *a = a_ + b_;

    if (a_ > b_)
        *b = a_ - b_;
    else
        *b = b_ - a_;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);

    update(pa, pb);
    
    printf("%d\n%d", a, b);

    return 0;
}