#pragma once

#include <locale.h>
#include "array_of_person.h"
#include "concatenation.h"
#include "map.h"
#include "where.h"
#include "test_person.h"
#include "person_typeinfo.h"
#include "array_errors.h"
#include "types.h"

int conclusion();
void show_buttons(void);
void print_serialized(char* str, array_errors error);