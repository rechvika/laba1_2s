#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_errors.h"
#include "array_of_person.h"
#include "types.h"


typedef struct typeinfo {
    size_t size;
    char* type_name;

    char* (*get_full_name)(struct array* arr, unsigned int index, array_errors* error);
    char* (*get_special_field)(struct array* arr, unsigned int index, array_errors* error);
    void (*print)(struct array* arr, unsigned int index, array_errors* error);
} typeinfo;


char* get_special_field_polymorph(array* arr, unsigned int i, array_errors* error);
void print_person_polymorph(array* arr, unsigned int i, array_errors* error);
typeinfo* create_person_typeinfo();
typeinfo* create_teacher_typeinfo();
typeinfo* create_student_typeinfo();
person* create_person(person_id id, char* first_name, char* middle_name, char* last_name, birth_date birth);
teacher* create_teacher(person_id id, char* first_name, char* middle_name, char* last_name, birth_date birth, char* subject);
student* create_student(person_id id, char* first_name, char* middle_name, char* last_name, birth_date birth, char* direction);
