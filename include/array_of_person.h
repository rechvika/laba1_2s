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
#include "types.h"

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

array* create_array(unsigned int capacity, struct typeinfo* type_info, array_errors* error);
void array_add(array* arr, person* p, array_errors* error);
void free_array(array* arr);

char* get_teacher_subject(array* arr, unsigned int i, array_errors* error);
char* get_student_direction(array* arr, unsigned int i, array_errors* error);



