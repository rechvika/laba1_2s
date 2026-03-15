#pragma once

#define MAX_LINE_NAME 100
#define LINE_SERIES_AND_YEAR 4
#define LINE_NUMBER 6
#define MAX_LINE_MONTH 9
#define MAX_LINE_DATE 2
#define FULL_ID 10
#define FULL_NAME 300
#define FULL_BIRTH 15
#define MAP_CONST 120

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person_id{
    unsigned short series;
    unsigned short number;
} person_id;

typedef struct birth_date{
    unsigned short year;
    char month[MAX_LINE_MONTH];
    unsigned short date;
} birth_date;

typedef struct person{
    person_id id;
    char first_name[MAX_LINE_NAME];
    char middle_name[MAX_LINE_NAME];
    char last_name[MAX_LINE_NAME];
    birth_date birth;
} person;

typedef struct array {
    person** element;
    unsigned int size;
    unsigned int capacity;
} array;

unsigned short get_series(person* p);
unsigned short get_number(person* p);
char* get_full_id (person* p);
char* get_first_name(person* p);
char* get_middle_name(person* p);
char* get_last_name(person* p);
char* get_full_name (person* p);
unsigned short get_birth_year(person* p);
char* get_birth_month(person* p);
unsigned short get_birth_date(person* p);
char* get_full_birth (person* p);
array* create_array(unsigned int capacity);
void array_add(array* arr, person* p);
void free_array(array* arr);
int is_array_empty(array* arr);
char* map_function(person* p)