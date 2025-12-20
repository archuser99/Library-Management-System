#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person_name.h"

//  core functions
person_name_ptr create_person_name(const char *new_first_name, const char *new_sec_name, const char *new_last_name){
    if( new_first_name == NULL || new_last_name == NULL){
        fprintf(stderr, "Invalid first and last name");
        return NULL;
    }
    person_name_ptr new_person_name = malloc(sizeof(person_name));

    strncpy(new_person_name->first_name, new_first_name, MAX_FIRST_NAME_LEN);
    new_person_name->first_name[MAX_FIRST_NAME_LEN - 1] = '\0';
    
    strncpy(new_person_name->sec_name, new_sec_name, MAX_SEC_NAME_LEN);
    new_person_name->first_name[MAX_SEC_NAME_LEN - 1] = '\0';
    
    strncpy(new_person_name->last_name, new_last_name, MAX_LAST_NAME_LEN);
    new_person_name->first_name[MAX_LAST_NAME_LEN - 1] = '\0';
    
    return new_person_name;
}
void free_person_name(person_name_ptr person_name_to_free){
    if(person_name_to_free == NULL)
        return;
    free(person_name_to_free); 
}

//  compare functions
int compare_person_name(person_name_ptr first_person, person_name_ptr sec_person){
    int result = 0;
    result = strcmp(first_person->first_name, sec_person->first_name);
    if( result == 0 )
        result = strcmp(first_person->sec_name, sec_person->sec_name);
    else if ( result == 0 )
        result = strcmp(first_person->last_name, sec_person->last_name);
    return result;
}
int compare_person_name_by_field(person_name_ptr first_person, person_name_ptr sec_person, unsigned field){
    int result = 0;
    if     ( field == 1 ) result = strcmp( first_person->first_name, sec_person->first_name );
    else if( field == 2 ) result = strcmp( first_person->sec_name,   sec_person->sec_name   );
    else if( field == 3 ) result = strcmp( first_person->last_name,  sec_person->last_name  );
    else fprintf(stderr, "Invalid field");
    return result;
}

//  change functions
void edit_person_name(person_name_ptr old_person_name, const char *new_first_name, const char *new_sec_name, const char *new_last_name){
    if(new_first_name){
        strncpy(old_person_name->first_name, new_first_name, MAX_FIRST_NAME_LEN);
        old_person_name->first_name[MAX_FIRST_NAME_LEN - 1] = '\0';
    }
    if(new_sec_name){
        strncpy(old_person_name->sec_name, new_sec_name, MAX_SEC_NAME_LEN);
        old_person_name->sec_name[MAX_SEC_NAME_LEN - 1] = '\0';
    } 
    if(new_last_name){
        strncpy(old_person_name->last_name, new_last_name, MAX_LAST_NAME_LEN);
        old_person_name->last_name[MAX_LAST_NAME_LEN - 1] = '\0';
    }
}
void parse_person_name(person_name_ptr person, const char *full_name){
    if( full_name == NULL ){
        fprintf(stderr, "Invalid full name");
        return;
    }
    char new_first_name[MAX_FIRST_NAME_LEN];
    char new_sec_name[MAX_SEC_NAME_LEN];
    char new_last_name[MAX_LAST_NAME_LEN];
    
    size_t index_string = 0;
    while( full_name[index_string] && index_string < MAX_FIRST_NAME_LEN - 1){
        if ( full_name[index_string] == ' ' ){
            index_string++;
            break;
        }    
        new_first_name[index_string] = full_name[index_string];
        index_string++;
    }
    new_first_name[MAX_FIRST_NAME_LEN - 1] = '\0';

    size_t index_new_string = 0;
    while ( full_name[index_string] && index_new_string < MAX_SEC_NAME_LEN - 1){
        if ( full_name[index_string] == ' ' ){
            index_string++;
            break;
        }    
        new_sec_name[index_string] = full_name[index_string];
        index_new_string++;
        index_string++;
    }
    new_sec_name[MAX_SEC_NAME_LEN - 1] = '\0';
    
    index_new_string = 0;
    while ( full_name[index_string] && index_new_string < MAX_LAST_NAME_LEN - 1){
        if ( full_name[index_string] == ' ' ){
            index_string++;
            break;
        }
        new_last_name[index_string] = full_name[index_string];
        index_new_string++;
        index_string++;
    }
    new_last_name[MAX_LAST_NAME_LEN - 1] = '\0';
    
    edit_person_name(person, new_first_name, new_sec_name, new_last_name);
}

void print_person_name_by_field(person_name_ptr person, unsigned field){
    if(field == 1 || field == 4)
        printf("%s ", person->first_name);
    else if(field == 2 || field == 4)
        printf("%s ", person->sec_name);
    else if(field == 3 || field == 4)
        printf("%s", person->last_name);
    else    fprintf(stderr, "Invalid field");
}
const char *get_name_by_field(const person_name_ptr person, unsigned field){
    if( field == 1 )return person->first_name;
    if( field == 2 )return person->first_name;
    if( field == 3 )return person->first_name;
    else fprintf(stderr, "Invalid field");
}

// bin file 
int save_person_name_to_bin_file(const person_name_ptr p, FILE *f){
    
}
person_name_ptr load_person_name_from_bin_file(FILE *f){
    
}

// csv file
int save_person_name_to_csv_file(const person_name_ptr p, FILE *f){

}
person_name_ptr load_person_name_from_csv_file(FILE *f){

}

// json file
int save_person_name_to_json_file(const person_name_ptr p, FILE *f){

}
person_name_ptr load_person_name_from_json_file(FILE *f){

}
