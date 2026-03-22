#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*binary_operator)(const void* arg1, const void* arg2, void* result);
typedef char* (*map_function_by_struct)(const void* data);
typedef unsigned short (*where_function_by_struct)(const void* data);

typedef struct{
    size_t size;
    map_function_by_struct map;
    where_function_by_struct where;
    void (*print)(const void*);
} typeinfo;


//// c
size_t size()