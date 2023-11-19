#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct triangle {
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float area (int a, int b, int c) {
    float p, area;
    
    p = (float) (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    return area;
}

void sort_by_area(triangle* tr, int n) {
	int i, j, min;
    float areas[n];
    triangle temp;

    for (i = 0; i < n; i++)
        areas[i] = area(tr[i].a, tr[i].b, tr[i].c);

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++)
            if (areas[min] > areas[j])
                min = j;

        temp   = tr[i];
        tr[i]  = tr[min];
        tr[min] = temp;

        areas[min] = areas[i];
    }
}


int main () {
	int n;
    triangle *tr;

	scanf("%d", &n);
	
    tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);

	sort_by_area(tr, n);
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);

	return 0;
}