#include <stdio.h>
#include <stdlib.h>


int* total_number_of_books;

int** total_number_of_pages;


int main () {
    int type_of_query, x, y;
    int total_number_of_shelves, total_number_of_queries;

    scanf("%d", &total_number_of_shelves);
    scanf("%d", &total_number_of_queries);

    total_number_of_books = (int*) malloc(sizeof(int) * total_number_of_shelves);
    total_number_of_pages = (int**) malloc(sizeof(int*) * total_number_of_shelves);

    for (int i = 0; i < total_number_of_shelves; i++)
        *(total_number_of_books + i) = 0;
    
    while (total_number_of_queries--) {
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            scanf("%d %d", &x, &y);
            
            total_number_of_books[x]++;
            total_number_of_pages[x] = (int*) realloc(total_number_of_pages[x], sizeof(int) * total_number_of_books[x]);
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;

        } else if (type_of_query == 2) {
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books)
        free(total_number_of_books);
    
    for (int i = 0; i < total_number_of_shelves; i++)
        if (*(total_number_of_pages + i))
            free(*(total_number_of_pages + i));
    
    if (total_number_of_pages)
        free(total_number_of_pages);
    
    return 0;
}