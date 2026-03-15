#pragma once

#include "array_of_person.h"


unsigned short age_verification(person* p);
array* where(array* arr, unsigned short (*function)(person*));