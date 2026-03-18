#pragma once

#include "array_of_person.h"
#include "typeinfo.h"
#include "where.h"

char* person_map_function(const void* data);
unsigned short person_where_function(const void* data);
void person_print(const void* data);
typeinfo* get_person_typeinfo();