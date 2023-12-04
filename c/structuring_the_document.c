#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5


struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

void alloc_word(struct sentence* s, char* w) {
    int n_word = s->word_count;

    if (n_word)
        s->data = (struct word*) realloc(s->data, (n_word + 1) * sizeof(struct word));
    else
        s->data = (struct word*) malloc(sizeof(struct word));

    s->data[n_word].data = strdup(w);
    s->word_count++;
}

struct document get_document(char* text) {
    int i, pw;
    char ch;
    char word[MAX_CHARACTERS];
    struct sentence *s;
    struct paragraph *p;
    struct document doc;

    p = (struct paragraph*) malloc(sizeof(struct paragraph));
    doc.data = p;
    doc.paragraph_count = 1;

    s = (struct sentence*) malloc(sizeof(struct sentence));
    p->data = s;
    p->sentence_count = 1;
    s->word_count = 0;

    pw = 0;
    for (i = 0; text[i]; i++) {
        ch = text[i];
        
        if (ch == ' ' || ch == '.') {
            alloc_word(s, word);
            pw = 0;

            if (ch == '.' && text[i + 1] && text[i + 1] != '\n') {
                p->sentence_count++;
                p->data = (struct sentence*) realloc(p->data, p->sentence_count * sizeof(struct sentence));

                s = p->data + (p->sentence_count - 1);
            }
        }
        else if (ch == '\n' && text[i + 1]) {
            doc.paragraph_count++;
            doc.data = (struct paragraph*) realloc(doc.data, doc.paragraph_count * sizeof(struct paragraph));
            p = doc.data + (doc.paragraph_count - 1);
            
            s = (struct sentence*) malloc(sizeof(struct sentence));
            p->data = s;
            p->sentence_count = 1;
            s->word_count = 0;

            pw = 0;
        }
        else {
            word[pw++] = ch;
            word[pw] = '\0';
        }
    }

    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);

        if (i != sen.word_count - 1)
            printf(" ");
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++) {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);

        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*) malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}


int main () {
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else {
            int k;
            scanf("%d", &k);

            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }

        printf("\n");
    }     
}