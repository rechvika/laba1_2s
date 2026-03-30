#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_age_verification_adult_18) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 2008; 
    array_add(arr, &p, NULL);
    
    unsigned short result = age_verification(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
    
    free_array(arr);
}

TEST(test_age_verification_adult_30) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 1996;
    array_add(arr, &p, NULL);
    
    unsigned short result = age_verification(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 1);
    
    free_array(arr);
}

TEST(test_age_verification_child_17) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 2009;
    array_add(arr, &p, NULL);
    
    unsigned short result = age_verification(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 0);
    
    free_array(arr);
}

TEST(test_age_verification_child_5) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 2021;
    array_add(arr, &p, NULL);
    
    unsigned short result = age_verification(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result == 0);
    
    free_array(arr);
}

TEST(test_age_verification_null_array) {
    array_errors error;
    
    unsigned short result = age_verification(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == 0);
}

TEST(test_age_verification_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    unsigned short result = age_verification(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == 0);
    
    free_array(arr);
}

TEST(test_where_filter_adults) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2, p3, p4;
    p1.birth.year = 2000; // взрослый
    p2.birth.year = 2015; // ребенок
    p3.birth.year = 1995; // взрослый
    p4.birth.year = 2020; // ребенок
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    array_add(arr, &p4, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered != NULL);
    assert(filtered->size == 2);
    
    person* elements = (person*)filtered->element;
    assert(elements[0].birth.year == 2000);
    assert(elements[1].birth.year == 1995);
    
    free_array(arr);
    free_array(filtered);
    free(info);
}

TEST(test_where_empty_result) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2;
    p1.birth.year = 2015;
    p2.birth.year = 2020;
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered != NULL);
    assert(filtered->size == 0);
    
    free_array(arr);
    free_array(filtered);
    free(info);
}

TEST(test_where_all_elements) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    person p1, p2;
    p1.birth.year = 1990;
    p2.birth.year = 2000;
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    
    array* filtered = where(arr, age_verification, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered->size == 2);
    
    free_array(arr);
    free_array(filtered);
    free(info);
}

TEST(test_where_null_array) {
    array_errors error;
    
    array* filtered = where(NULL, age_verification, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(filtered == NULL);
}

TEST(test_where_null_function) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    assert(error == ARRAY_OPERATION_OK);
    
    array* filtered = where(arr, NULL, &error);
    
    assert(error == OPERATION_NOT_DEFINED);
    assert(filtered == NULL);
    
    free_array(arr);
    free(info);
}

TEST(test_concatenation_two_arrays) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, info, &error);
    array* arr2 = create_array(2, info, &error);
    
    person p1, p2, p3, p4;
    p1.id.series = 1;
    p2.id.series = 2;
    p3.id.series = 3;
    p4.id.series = 4;
    
    array_add(arr1, &p1, &error);
    array_add(arr1, &p2, &error);
    array_add(arr2, &p3, &error);
    array_add(arr2, &p4, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(result->size == 4);
    assert(result->capacity >= 4);
    
    person* elements = (person*)result->element;
    assert(elements[0].id.series == 1);
    assert(elements[1].id.series == 2);
    assert(elements[2].id.series == 3);
    assert(elements[3].id.series == 4);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
    free(info);
}

TEST(test_concatenation_empty_and_nonempty) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, info, &error);
    array* arr2 = create_array(2, info, &error);
    
    person p1, p2;
    p1.id.series = 1;
    p2.id.series = 2;
    
    array_add(arr2, &p1, &error);
    array_add(arr2, &p2, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result->size == 2);
    
    person* elements = (person*)result->element;
    assert(elements[0].id.series == 1);
    assert(elements[1].id.series == 2);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
    free(info);
}

TEST(test_concatenation_both_empty) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, info, &error);
    array* arr2 = create_array(2, info, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result->size == 0);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
    free(info);
}

TEST(test_concatenation_null_first_array) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr2 = create_array(2, info, &error);
    
    array* result = concatenation(NULL, arr2, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
    
    free_array(arr2);
    free(info);
}

TEST(test_concatenation_null_second_array) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, info, &error);
    
    array* result = concatenation(arr1, NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
    
    free_array(arr1);
    free(info);
}

TEST(test_concatenation_incompatible_types) {
    typeinfo* info1 = create_person_typeinfo();
    typeinfo* info2 = create_teacher_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, info1, &error);
    array* arr2 = create_array(2, info2, &error);
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == INCOMPATIBLE_TYPES);
    assert(result == NULL);
    
    free_array(arr1);
    free_array(arr2);
    free(info1);
    free(info2);
}

