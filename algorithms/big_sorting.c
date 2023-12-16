#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline ();
char* ltrim (char*);
char* rtrim (char*);

int parse_int (char*);

int cmpsint (int lenx, int leny, char *strx, char* stry) {
    if (lenx < leny)
        return -1;
    if (lenx > leny)
        return 1;

    return strcmp(strx, stry);
}

void quicksort (char** unsorted, int* len, int left, int right) {
    int i, j, lenpivot, temp;
    char *strpivot, *strtemp;

    i = left;
    j = right;

    lenpivot = len[(left + right) / 2];
    strpivot = unsorted[(left + right) / 2];

    do {
        while (cmpsint(len[i], lenpivot, unsorted[i], strpivot) < 0 && i < right) i++;
        while (cmpsint(len[j], lenpivot, unsorted[j], strpivot) > 0 && j > left) j--;

        if (i <= j) {
            strtemp     = unsorted[i];
            unsorted[i] = unsorted[j];
            unsorted[j] = strtemp;

            temp   = len[i];
            len[i] = len[j];
            len[j] = temp;

            i++; j--;
        }
    } while (i <= j);

    if (left < j) quicksort(unsorted, len, left, j);
    if (i < right) quicksort(unsorted, len, i, right);
}

char** bigSorting (int unsorted_count, char** unsorted, int* result_count) {
    int *len;
    
    len = (int*) malloc(unsorted_count * sizeof(int));
    for (int i = 0; i < unsorted_count; i++)
        len[i] = strlen(unsorted[i]);

    *result_count = unsorted_count;
    quicksort(unsorted, len, 0, unsorted_count - 1);

    free(len);
    
    return unsorted;
}

int main () {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** unsorted = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* unsorted_item = readline();

        *(unsorted + i) = unsorted_item;
    }

    int result_count;
    char** result = bigSorting(n, unsorted, &result_count);

    for (int i = 0; i < result_count; i++)
        fprintf(fptr, "%s\n", *(result + i));

    fclose(fptr);

    return 0;
}

char* readline () {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
            break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
            break;

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
            data = '\0';
    } else {
        data = realloc(data, data_length + 1);

        if (!data)
            data = '\0';
        else
            data[data_length] = '\0';
    }

    return data;
}

char* ltrim (char* str) {
    if (!str)
        return '\0';

    if (!*str)
        return str;

    while (*str != '\0' && isspace(*str))
        str++;

    return str;
}

char* rtrim (char* str) {
    if (!str)
        return '\0';

    if (!*str)
        return str;

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
        end--;

    *(end + 1) = '\0';

    return str;
}

int parse_int (char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
        exit(EXIT_FAILURE);

    return value;
}