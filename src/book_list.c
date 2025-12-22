#include <stdio.h>
#include <stdlib.h>
#include "book_list.h"

void init_book_list(book_list_ptr new_book_list){
    new_book_list = malloc(sizeof(book_list));
    new_book_list->head = NULL;
    new_book_list->tail = NULL;
    new_book_list->number_books = 0;
}

bool book_list_empty(book_list_ptr my_book_list){
    if(my_book_list->head == NULL)
        return true;
    return false;
}

size_t get_size_list(book_list_ptr my_book_list){
    if( my_book_list == NULL ) return 0;
    return my_book_list->number_books;
}

// insert book functions
void insert_book_at_top_list(book_list_ptr my_book_list, book_node_ptr new_book ){
    if( my_book_list == NULL){
        fprintf(stderr, "Error, the book list you provided is not valid");
        return;
    }
    if( book_list_empty( my_book_list ) ){
        my_book_list->head = new_book;
        my_book_list->tail = new_book;
        new_book->next = NULL;
    } else {
        new_book->next = my_book_list->head;
        my_book_list->head = new_book;
    }
    my_book_list->number_books++;
}
void insert_book_at_end_list(book_list_ptr my_book_list, book_node_ptr new_book ){
    if( my_book_list == NULL){
        fprintf(stderr, "Error, the book list you provided is not valid");
        return;
    }
    if( book_list_empty( my_book_list ) ){
        insert_book_at_top_list(my_book_list, new_book);
    } else {
        new_book->next = NULL;
        my_book_list->tail->next = new_book;
        my_book_list->tail = new_book;
    }
    my_book_list->number_books++;

}
void insert_book_at_index_list(book_list_ptr my_book_list, book_node_ptr new_book, unsigned index){
    if( my_book_list == NULL || index > my_book_list->number_books ){
        fprintf(stderr, "Error, while inserting book at index %d", index);
        return;
    }
    if( book_list_empty( my_book_list ) )
        insert_book_at_top_list( my_book_list, new_book );
    else if( index == 0 )
        insert_book_at_top_list( my_book_list, new_book );
    else if( index == my_book_list->number_books )
        insert_book_at_end_list( my_book_list, new_book );
    else{
        book_node_ptr tmp = my_book_list->head;
        for (size_t tmp_index = 0; tmp_index < index - 1; tmp_index++)
            tmp = tmp->next;
        new_book->next = tmp->next;
        tmp = new_book;
    }
    my_book_list->number_books++;
}

// remove book functions
void remove_book_from_top_list(book_list_ptr my_book_list){
    if( my_book_list == NULL || book_list_empty( my_book_list ) ){
        fprintf(stderr, "Error while removing book node");
        return;
    }
    if( my_book_list->number_books == 1){
        book_node_ptr tmp = my_book_list->head;
        free_book_node( tmp );
        my_book_list->tail = NULL;
    } else {
        book_node_ptr tmp = my_book_list->head;
        my_book_list->head = tmp->next;
        free_book_node( tmp );
    }
    my_book_list->number_books--;

}
void remove_book_from_end_list(book_list_ptr my_book_list){
    if( my_book_list == NULL || book_list_empty( my_book_list ) ){
        fprintf(stderr, "Error while removing book node");
        return;
    }
    if( my_book_list->number_books == 1)
        remove_book_from_top_list( my_book_list );
    else{
        book_node_ptr tmp = my_book_list->head;
        while( tmp->next != NULL && tmp->next->next != NULL )
            tmp = tmp->next;
        free_book_node( tmp->next );
        my_book_list->tail = tmp;
        tmp->next = NULL;
    }
    my_book_list->number_books--;
    
}
void remove_book_from_index_list(book_list_ptr my_book_list, unsigned index){
    if( my_book_list == NULL || book_list_empty( my_book_list ) ){
        fprintf(stderr, "Error while removing book node");
        return;
    }
    if( my_book_list->number_books == 1)
        remove_book_from_top_list( my_book_list );
    else if( index == my_book_list->number_books -1 )
        remove_book_from_end_list( my_book_list );
    else {
        // to be continued;
    }
    my_book_list->number_books--;
}

// other functions
book_node_ptr get_book_by_index(book_list_ptr my_book_list, unsigned index){
    if( my_book_list == NULL || index > my_book_list->number_books - 1 ){
        fprintf(stderr, "Error, while inserting book at index %d", index);
        return NULL;
    }
    book_node_ptr tmp = my_book_list->head;
    for (size_t tmp_index = 0; tmp_index < index - 1; tmp_index++)
        tmp = tmp->next;
    return tmp;
}
bool compare_lists(book_list_ptr my_book_list_1, book_list_ptr my_book_list_2){
    if( my_book_list_1 == NULL || my_book_list_2 == NULL ){
        fprintf(stderr, "Error, invalid book list");
        return false;
    } 
    book_node_ptr tmp_1 = my_book_list_1->head;
    book_node_ptr tmp_2 = my_book_list_2->head;
    while( compare_books( tmp_1, tmp_2 ) >= 0 ){
        tmp_1 = tmp_1->next;
        tmp_2 = tmp_2->next;
    }
    return( tmp_1 == NULL && tmp_2 == NULL );
}
void sort_list(book_list_ptr );
void free_list(book_list_ptr my_book_list){
    if( my_book_list == NULL ) return;
    if( book_list_empty( my_book_list ) )
        free( my_book_list );
    else{
        book_node_ptr tmp_book = my_book_list->head;
        while( tmp_book ){
            book_node_ptr current = tmp_book;
            tmp_book = tmp_book->next;
            free_book_node( current );
        }
        
    }
}

// print list
void print_book_list(book_list_ptr my_book_list){
    if( my_book_list == NULL)
        return;
    book_node_ptr tmp = my_book_list->head;
    while( tmp != NULL ){
        print_book( tmp );
        tmp = tmp->next;
    }
}
void print_book_list_reverse(book_list_ptr my_book_list){
    if( my_book_list == NULL ) return;
    my_book_list->head = my_book_list->head->next;
    print_book_list_reverse( my_book_list );
    print_book( my_book_list->head );
}
