#include "serialize.h"
#include "operation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* serialize_series(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    unsigned short series = get_series(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Серия паспорта: %hu", series);
    return result;
}

char* serialize_number(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    unsigned short number = get_number(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Номер паспорта: %hu", number);
    return result;
}

char* serialize_full_id(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    char* full_id = get_full_id(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(30);
    if (result == NULL) {
        free(full_id);
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "ID: %s", full_id);
    free(full_id);
    return result;
}

char* serialize_first_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    char* name = get_first_name(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(MAX_LINE_NAME + 20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Имя: %s", name);
    return result;
}

char* serialize_middle_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    char* middlename = get_middle_name(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(MAX_LINE_NAME + 20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Отчество: %s", middlename);
    return result;
}

char* serialize_last_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    char* lastname = get_last_name(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(MAX_LINE_NAME + 20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Фамилия: %s", lastname);
    return result;
}

char* serialize_full_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    char* full_name = get_full_name(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(FULL_NAME + 20);
    if (result == NULL) {
        free(full_name);
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "ФИО: %s", full_name);
    free(full_name);
    return result;
}

char* serialize_birth_year(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    unsigned short year = get_birth_year(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Год рождения: %hu", year);
    return result;
}

char* serialize_birth_month(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    char* month = get_birth_month(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(MAX_LINE_MONTH + 20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Месяц рождения: %s", month);
    return result;
}

char* serialize_birth_date(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    unsigned short date = get_birth_date(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(20);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "День рождения: %hu", date);
    return result;
}

char* serialize_full_birth(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL || i >= arr->size) {
        if (error) *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    char* full_birth = get_full_birth(arr, i, error);
    if (*error != ARRAY_OPERATION_OK) return NULL;
    
    char* result = (char*)malloc(FULL_BIRTH + 20);
    if (result == NULL) {
        free(full_birth);
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    
    sprintf(result, "Дата рождения: %s", full_birth);
    free(full_birth);
    return result;
}

char* serialize_where_list(array* arr, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    
    array* adults = where(arr, age_verification, error);
    if (*error != ARRAY_OPERATION_OK || adults == NULL) {
        return NULL;
    }
    
    char* result = (char*)malloc(array->capacity);
    if (result == NULL) {
        free_array(adults);
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    result[0] = '\0';
    
    strcat(result, "Совершеннолетние:\n");
    
    for (unsigned int i = 0; i < adults->size; i++) {
        char* full_name = get_full_name(adults, i, error);
        if (*error == ARRAY_OPERATION_OK && full_name != NULL) {
            char line[256];
            sprintf(line, "%d. %s\n", i + 1, full_name);
            strcat(result, line);
            free(full_name);
        }
    }
    
    free_array(adults);
    return result;
}

char* serialize_map_list(array* arr, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }

    char* result = (char*)malloc(array->capacity);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    result[0] = '\0';
    
    strcat(result, "Имена в массиве:\n");
    
    for (unsigned int i = 0; i < arr->size; i++) {
        char* name = get_first_name(arr, i, error);
        if (*error == ARRAY_OPERATION_OK && name != NULL) {
            char line[256];
            sprintf(line, "%d. %s\n", i + 1, name);
            strcat(result, line);
        }
    }
    
    return result;
}