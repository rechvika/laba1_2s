#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_array_resize_performance) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    
    for(int i = 0; i < 100; i++) {
        person p;
        p.id.series = i;
        array_add(arr, &p, &error);
        assert(error == ARRAY_OPERATION_OK);
    }
    
    assert(arr->size == 100);
    assert(arr->capacity >= 100);
    
    person* elements = (person*)arr->element;
    for(int i = 0; i < 100; i++) {
        assert(elements[i].id.series == i);
    }
    
    free_array(arr);
    free(info);
}

TEST(test_error_recovery) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    assert(error == ARRAY_OPERATION_OK);

    array* filtered = where(arr, NULL, &error);
    assert(error == OPERATION_NOT_DEFINED);
    assert(filtered == NULL);

    assert(arr->size == 0);
    assert(arr->capacity == 2);
    
    person p;
    p.id.series = 123;
    array_add(arr, &p, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(arr->size == 1);
    
    free_array(arr);
    free(info);
}

TEST(test_multiple_operations_chain) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    
    array* arr = create_array(2, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3;
    p1.birth.year = 2000;
    p2.birth.year = 2015;
    p3.birth.year = 1995;
    strcpy(p1.first_name, "Иван");
    strcpy(p2.first_name, "Петр");
    strcpy(p3.first_name, "Сидор");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    array* adults = where(arr, age_verification, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(adults->size == 2);
    
    array* mapped_names = map(adults, map_function, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(mapped_names->size == 2);
    
    char** names = (char**)mapped_names->element;
    assert(strcmp(names[0], "mapped_Иван") == 0);
    assert(strcmp(names[1], "mapped_Сидор") == 0);
    
    for(unsigned int i = 0; i < mapped_names->size; i++) {
        free(names[i]);
    }
    
    free_array(arr);
    free_array(adults);
    free_array(mapped_names);
    free(info);
}


TEST(test_array_add_very_many_elements) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(10, info, &error);
    
    unsigned int test_size = 1000;
    for(int i = 0; i < test_size; i++) {
        person p;
        p.id.series = i;
        array_add(arr, &p, &error);
        assert(error == ARRAY_OPERATION_OK);
    }
    
    assert(arr->size == test_size);
    assert(arr->capacity >= test_size);
    
    person* elements = (person*)arr->element;
    for(int i = 0; i < test_size; i++) {
        assert(elements[i].id.series == i);
    }
    
    free_array(arr);
    free(info);
}

TEST(test_array_add_zero_capacity) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(0, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    assert(arr->capacity == 0);
    
    person p;
    p.id.series = 123;
    array_add(arr, &p, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(arr->size == 1);
    assert(arr->capacity == 1);
    
    person* elements = (person*)arr->element;
    assert(elements[0].id.series == 123);
    
    free_array(arr);
    free(info);
}

TEST(test_where_empty_array) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered != NULL);
    assert(filtered->size == 0);
    
    free_array(arr);
    free_array(filtered);
    free(info);
}

TEST(test_map_empty_array) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    
    array* mapped = map(arr, map_function, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(mapped != NULL);
    assert(mapped->size == 0);
    
    free_array(arr);
    free_array(mapped);
    free(info);
}

TEST(test_serialize_where_list_empty_array) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    
    char* result = serialize_where_list(arr, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "Совершеннолетние:\n") == 0);
    
    free(result);
    free_array(arr);
    free(info);
}

TEST(test_serialize_map_list_empty_array) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    
    char* result = serialize_map_list(arr, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "Имена в массиве:\n") == 0);
    
    free(result);
    free_array(arr);
    free(info);
}

TEST(test_multiple_errors_chain) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    
    array* result1 = where(arr, NULL, &error);
    assert(error == OPERATION_NOT_DEFINED);
    assert(result1 == NULL);
    
    array* result2 = concatenation(arr, NULL, &error);
    assert(error == ARRAY_NOT_DEFINED);
    assert(result2 == NULL);
    
    char* result3 = serialize_series(arr, 5, &error);
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result3 == NULL);

    assert(arr->size == 0);
    assert(arr->capacity == 2);
    
    free_array(arr);
    free(info);
}

TEST(test_error_after_successful_operation) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    
    person p;
    p.id.series = 123;
    array_add(arr, &p, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    char* result = serialize_series(arr, 5, &error);
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    assert(arr->size == 1);
    person* elements = (person*)arr->element;
    assert(elements[0].id.series == 123);
    
    free_array(arr);
    free(info);
}

TEST_ENTRY_POINT