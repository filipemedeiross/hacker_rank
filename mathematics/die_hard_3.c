#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YES "YES"
#define NO "NO"


// Definition of data structures
typedef struct Node {
    int a;
    int b;
    int max_a;
    int max_b;
} Node;

typedef struct ListNode {
    Node* node;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* front;
} List;

typedef struct QueueNode {
    Node* node;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;


// Prototype of the functions
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

Node* new_node(int, int);
Node* create_node(int, int, int, int);

Queue* create_queue(Node*);
void push_queue(Queue*, Node*);
Node* dequeue(Queue*);

List* create_list(Node*);
void push_list(List*, Node*);
int find_node(List*, int, int);

int expand_node(int, int, int, int, int, Queue*, List*);


// BFS - Breadth-First Search
char* solve(int a, int b, int c) {
    int curr_a;
    int curr_b;
    int capacity;
    int find_item;
    Node* root;
    Node* curr;
    List* discovered;
    Queue* queue;

    root = new_node(a, b);
    queue = create_queue(root);
    discovered = create_list(root);

    find_item = 0;
    while (queue->front) {
        curr = dequeue(queue);

        if (!find_item && curr->max_a - curr->a) {
            curr_a = a;
            curr_b = curr->b;

            if (!find_node(discovered, curr_a, curr_b))
                find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
        }
        if (!find_item && curr->max_b - curr->b) {
            curr_a = curr->a;
            curr_b = b;

            if (!find_node(discovered, curr_a, curr_b))
                find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
        }
        if (!find_item && curr->a) {
            curr_a = 0;
            curr_b = curr->b;

            if (!find_node(discovered, curr_a, curr_b))
                find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
        }
        if (!find_item && curr->b) {
            curr_a = curr->a;
            curr_b = 0;

            if (!find_node(discovered, curr_a, curr_b))
                find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
        }
        if (curr->a && curr->max_b - curr->b) {
            capacity = curr->max_b - curr->b;

            if (!find_item && curr->a > capacity) {
                curr_a = curr->a - capacity;
                curr_b = curr->b + capacity;

                if (!find_node(discovered, curr_a, curr_b))
                    find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
            }
            else if (!find_item) {
                curr_a = 0;
                curr_b = curr->a + curr->b;

                if (!find_node(discovered, curr_a, curr_b))
                    find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
            }
        }
        if (curr->b && curr->max_a - curr->a) {
            capacity = curr->max_a - curr->a;

            if (!find_item && curr->b > capacity) {
                curr_a = curr->a + capacity;
                curr_b = curr->b - capacity;

                if (!find_node(discovered, curr_a, curr_b))
                    find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
            }
            else if (!find_item) {
                curr_a = curr->a + curr->b;
                curr_b = 0;

                if (!find_node(discovered, curr_a, curr_b))
                    find_item = expand_node(curr_a, curr_b, a, b, c, queue, discovered);
            }
        }

        if (find_item)
            return YES;
    }

    free(queue);

    return NO;
}


int main () {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        int a = parse_int(*(first_multiple_input + 0));

        int b = parse_int(*(first_multiple_input + 1));

        int c = parse_int(*(first_multiple_input + 2));

        char* result = solve(a, b, c);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}


// Definition of functions
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

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

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
 
Node* new_node(int max_a, int max_b) {
    return create_node(0, 0, max_a, max_b);
}

Node* create_node(int a, int b, int max_a, int max_b) {
    Node* node;
    
    node = (Node*) malloc(sizeof(Node));
    node->a = a;
    node->b = b;
    node->max_a = max_a;
    node->max_b = max_b;

    return node;
}

Queue* create_queue(Node* root) {
    Queue* queue;
    
    queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    push_queue(queue, root);

    return queue;
}

void push_queue(Queue* queue, Node* node) {
    QueueNode* queue_node;
    
    queue_node = (QueueNode*) malloc(sizeof(QueueNode));
    queue_node->node = node;
    queue_node->next = NULL;

    if (queue->rear) {
        queue->rear->next = queue_node;
        queue->rear = queue_node;
    } else {
        queue->front = queue->rear = queue_node;
    }
}

Node* dequeue(Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    QueueNode* temp = queue->front;
    Node* node = temp->node;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return node;
}

List* create_list(Node* root) {
    List* list;
    
    list= (List*) malloc(sizeof(List));
    list->front = NULL;
    push_list(list, root);

    return list;
}

void push_list(List* list, Node* node) {
    ListNode* list_node;
    
    list_node = (ListNode*) malloc(sizeof(ListNode));
    list_node->node = node;
    list_node->next = NULL;

    if (list->front)
        list_node->next = list->front;

    list->front = list_node;
}

int find_node(List* list, int a, int b) {
    Node* node;
    ListNode* current;

    current = list->front;
    while (current) {
        node = current->node;

        if (node->a == a && node->b == b)
            return 1;

        current = current->next;
    }

    return 0;
}

int expand_node(int a, int b, int max_a, int max_b, int c, Queue* queue, List* discovered) {
    Node* child;
    
    child = create_node(a, b, max_a, max_b);
    push_queue(queue, child);
    push_list(discovered, child);
    
    return a == c || b == c;
}