#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_create_array_correct) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(10, info, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr != NULL);
    assert(arr->capacity == 10);
    assert(arr->size == 0);
    assert(arr->element != NULL);
    
    free_array(arr);
    free(info);
}

TEST(test_create_array_zero_capacity) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(0, info, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr != NULL);
    assert(arr->capacity == 0);
    assert(arr->size == 0);
    
    free_array(arr);
    free(info);
}

TEST(test_create_array_null_typeinfo) {
    array_errors error;
    
    array* arr = create_array(10, NULL, &error);
    
    assert(error == OPERATION_NOT_DEFINED);
    assert(arr == NULL);
}

TEST(test_create_array_memory_allocation_failure) {
    assert(1);
}

TEST(test_array_add_one_element) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p;
    p.id.series = 1234;
    p.id.number = 5678;
    
    array_add(arr, &p, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr->size == 1);
    assert(arr->capacity == 2);
    
    person* elements = (person*)arr->element;
    assert(elements[0].id.series == 1234);
    assert(elements[0].id.number == 5678);
    
    free_array(arr);
    free(info);
}

TEST(test_array_add_multiple_elements) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3;
    p1.id.series = 111;
    p2.id.series = 222;
    p3.id.series = 333;
    
    array_add(arr, &p1, &error);
    assert(error == ARRAY_OPERATION_OK);
    array_add(arr, &p2, &error);
    assert(error == ARRAY_OPERATION_OK);
    array_add(arr, &p3, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    assert(arr->size == 3);
    assert(arr->capacity == 4);
    
    person* elements = (person*)arr->element;
    assert(elements[0].id.series == 111);
    assert(elements[1].id.series == 222);
    assert(elements[2].id.series == 333);
    
    free_array(arr);
    free(info);
}

TEST(test_array_add_null_array) {
    person p;
    array_errors error;
    
    array_add(NULL, &p, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
}

TEST(test_array_add_null_person) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    array_add(arr, NULL, &error);
    
    assert(error == PERSON_NOT_DEFINED);
    
    free_array(arr);
    free(info);
}

TEST(test_array_add_with_reallocation) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(1, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2;
    p1.id.series = 111;
    p2.id.series = 222;
    
    array_add(arr, &p1, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(arr->size == 1);
    assert(arr->capacity == 1);
    
    array_add(arr, &p2, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(arr->size == 2);
    assert(arr->capacity == 2);
    
    person* elements = (person*)arr->element;
    assert(elements[0].id.series == 111);
    assert(elements[1].id.series == 222);
    
    free_array(arr);
    free(info);
}

TEST(test_free_array_null) {
    free_array(NULL);
    assert(1);
}

TEST(test_free_array_normal) {
    typeinfo* info = create_person_typeinfo();
    array* arr = create_array(5, info, NULL);
    
    free_array(arr);
    free(info);
    assert(1);
}


TEST(test_all_get_functions_empty_array) {
    typeinfo* info = create_person_typeinfo();
    array* arr = create_array(5, info, NULL);
    array_errors error;
    
    assert(get_series(arr, 0, &error) == 0);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_number(arr, 0, &error) == 0);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_full_id(arr, 0, &error) == NULL);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_first_name(arr, 0, &error) == NULL);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_middle_name(arr, 0, &error) == NULL);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_last_name(arr, 0, &error) == NULL);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_full_name(arr, 0, &error) == NULL);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_birth_year(arr, 0, &error) == 0);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_birth_month(arr, 0, &error) == NULL);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_birth_date(arr, 0, &error) == 0);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    assert(get_full_birth(arr, 0, &error) == NULL);
    assert(error == INDEX_OUT_OF_BOUNDS);
    
    free_array(arr);
    free(info);
}

TEST(test_all_get_functions_null_array) {
    array_errors error;
    
    assert(get_series(NULL, 0, &error) == 0);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_number(NULL, 0, &error) == 0);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_full_id(NULL, 0, &error) == NULL);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_first_name(NULL, 0, &error) == NULL);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_middle_name(NULL, 0, &error) == NULL);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_last_name(NULL, 0, &error) == NULL);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_full_name(NULL, 0, &error) == NULL);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_birth_year(NULL, 0, &error) == 0);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_birth_month(NULL, 0, &error) == NULL);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_birth_date(NULL, 0, &error) == 0);
    assert(error == ARRAY_NOT_DEFINED);
    
    assert(get_full_birth(NULL, 0, &error) == NULL);
    assert(error == ARRAY_NOT_DEFINED);
}

TEST_ENTRY_POINT