#include "testing.h"
#include "array_of_person.h"
#include "operation.h"
#include "serialize.h"
#include "typeinfo.h"
#include "array_errors.h"
#include <string.h>
#include <stdio.h>
#include "assertions.h"

TEST(test_serialize_series_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.series = 1234;
    array_add(arr, &p, NULL);
    
    char* result = serialize_series(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strcmp(result, "Серия паспорта: 1234") == 0);
    
    free(result);
    free_array(arr);
}


TEST(test_serialize_number_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.number = 5678;
    array_add(arr, &p, NULL);
    
    char* result = serialize_number(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "Номер паспорта: 5678") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_full_id_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.id.series = 1234;
    p.id.number = 5678;
    array_add(arr, &p, NULL);
    
    char* result = serialize_full_id(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "ID: 1234 5678") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_first_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.first_name, "Иван");
    array_add(arr, &p, NULL);
    
    char* result = serialize_first_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "Имя: Иван") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_middle_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.middle_name, "Иванович");
    array_add(arr, &p, NULL);
    
    char* result = serialize_middle_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "Отчество: Иванович") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_last_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.last_name, "Петров");
    array_add(arr, &p, NULL);
    
    char* result = serialize_last_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "Фамилия: Петров") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_full_name_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.first_name, "Иван");
    strcpy(p.middle_name, "Иванович");
    strcpy(p.last_name, "Петров");
    array_add(arr, &p, NULL);
    
    char* result = serialize_full_name(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "ФИО: Иван Иванович Петров") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_birth_year_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 2000;
    array_add(arr, &p, NULL);
    
    char* result = serialize_birth_year(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "Год рождения: 2000") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_birth_month_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    strcpy(p.birth.month, "Январь");
    array_add(arr, &p, NULL);
    
    char* result = serialize_birth_month(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "Месяц рождения: Январь") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_birth_date_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.date = 15;
    array_add(arr, &p, NULL);
    
    char* result = serialize_birth_date(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "День рождения: 15") == 0);
    
    free(result);
    free_array(arr);
}


TEST(test_serialize_full_birth_correct) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    p.birth.year = 2000;
    strcpy(p.birth.month, "Январь");
    p.birth.date = 15;
    array_add(arr, &p, NULL);
    
    char* result = serialize_full_birth(arr, 0, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(strcmp(result, "Дата рождения: 2000 Январь 15") == 0);
    
    free(result);
    free_array(arr);
}

TEST(test_serialize_where_list_correct) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(3, info, &error);
    
    person p1, p2, p3;
    p1.birth.year = 2000;
    p2.birth.year = 2015;
    p3.birth.year = 1995;
    strcpy(p1.first_name, "Иван");
    strcpy(p1.middle_name, "Иванович");
    strcpy(p1.last_name, "Петров");
    strcpy(p2.first_name, "Петр");
    strcpy(p2.middle_name, "Петрович");
    strcpy(p2.last_name, "Сидоров");
    strcpy(p3.first_name, "Сидор");
    strcpy(p3.middle_name, "Сидорович");
    strcpy(p3.last_name, "Иванов");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    array_add(arr, &p3, &error);
    
    char* result = serialize_where_list(arr, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strstr(result, "Совершеннолетние:") != NULL);
    assert(strstr(result, "Иван Иванович Петров") != NULL);
    assert(strstr(result, "Сидор Сидорович Иванов") != NULL);
    
    free(result);
    free_array(arr);
    free(info);
}

TEST(test_serialize_where_list_null_array) {
    array_errors error;
    
    char* result = serialize_where_list(NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_map_list_correct) {
    typeinfo* info = create_person_typeinfo();
    array_errors error;
    array* arr = create_array(2, info, &error);
    
    person p1, p2;
    strcpy(p1.first_name, "Иван");
    strcpy(p2.first_name, "Петр");
    
    array_add(arr, &p1, &error);
    array_add(arr, &p2, &error);
    
    char* result = serialize_map_list(arr, &error);
    
    assert(error == ARRAY_OPERATION_OK);
    assert(result != NULL);
    assert(strstr(result, "Имена в массиве:") != NULL);
    assert(strstr(result, "Иван") != NULL);
    assert(strstr(result, "Петр") != NULL);
    
    free(result);
    free_array(arr);
    free(info);
}

TEST(test_serialize_map_list_null_array) {
    array_errors error;
    
    char* result = serialize_map_list(NULL, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_series_null_array) {
    array_errors error;
    
    char* result = serialize_series(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_series_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_series(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_series_empty_array) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    char* result = serialize_series(arr, 0, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_number_null_array) {
    array_errors error;
    
    char* result = serialize_number(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_number_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_number(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_full_id_null_array) {
    array_errors error;
    
    char* result = serialize_full_id(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_full_id_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_full_id(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_first_name_null_array) {
    array_errors error;
    
    char* result = serialize_first_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_first_name_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_first_name(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_middle_name_null_array) {
    array_errors error;
    
    char* result = serialize_middle_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_middle_name_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_middle_name(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_last_name_null_array) {
    array_errors error;
    
    char* result = serialize_last_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_last_name_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_last_name(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_full_name_null_array) {
    array_errors error;
    
    char* result = serialize_full_name(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_full_name_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_full_name(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_birth_year_null_array) {
    array_errors error;
    
    char* result = serialize_birth_year(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_birth_year_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_birth_year(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_birth_month_null_array) {
    array_errors error;
    
    char* result = serialize_birth_month(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_birth_month_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_birth_month(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_birth_date_null_array) {
    array_errors error;
    
    char* result = serialize_birth_date(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_birth_date_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_birth_date(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}

TEST(test_serialize_full_birth_null_array) {
    array_errors error;
    
    char* result = serialize_full_birth(NULL, 0, &error);
    
    assert(error == ARRAY_NOT_DEFINED);
    assert(result == NULL);
}

TEST(test_serialize_full_birth_index_out_of_bounds) {
    array* arr = create_array(1, create_person_typeinfo(), NULL);
    array_errors error;
    
    person p;
    array_add(arr, &p, NULL);
    
    char* result = serialize_full_birth(arr, 5, &error);
    
    assert(error == INDEX_OUT_OF_BOUNDS);
    assert(result == NULL);
    
    free_array(arr);
}


TEST_ENTRY_POINT