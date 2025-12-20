#ifndef PERSON_NAME_H
#define PERSON_NAME_H

#define MAX_FIRST_NAME_LEN 50
#define MAX_SEC_NAME_LEN 50
#define MAX_LAST_NAME_LEN 100

typedef struct _PersonName person_name, *person_name_ptr;

struct _PersonName {
    char first_name[MAX_FIRST_NAME_LEN];
    char sec_name[MAX_SEC_NAME_LEN];
    char last_name[MAX_LAST_NAME_LEN];
};

// core
person_name_ptr create_person_name(const char *, const char *, const char *);
void free_person_name(person_name_ptr );

// compare functions
int compare_person_name(person_name_ptr , person_name_ptr );
int compare_person_name_by_field(person_name_ptr , person_name_ptr , unsigned );

// edit functions
void edit_person_name(person_name_ptr , const char *, const char *, const char *);
void parse_person_name(person_name_ptr , const char *);

void print_person_name_by_field(person_name_ptr , unsigned);
const char *get_name_by_field(const person_name_ptr , unsigned );

// bin file 
int save_person_name_to_bin_file(const person_name_ptr p, FILE *f);
person_name_ptr load_person_name_from_bin_file(FILE *f);

// csv file
int save_person_name_to_csv_file(const person_name_ptr p, FILE *f);
person_name_ptr load_person_name_from_csv_file(FILE *f);

// json file
int save_person_name_to_json_file(const person_name_ptr p, FILE *f);
person_name_ptr load_person_name_from_json_file(FILE *f);

#endif /* PERSON_NAME_H */