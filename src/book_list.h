#ifndef BOOK_LIST_H
#define BOOK_LIST_H
#include <stdbool.h>
#include "book_node.h"

typedef struct _BookList book_list, *book_list_ptr;

struct _BookList {
    book_node_ptr head;     // Pointer to the first book
    book_node_ptr tail;     // Pointer to the last book
    size_t number_books;    // Number of books in the list
};


book_list_ptr init_book_list(void);
bool is_empty(list_ptr );
size_t get_size_list(list_ptr );

// insert book functions
void insert_book_at_top_list(book_list_ptr , int );
void insert_book_at_end_list(book_list_ptr , int );
void insert_book_at_index_list(book_list_ptr , int , unsigned );

// remove book functions
void remove_book_from_top_list(book_list_ptr );
void remove_book_from_end_list(book_list_ptr );
void remove_book_from_index_list(book_list_ptr , unsigned );

// other functions
int find_index_node(book_list_ptr , int );
bool compare_lists(book_list_ptr , book_list_ptr );
void sort_list(book_list_ptr );
void free_list(book_list_ptr );

// print list
void print_book_list(book_list_ptr );
void print_book_list_reverse(book_list_ptr );

#endif