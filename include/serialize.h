#pragma once

#include "array_of_person.h"
#include "array_errors.h"
#include "operation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

char* serialize_series(array* arr, unsigned int i, array_errors* error);
char* serialize_number(array* arr, unsigned int i, array_errors* error);
char* serialize_full_id(array* arr, unsigned int i, array_errors* error);
char* serialize_first_name(array* arr, unsigned int i, array_errors* error);
char* serialize_middle_name(array* arr, unsigned int i, array_errors* error);
char* serialize_last_name(array* arr, unsigned int i, array_errors* error);
char* serialize_full_name(array* arr, unsigned int i, array_errors* error);
char* serialize_birth_year(array* arr, unsigned int i, array_errors* error);
char* serialize_birth_month(array* arr, unsigned int i, array_errors* error);
char* serialize_birth_date(array* arr, unsigned int i, array_errors* error);
char* serialize_full_birth(array* arr, unsigned int i, array_errors* error);
char* serialize_where_list(array* arr, array_errors* error);
char* serialize_map_list(array* arr, array_errors* error);
char* serialize_person(array* arr, unsigned int i, array_errors* error);