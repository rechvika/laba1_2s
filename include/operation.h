#pragma once

#include "array_of_person.h"
#include "array_errors.h"
#include "types.h"


array* map(array* arr, char* (*function)(array*, unsigned int, array_errors*), array_errors* error);
unsigned short age_verification(array* arr, unsigned int i, array_errors* error);
array* where(array* arr, unsigned short (*function)(array*, unsigned int, array_errors*), array_errors* error);
array* concatenation(array* arr_1, array* arr_2, array_errors* error);
