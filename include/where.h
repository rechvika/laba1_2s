#pragma once

#include "array_of_person.h"
#include "array_errors.h"


unsigned short age_verification(person* p, array_errors* error);
array* where(array* arr, unsigned short (*function)(person*, array_errors*), array_errors* error);