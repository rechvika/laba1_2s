#pragma once

#include "array_of_person.h"


unsigned short age_verification(person* person);
array* where(array* array, unsigned short (*function)(person*));