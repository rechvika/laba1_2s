#pragma once 
#include <stdio.h>

void int_success();
void int_fail();
int pop_fail();
int pop_success();

int assert_success(const char *expr, const char *file, size_t lineno);
int assert_fail(const char *expr, const char *file, size_t lineno);
int print_stats();

#define assert(expr) \
    ((!!(expr)) \
        ? assert_success(#expr, __FILE__, __LINE__) \
        : assert_fail(#expr, __FILE__, __LINE__))


