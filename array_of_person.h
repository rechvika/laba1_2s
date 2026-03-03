#pragma once

#define MAX_LINE_NAME 100
#define LINE_SERIES_AND_YEAR 4
#define LINE_NUMBER 6
#define MAX_LINE_MONTH 9
#define MAX_LINE_DATE 2
#define FULL_ID 10
#define FULL_NAME 300
#define FULL_BIRTH 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct person_id{
    unsigned short series[LINE_SERIES_AND_YEAR];
    unsigned short number[LINE_NUMBER];
} person_id;

typedef struct birth_date{
    unsigned short year[LINE_SERIES_AND_YEAR];
    char month[MAX_LINE_MONTH];
    unsigned short date[MAX_LINE_DATE];
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



unsigned short get_series(person* person);
unsigned short get_number(person* person);
char* get_full_id (person* person);
char* get_first_name(person* person);
char* get_middle_name(person* person);
char* get_last_name(person* person);
char* get_full_name (person* person);
unsigned short get_birth_year(person* person);
char* get_birth_month(person* person);
unsigned short get_birth_date(person* person);
char* get_full_birth (person* person);
array* create_array();
void array_add(array* array, person* person);
