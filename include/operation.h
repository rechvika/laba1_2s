#pragma once

#include "array_of_person.h"
#include "array_errors.h"


array* map(array* arr, char* (*function)(array*, unsigned int, array_errors*), array_errors* error);
unsigned short age_verification(person* p, array_errors* error);
array* where(array* arr, unsigned short (*function)(person*, array_errors*), array_errors* error);
array* concatenation(array* arr_1, array* arr_2, array_errors* error);

//o файлов не должно быть в репозитоиии gitignor