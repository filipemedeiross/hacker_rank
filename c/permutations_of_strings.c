#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lexicographic_sort(const char* a, const char* b) {
    const char *ch1, *ch2;

    ch1 = a, ch2 = b;
    while (*ch1 && *ch2) {
        if (*ch1 > *ch2)
            return 1;
        else if (*ch1 < *ch2)
            return 0;

        ch1++, ch2++;
    }

    return strlen(a) > strlen(b);
}

void string_sort(char** arr, const int len){
    int i, j, min;
    char *temp;

    for (i = 0; i < len - 1; i++) {
        min = i;

        for (j = i + 1; j < len; j++)
            if (lexicographic_sort(arr[min], arr[j]))
                min = j;

        temp     = arr[i];
        arr[i]   = arr[min];
        arr[min] = temp;
    }
}

int next_permutation(int n, char **s) {
    char *temp;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (lexicographic_sort(s[j], s[i])) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;

                i++;
                string_sort(s + i, n - i);

                return 1;
            }
        }
    }    

    return 0;
}


int main () {
	int n;
	char **s;
	
    scanf("%d", &n);
	
    s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}

	do {
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	
    for (int i = 0; i < n; i++)
		free(s[i]);
	
    free(s);
	
    return 0;
}