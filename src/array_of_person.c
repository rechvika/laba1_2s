#include "array_of_person.h"

unsigned short get_series(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].id.series;
}

unsigned short get_number(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].id.number;
}

char* get_full_id (array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* full_id = (char*)malloc(FULL_ID);
    if (full_id == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_id, "%hu %hu", arr->element[i].id.series, arr->element[i].id.number);
    *error = ARRAY_OPERATION_OK;
    return full_id;
}

char* get_first_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].first_name;
}

char* get_middle_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].middle_name; 
}

char* get_last_name(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].last_name;
}

char* get_full_name (array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* full_name = (char*)malloc(FULL_NAME);
    if (full_name == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_name, "%s %s %s", arr->element[i].first_name, arr->element[i].middle_name, arr->element[i].last_name);
    *error = ARRAY_OPERATION_OK;
    return full_name;
}

unsigned short get_birth_year(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].birth.year;
}

char* get_birth_month(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].birth.month;
}

unsigned short get_birth_date(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return 0;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    *error = ARRAY_OPERATION_OK;
    return arr->element[i].birth.date;
}

char* get_full_birth (array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* full_birth = (char*)malloc(FULL_BIRTH);
    if (full_birth == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    sprintf(full_birth, "%hu %s %hu", arr->element[i].birth.year, arr->element[i].birth.month, arr->element[i].birth.date);
    *error = ARRAY_OPERATION_OK;
    return full_birth;
}

array* create_array(unsigned int capacity, typeinfo* type_info, array_errors* error){
    if (type_info == NULL) {
        *error = OPERATION_NOT_DEFINED;
        return NULL;
    }
    array* array_new = (array*)malloc(sizeof(array));
    if (array_new == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    array_new->element = (person*)malloc(type_info->size * capacity);
    if (array_new->element == NULL && capacity > 0) {
        free(array_new);
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }

    array_new->capacity = capacity;
    array_new->size = 0;
    array_new->typeinfo = type_info;

    *error = ARRAY_OPERATION_OK;
    return array_new;
}

void array_add(array* arr, person* p, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return;
    }
    if (p == NULL) {
        *error = PERSON_NOT_DEFINED;
        return;
    }

    if (arr->size >= arr->capacity){
        unsigned int new_capacity = (arr->capacity == 0) ? 1 : arr->capacity * 2;
        person* new_element = (person*)realloc(arr->element, arr->typeinfo->size * new_capacity);
        if (new_element == NULL) {
            *error = MEMORY_ALLOCATION_FAILED;
            return;
        }
        arr->element = new_element;
        arr->capacity = new_capacity;
    }

    memcpy((char*)arr->element + (arr->size * arr->typeinfo->size), p, arr->typeinfo->size);
    arr->size++;
    *error = ARRAY_OPERATION_OK;
}

void free_array(array* arr){
    if (arr != NULL) {
        free(arr->element);
        free(arr);
    }
}

char* map_function(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    char* result = (char*)malloc(MAP_CONST);
    if (result == NULL) {
        *error = MEMORY_ALLOCATION_FAILED;
        return NULL;
    }
    sprintf(result, "mapped_%s", arr->element[i].first_name);
    *error = ARRAY_OPERATION_OK;
    return result;
}


char* get_teacher_subject(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    
    *error = ARRAY_OPERATION_OK;
    return ((teacher*)&arr->element[i])->data.subject;
}

char* get_student_direction(array* arr, unsigned int i, array_errors* error){
    if (arr == NULL) {
        *error = ARRAY_NOT_DEFINED;
        return NULL;
    }
    if (i >= arr->size) {
        *error = INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    
    *error = ARRAY_OPERATION_OK;
    return ((student*)&arr->element[i])->data.direction;
}
