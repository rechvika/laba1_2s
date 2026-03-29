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
#define MAX_LINE_SUBJECT 50
#define MAX_LINE_DIRECTION 50 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeinfo.h"
#include "array_errors.h"

typedef struct person_id{
    unsigned short series;
    unsigned short number;
} person_id;

typedef struct birth_date{
    unsigned short year;
    char month[MAX_LINE_MONTH];
    unsigned short date;
} birth_date;

typedef struct record_teacher{
    char subject[MAX_LINE_SUBJECT];
} record_teacher;

typedef struct record_student{
    char direction[MAX_LINE_DIRECTION];
} record_student;

typedef struct person{
    struct typeinfo* vtable;
    person_id id;
    char first_name[MAX_LINE_NAME];
    char middle_name[MAX_LINE_NAME];
    char last_name[MAX_LINE_NAME];
    birth_date birth;
} person;

typedef struct teacher{
    person base;
    record_teacher data;
} teacher;

typedef struct student{
    person base;
    record_student data;
} student;

typedef struct array { 
    struct person* element;
    unsigned int size;
    unsigned int capacity;
    struct typeinfo* typeinfo;
} array;