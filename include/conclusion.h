#pragma once

#include <locale.h>
#include "array_errors.h"
#include "conclusion.h"
#include "serialize.h"
#include "array_of_person.h"
#include "operation.h"
#include "test_person.h"
#include "typeinfo.h"
#include "types.h"

int conclusion();
void show_buttons(void);
void print_serialized(char* str, array_errors error);