TEST(test_map_with_map_function) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(3, info, &error);
    
    person p1, p2, p3;
    strcpy(p1.first_name, "Иван");
    strcpy(p2.first_name, "Петр");
    strcpy(p3.first_name, "Сидор");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    array* mapped = map(arr, map_function, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(mapped != NULL);
    assert(mapped->size == 3);
    
    char** strings = (char**)mapped->element;
    assert(strcmp(strings[0], "mapped_Иван") == 0);
    assert(strcmp(strings[1], "mapped_Петр") == 0);
    assert(strcmp(strings[2], "mapped_Сидор") == 0);
    
    for(unsigned int i = 0; i < mapped->size; i++) {
        free(strings[i]);
    }
    
    free_array(arr);
    free_array(mapped);
    free(info);
}

TEST(test_map_null_array) {
    array_errors error;
    
    array* result = map(NULL, map_function, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_map_null_function) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    
    array* result = map(arr, NULL, &error);
    
    assert(error == OPERATION_NOT_DEFINED);
    assert(result == NULL);
    
    free_array(arr);
    free(info);
}

TEST(test_map_empty_array) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    
    array* result = map(arr, map_function, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(result->size == 0);
    
    free_array(arr);
    free_array(result);
    free(info);
}

TEST(test_map_function_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.first_name, "Тест");
    array_add(arr, &p, NULL);
    
    char* result = map_function(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "mapped_Тест") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_map_function_null_array) {
    array_errors error;
    
    char* result = map_function(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_map_function_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = map_function(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_map_function_memory_allocation_failure) {
    assert(1);
}


TEST(test_map_with_custom_function) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    
    person p1, p2;
    strcpy(p1.first_name, "Алексей");
    strcpy(p2.first_name, "Дмитрий");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    
    array* mapped = map(arr, map_function, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(mapped->size == 2);
    
    char** strings = (char**)mapped->element;
    assert(strcmp(strings[0], "mapped_Алексей") == 0);
    assert(strcmp(strings[1], "mapped_Дмитрий") == 0);
    
    for(unsigned int i = 0; i < mapped->size; i++) {
        free(strings[i]);
    }
    
    free_array(arr);
    free_array(mapped);
    free(info);
}

TEST(test_map_function_returns_null) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(1, info, &error);
    
    person p;
    strcpy(p.first_name, "Тест");
    array_add(arr, &p, &error);
    
    array_errors temp_error;
    char* result = map_function(arr, 0, &temp_error);
    assert(result != NULL);
    free(result);
    
    free_array(arr);
    free(info);
}



TEST(test_concatenation_first_larger) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(5, info, &error);
    array* arr2 = create_array(2, info, &error);
    
    for(int i = 0; i < 5; i++) {
        person p;
        p.id.series = i;
        array_add(arr1, &p, &error);
    }
    
    for(int i = 0; i < 2; i++) {
        person p;
        p.id.series = i + 100;
        array_add(arr2, &p, &error);
    }
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result->size == 7);
    
    person* elements = (person*)result->element;
    for(int i = 0; i < 5; i++) {
        assert(elements[i].id.series == i);
    }
    for(int i = 0; i < 2; i++) {
        assert(elements[5 + i].id.series == i + 100);
    }
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
    free(info);
}

TEST(test_concatenation_second_larger) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr1 = create_array(2, info, &error);
    array* arr2 = create_array(5, info, &error);
    
    for(int i = 0; i < 2; i++) {
        person p;
        p.id.series = i;
        array_add(arr1, &p, &error);
    }
    
    for(int i = 0; i < 5; i++) {
        person p;
        p.id.series = i + 100;
        array_add(arr2, &p, &error);
    }
    
    array* result = concatenation(arr1, arr2, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result->size == 7);
    
    free_array(arr1);
    free_array(arr2);
    free_array(result);
    free(info);
}

unsigned short custom_condition_year_2000(array* arr, unsigned int i, array_errors* error) {
    if (arr == NULL || i >= arr->size) {
        *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].birth.year == 2000;
}

unsigned short custom_condition_name_starts_with_I(array* arr, unsigned int i, array_errors* error) {
    if (arr == NULL || i >= arr->size) {
        *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].first_name[0] == 'I';
}

TEST(test_where_with_custom_condition_year) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    
    person p1, p2, p3;
    p1.birth.year = 2000;
    p2.birth.year = 2001;
    p3.birth.year = 2000;
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    array* filtered = where(arr, custom_condition_year_2000, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered->size == 2);
    
    free_array(arr);
    free_array(filtered);
    free(info);
}

TEST(test_where_with_custom_condition_name) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(5, info, &error);
    
    person p1, p2, p3;
    strcpy(p1.first_name, "Иван");
    strcpy(p2.first_name, "Петр");
    strcpy(p3.first_name, "Игорь");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    array* filtered = where(arr, custom_condition_name_starts_with_I, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(filtered->size == 2);
    
    free_array(arr);
    free_array(filtered);
    free(info);
}

TEST_ENTRY_POINT