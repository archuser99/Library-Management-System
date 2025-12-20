#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_node.h"

book_node_ptr new_book(const char *new_title, 
                       const char *new_full_name,
                       const float new_rating,
                       const unsigned new_number_pages){
    book_node_ptr new_book = NULL;
    new_book = malloc(sizeof(book_node));
    
    if( !new_title || !new_full_name || new_rating > 5){
        fprintf(stderr, "Error while creating new book");
        return new_book;
    }

    //  Title
    strncpy(new_book->title, new_title, MAX_TITLE_LEN);
    new_book->title[MAX_TITLE_LEN - 1] = '\0';
    
    //  Author name
    person_name_ptr new_author_name = malloc(sizeof(person_name));
    parse_person_name(new_author_name, new_full_name);

    //  Number of pages
    new_book->number_pages = new_number_pages;
    
    //  Rating
    new_book->rating = new_rating;
    
    return new_book; 
}

void print_book(book_node_ptr book){
    if(book == NULL)
        fprintf(stderr, "Error while printing \"book\"");
    printf("Title of the book:\t%s.\n", book->title);    
    print_person_name_by_field( &(book->author_name), 4 );
    printf("\nNumber of pages:\t%d\n", book->number_pages);
    printf("Ratings:\t%f\n", book->rating);
}

void free_book_node(book_node_ptr book){
    if( book == NULL )
        return;
    free_person_name( &(book->author_name));
    free( book );
}

static int cmp_usigned( unsigned num_1, unsigned num_2 ){
    if( num_1 < num_2 ) return -1;
    if( num_1 = num_2 ) return 0;
    if( num_1 > num_2 ) return 1;
}

int compare_book_by_fieled(book_node_ptr book_1, book_node_ptr book_2, unsigned field){
    if( book_1 == NULL || book_2 == NULL  || field < 0 || field > 6){
        fprintf(stderr, "Error while comparing two books by field %d", field);
        return 0;
    }
    if( field == 1 )
        return strncmp( book_1->title, book_2->title, MAX_TITLE_LEN);
    if( field == 2 )
        return compare_person_name_by_field( &(book_1->author_name), &(book_2->author_name), 1 );
    if( field == 3 )
        return compare_person_name_by_field( &(book_1->author_name), &(book_2->author_name), 2 );
    if( field == 4 )
        return compare_person_name_by_field( &(book_1->author_name), &(book_2->author_name), 3 );
    if( field == 5 )
        return cmp_usigned( book_1->number_pages, book_2->number_pages);
    if( field == 6){
        return cmp_usigned( book_1->number_pages, book_2->number_pages);
    }
}
