#ifndef BOOK_NODE_H
#define BOOK_NODE_H
#include "person_name.h"

#define MAX_TITLE_LEN 100

typedef struct _BookNode book_node, *book_node_ptr;
struct _BookNode {
    char title[MAX_TITLE_LEN];
    person_name author_name;
    unsigned number_pages;
    float rating;
    /* ... */
    book_node_ptr next;
};

book_node_ptr new_book(const char *,
                       const char *,
                       const float,
                       const unsigned);

void print_book(book_node_ptr );

void free_book_node(book_node_ptr );

int compare_books_by_fieled(book_node_ptr , book_node_ptr , unsigned );

int compare_books(book_node_ptr , book_node_ptr );

#endif  /* BOOK_NODE_H */