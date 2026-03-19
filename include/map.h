#pragma once

#include "array_of_person.h"
#include "array_errors.h"


array* map(array* arr, char* (*function)(person*, array_errors*), array_errors* error);