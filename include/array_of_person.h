#pragma once

#define MAX_LINE_NAME 100
#define LINE_SERIES_AND_YEAR 10
#define LINE_NUMBER 10
#define MAX_LINE_MONTH 15
#define MAX_LINE_DATE 5
#define FULL_ID 15
#define FULL_NAME 300
#define FULL_BIRTH 20
#define MAP_CONST 120

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeinfo.h"
#include "array_errors.h"


//////
// record
struct person_record {
    // unsigned short id;
    unsigned short age;
    char name[MAX_LINE_NAME];
};

struct person_detailed_record {
    unsigned short age;
    char name[MAX_LINE_NAME];
    char lastname[MAX_LINE_NAME];
    char secondname[MAX_LINE_NAME];
};

typedef struct Person
{
    typeinfo* vtable;
    unsigned short id;
} Person;

typedef struct PersonD
{
    Person base;
    struct person_record data;
} PersonD;

typedef struct PersonDt
{
    Person base;
    struct person_detailed_record data;
} PersonDt;


Person* create_person_dt() {
    PersonDt* p = malloc(sizeof(PersonDt));
    p->base.vtable = &... 
}

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

typedef struct person{
    
} person;

typedef struct array { 
    person* element;
    unsigned int size;
    unsigned int capacity;
    typeinfo* typeinfo;
} array;

unsigned short get_series(array* arr, unsigned int i, array_errors* error);
unsigned short get_number(array* arr, unsigned int i, array_errors* error);
char* get_full_id (array* arr, unsigned int i, array_errors* error);
char* get_first_name(array* arr, unsigned int i, array_errors* error);
char* get_middle_name(array* arr, unsigned int i, array_errors* error);
char* get_last_name(array* arr, unsigned int i, array_errors* error);
char* get_full_name (array* arr, unsigned int i, array_errors* error);
unsigned short get_birth_year(array* arr, unsigned int i, array_errors* error);
char* get_birth_month(array* arr, unsigned int i, array_errors* error);
unsigned short get_birth_date(array* arr, unsigned int i, array_errors* error);
char* get_full_birth (array* arr, unsigned int i, array_errors* error);
char* map_function(array* arr, unsigned int i, array_errors* error);

