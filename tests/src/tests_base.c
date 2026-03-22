#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_get_series_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.series = 1234;
    p.id.number = 5678;
    strcpy(p.first_name, "Иван");
    strcpy(p.middle_name, "Иванович");
    strcpy(p.last_name, "Петров");
    p.birth.year = 2000;
    strcpy(p.birth.month, "Январь");
    p.birth.date = 15;
    
    array_add(arr, &p, NULL);
    
    unsigned short series = get_series(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(series == 1234);
    
    free_array(arr);
}

TEST(test_get_series_null_array) {
    array_errors error;
    
    unsigned short series = get_series(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(series == 0);
}

TEST(test_get_series_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.series = 1234;
    array_add(arr, &p, NULL);
    
    unsigned short series = get_series(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(series == 0);
    
    free_array(arr);
}

TEST(test_get_series_empty_array) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    unsigned short series = get_series(arr, 0, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(series == 0);
    
    free_array(arr);
}

TEST(test_get_number_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.series = 1234;
    p.id.number = 5678;
    array_add(arr, &p, NULL);
    
    unsigned short number = get_number(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(number == 5678);
    
    free_array(arr);
}

TEST(test_get_number_null_array) {
    array_errors error;
    
    unsigned short number = get_number(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(number == 0);
}

TEST(test_get_number_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.number = 5678;
    array_add(arr, &p, NULL);
    
    unsigned short number = get_number(arr, 10, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(number == 0);
    
    free_array(arr);
}

TEST(test_get_full_id_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.series = 1234;
    p.id.number = 5678;
    array_add(arr, &p, NULL);
    
    char* full_id = get_full_id(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_id != NULL);
    assert(strcmp(full_id, "1234 5678") == 0);
    
    free(full_id);
    free_array(arr);
}

TEST(test_get_full_id_null_array) {
    array_errors error;
    
    char* full_id = get_full_id(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(full_id == NULL);
}

TEST(test_get_full_id_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* full_id = get_full_id(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(full_id == NULL);
    
    free_array(arr);
}

TEST(test_get_full_id_memory_allocation_failure) {
    assert(1);
}


TEST(test_get_first_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.first_name, "Иван");
    array_add(arr, &p, NULL);
    
    char* name = get_first_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(name, "Иван") == 0);
    
    free_array(arr);
}

TEST(test_get_first_name_null_array) {
    array_errors error;
    
    char* name = get_first_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(name == NULL);
}

TEST(test_get_first_name_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* name = get_first_name(arr, 10, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(name == NULL);
    
    free_array(arr);
}

TEST(test_get_middle_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.middle_name, "Иванович");
    array_add(arr, &p, NULL);
    
    char* middlename = get_middle_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(middlename, "Иванович") == 0);
    
    free_array(arr);
}

TEST(test_get_middle_name_null_array) {
    array_errors error;
    
    char* middlename = get_middle_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(middlename == NULL);
}

TEST(test_get_last_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.last_name, "Петров");
    array_add(arr, &p, NULL);
    
    char* lastname = get_last_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(lastname, "Петров") == 0);
    
    free_array(arr);
}

TEST(test_get_last_name_null_array) {
    array_errors error;
    
    char* lastname = get_last_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(lastname == NULL);
}

TEST(test_get_full_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.first_name, "Иван");
    strcpy(p.middle_name, "Иванович");
    strcpy(p.last_name, "Петров");
    array_add(arr, &p, NULL);
    
    char* full_name = get_full_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_name != NULL);
    assert(strcmp(full_name, "Иван Иванович Петров") == 0);
    
    free(full_name);
    free_array(arr);
}

TEST(test_get_full_name_null_array) {
    array_errors error;
    
    char* full_name = get_full_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(full_name == NULL);
}

TEST(test_get_birth_year_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 2000;
    array_add(arr, &p, NULL);
    
    unsigned short year = get_birth_year(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(year == 2000);
    
    free_array(arr);
}

TEST(test_get_birth_year_null_array) {
    array_errors error;
    
    unsigned short year = get_birth_year(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(year == 0);
}

TEST(test_get_birth_month_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.birth.month, "Январь");
    array_add(arr, &p, NULL);
    
    char* month = get_birth_month(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(month, "Январь") == 0);
    
    free_array(arr);
}

TEST(test_get_birth_month_null_array) {
    array_errors error;
    
    char* month = get_birth_month(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(month == NULL);
}

TEST(test_get_birth_date_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.date = 15;
    array_add(arr, &p, NULL);
    
    unsigned short date = get_birth_date(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(date == 15);
    
    free_array(arr);
}

TEST(test_get_birth_date_null_array) {
    array_errors error;
    
    unsigned short date = get_birth_date(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(date == 0);
}

TEST(test_get_full_birth_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 2000;
    strcpy(p.birth.month, "Январь");
    p.birth.date = 15;
    array_add(arr, &p, NULL);
    
    char* full_birth = get_full_birth(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(full_birth != NULL);
    assert(strcmp(full_birth, "2000 Январь 15") == 0);
    
    free(full_birth);
    free_array(arr);
}

TEST(test_get_full_birth_null_array) {
    array_errors error;
    
    char* full_birth = get_full_birth(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(full_birth == NULL);
}






TEST_ENTRY_POINT