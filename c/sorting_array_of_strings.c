#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_ALPHA 26


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

int lexicographic_sort_reverse(const char* a, const char* b) {
    return !lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i, n1, n2;
    const char *ch;
    int charr1[LEN_ALPHA] = {0};
    int charr2[LEN_ALPHA] = {0};

    for (ch = a; *ch; ch++)
        if (!charr1[*ch - 'a'])
            charr1[*ch - 'a'] = 1;

    for (ch = b; *ch; ch++)
        if (!charr2[*ch - 'a'])
            charr2[*ch - 'a'] = 1;

    n1 = n2 = 0;
    for (i = 0; i < LEN_ALPHA; i++) {
        n1 += charr1[i];
        n2 += charr2[i];
    }

    if (n1 > n2) return 1;
    else if (n1 < n2) return 0;
    
    return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int n1, n2;
    const char *ch;

    n1 = n2 = 0;
    for (ch = a; *ch; ch++)
        n1 += 1;

    for (ch = b; *ch; ch++)
        n2 += 1;

    if (n1 > n2)
        return 1;
    else if (n1 < n2)
        return 0;
    
    return lexicographic_sort(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)){
    int i, j, min;
    char *temp;

    for (i = 0; i < len - 1; i++) {
        min = i;

        for (j = i + 1; j < len; j++)
            if ((*cmp_func)(arr[min], arr[j]))
                min = j;

        temp     = arr[i];
        arr[i]   = arr[min];
        arr[min] = temp;
    }
}


int main () {
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**) malloc(n * sizeof(char*));
  
    for (int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}